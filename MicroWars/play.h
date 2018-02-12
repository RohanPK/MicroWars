#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Orb.h"
#include "Unit.h"
#include <algorithm>

using namespace sf;
using namespace std;
using namespace microwars;

#define ORB_COUNT 4
#define ORB_RADIUS 30
#define UNIT_RADIUS 4
#define NULL_VECTOR Vector2f(0,0)

vector <Orb> ORB_VECTOR;
char ORB_COLOUR[ORB_COUNT] = {'B', 'R', 'G', 'Y'};
float ORB_COORDINATES[ORB_COUNT][2] = {{10,200}, {178,654}, {250,124}, {560,633}};
int ORB_INITIAL_UNITS[ORB_COUNT] = {10, 20, 30, 40};
RenderWindow window(VideoMode(1080, 720), "Micro Wars");

void initialise()
{
	window.display();
	
	for(int i = 0; i<ORB_COUNT; i++)
	{
		ORB_VECTOR.push_back(Orb(ORB_COORDINATES[i][0],ORB_COORDINATES[i][1],ORB_RADIUS,ORB_COLOUR[i],i,1,100));
		for(int j = 0; j<ORB_INITIAL_UNITS[i]; j++)
		{
			ORB_VECTOR[i].produce_unit();
		}
	}
}

void update()
{
	Vector2f starting_position;
	Vector2f final_position;
	Vector2f current_position;
	
	window.display();
	
	RectangleShape selection_box;
	CircleShape Orb_Shape(ORB_RADIUS);
	
	while (window.isOpen())
    {
		window.display();
		window.clear();
        Event event;
		
        while (window.pollEvent(event))
        {
			switch(event.type)
			{
				case Event::Closed:
					window.close();
					break;
				
				case Event::MouseButtonPressed:
					if(event.mouseButton.button == Mouse::Left)
					{
						starting_position.x = event.mouseButton.x;
						starting_position.y = event.mouseButton.y;
					}
					break;
					
				case Event::MouseButtonReleased:
					if(event.mouseButton.button == Mouse::Left)
					{
						final_position.x = event.mouseButton.x;
						final_position.y = event.mouseButton.y;
						current_position.x = event.mouseButton.x - starting_position.x;
						current_position.y = event.mouseButton.y - starting_position.y;
						
						selection_box.setFillColor(Color::Black);
						selection_box.setOutlineColor(Color::Cyan);
						selection_box.setOutlineThickness(1);
						selection_box.setSize(current_position);
						selection_box.setPosition(starting_position.x, starting_position.y);
					}
					break;
					
				default:
					break;
			}
        }
		window.draw(selection_box);
		for(int i = 0; i<ORB_COUNT; i++)
		{
			Orb_Shape.setPosition(ORB_COORDINATES[i][0],ORB_COORDINATES[i][1]);
			
			if(ORB_COLOUR[i] == 'R')
			{
				Orb_Shape.setFillColor(Color::Red);
			}
			if(ORB_COLOUR[i] == 'B')
			{
				Orb_Shape.setFillColor(Color::Blue);
			}
			if(ORB_COLOUR[i]== 'G')
			{
				Orb_Shape.setFillColor(Color::Green);
			}
			if(ORB_COLOUR[i]== 'Y')
			{
				Orb_Shape.setFillColor(Color::Yellow);
			}
			if(ORB_COLOUR[i]== 'X')
			{
				Orb_Shape.setFillColor(Color::White);
			}
			window.draw(Orb_Shape);
		}
		for(int i = 0; i<ORB_COUNT; i++)
		{
			if(ORB_VECTOR[i].return_orb_colour() == 'Y')
			{
				if (event.mouseButton.button == Mouse::Right)
				{
					Vector2f destination_point;
					destination_point.x	= event.mouseButton.x;
					destination_point.y = event.mouseButton.y;
					for(int j = 0; j<ORB_VECTOR[i].orb_units.size(); j++)
					{
						if(ORB_VECTOR[i].orb_units[j].return_unit_pos('x') >=  min(final_position.x,starting_position.x))
						{
							if(ORB_VECTOR[i].orb_units[j].return_unit_pos('x') <= max(final_position.x,starting_position.x)) 
							{
								if(ORB_VECTOR[i].orb_units[j].return_unit_pos('y') >= min(final_position.y,starting_position.y))
								{
									if(ORB_VECTOR[i].orb_units[j].return_unit_pos('y') <= max(final_position.y,starting_position.y))
									{
										ORB_VECTOR[i].orb_units[j].set_unit_destination(destination_point.x, destination_point.y);
									}
								}
							}
						}
					}
					selection_box.setSize(NULL_VECTOR);
					final_position = NULL_VECTOR;
					starting_position = NULL_VECTOR;
				}
			}
		}
		for(int i = 0; i<ORB_COUNT; i++)
		{
			if(ORB_VECTOR[i].return_orb_colour() == 'Y')
			{
				for(int j=0; j<ORB_VECTOR[i].orb_units.size(); j++)
				{
					if(ORB_VECTOR[i].orb_units[j].return_selection_status())
					{
						ORB_VECTOR[i].orb_units[j].move();
					}
				}
			}
		}
		for (int i = 0; i<ORB_COUNT; i++)
		{
			for(int j = 0; j<ORB_VECTOR[i].orb_units.size(); j++)
			{
				CircleShape Unit_Shape(UNIT_RADIUS);
				Unit_Shape.setPosition(ORB_VECTOR[i].orb_units[j].return_unit_pos('x'),ORB_VECTOR[i].orb_units[j].return_unit_pos('y'));
				if(ORB_VECTOR[i].return_orb_colour() == 'R')
				{
					Unit_Shape.setFillColor(Color::Red);
				}
				if(ORB_VECTOR[i].return_orb_colour() == 'B')
				{
					Unit_Shape.setFillColor(Color::Blue);
				}
				if(ORB_VECTOR[i].return_orb_colour() == 'G')
				{
					Unit_Shape.setFillColor(Color::Green);
				}
				if(ORB_VECTOR[i].return_orb_colour() == 'Y')
				{
					Unit_Shape.setFillColor(Color::Yellow);
					if(ORB_VECTOR[i].orb_units[j].return_selection_status())
					{
						Unit_Shape.setOutlineColor(Color::White);
						Unit_Shape.setOutlineThickness(1);
					}
				}
				window.draw(Unit_Shape);
			}
		}
	}
}

void play()
{
	initialise();
	update();
}