#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Orb.h"
#include "Unit.h"
#include <algorithm>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;
using namespace microwars;

#define ORB_COUNT 4
#define ORB_RADIUS 30
#define UNIT_RADIUS 4
#define NULL_VECTOR Vector2f(0,0)
#define PLAYER_COLOUR 'Y'

vector <Orb> ORB_VECTOR;
char ORB_COLOUR[ORB_COUNT] = {'Y', 'G', 'B', 'R'};
float ORB_COORDINATES[ORB_COUNT][2] = {{10,200}, {178,654}, {250,124}, {560,633}};
int ORB_INITIAL_UNITS[ORB_COUNT] = {50, 20, 30, 40};
RenderWindow window(VideoMode(1080, 720), "Micro Wars");

void main_menu()
{
	window.display();
	
	Font font_title,font_buttons;
	font_title.loadFromFile("../assets/fonts/title.ttf");
	Text menu_title("MicroWars",font_title,100);
	Text menu_play;
	Text menu_options;
	Text menu_quit;
	
	menu_title.setColor(sf::Color::Red);
	menu_title.setPosition(Vector2f(300,50));
	
	Music background;
	background.openFromFile("../assets/sounds/temporary.ogg");
	background.play();
	while(window.isOpen())
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
				default:
					break;
			}
		}
		if(event.MouseButtonPressed && event.mouseButton.button == Mouse::Button::Left)
		{
			break;
		}
		window.draw(menu_title);
	}
}


void initialise()
{
	window.display();
	
	for(int i = 0; i<ORB_COUNT; i++)
	{
		ORB_VECTOR.push_back(Orb(ORB_COORDINATES[i][0],ORB_COORDINATES[i][1],ORB_RADIUS,ORB_COLOUR[i],i,1,100,100));
		for(int j = 0; j<ORB_INITIAL_UNITS[i]; j++)
		{
			ORB_VECTOR[i].produce_unit();
		}
	}
}

void update()
{
	Texture texture_yellow,texture_red,texture_green,texture_blue,texture_grey;
	texture_yellow.loadFromFile("../assets/images/yellow_orb.png");
	texture_yellow.setSmooth(true);
	const sf::Texture *p_yellow_Texture = &texture_yellow;

	texture_red.loadFromFile("../assets/images/red_orb.png");
	texture_red.setSmooth(true);
	const sf::Texture *p_red_Texture = &texture_red;
	
	texture_green.loadFromFile("../assets/images/green_orb.png");
	texture_green.setSmooth(true);
	const sf::Texture *p_green_Texture = &texture_green;
	
	texture_blue.loadFromFile("../assets/images/blue_orb.png");
	texture_blue.setSmooth(true);
	const sf::Texture *p_blue_Texture = &texture_blue;

	texture_grey.loadFromFile("../assets/images/grey_orb.png");
	texture_grey.setSmooth(true);
	const sf::Texture *p_grey_Texture = &texture_grey;

	Vector2f starting_position;
	Vector2f final_position;
	Vector2f span;
	
	window.display();
	
	RectangleShape *selection_box = new RectangleShape;
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
						span.x = event.mouseButton.x - starting_position.x;
						span.y = event.mouseButton.y - starting_position.y;
						
						if(selection_box != nullptr)
						{
							delete selection_box;
						}
						selection_box = new RectangleShape(span);
						selection_box->setFillColor(Color::Black);
						selection_box->setOutlineColor(Color::Cyan);
						selection_box->setOutlineThickness(1);
						selection_box->setPosition(starting_position.x, starting_position.y);
					}
					break;
					
				default:
					break;
			}
        }
		if(selection_box != nullptr)
		{
			window.draw(*selection_box);
		}
		for(int i = 0; i<ORB_COUNT; i++)
		{
			Orb_Shape.setPosition(ORB_COORDINATES[i][0],ORB_COORDINATES[i][1]);
			
			if(ORB_VECTOR[i].return_orb_colour() == 'R')
			{
				Orb_Shape.setTexture(NULL);
				Orb_Shape.setTexture(p_red_Texture,true);
			}
			if(ORB_VECTOR[i].return_orb_colour() == 'B')
			{
				Orb_Shape.setTexture(NULL);
				Orb_Shape.setTexture(p_blue_Texture,true);
			}
			if(ORB_VECTOR[i].return_orb_colour() == 'G')
			{
				Orb_Shape.setTexture(NULL);
				Orb_Shape.setTexture(p_green_Texture,true);
			}
			if(ORB_VECTOR[i].return_orb_colour() == 'Y')
			{
				Orb_Shape.setTexture(NULL);
				Orb_Shape.setTexture(p_yellow_Texture,true);
			}
			if(ORB_VECTOR[i].return_orb_colour() == 'X')
			{
				Orb_Shape.setTexture(NULL);
				Orb_Shape.setTexture(p_grey_Texture,true);
			}
			window.draw(Orb_Shape);
		}
		for(int i = 0; i<ORB_COUNT; i++)
		{
			if(ORB_VECTOR[i].return_orb_colour() == PLAYER_COLOUR)
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
					delete selection_box;
					selection_box = nullptr;
				}
			}
		}
		for(int i = 0; i<ORB_COUNT; i++)
		{
			if(ORB_VECTOR[i].return_orb_colour() == PLAYER_COLOUR)
			{
				for(int j = 0; j<ORB_VECTOR[i].orb_units.size(); j++)
				{
					if(ORB_VECTOR[i].orb_units[j].return_selection_status())
					{
						if(ORB_VECTOR[i].orb_units[j].move())
						{
							for(int k = 0; k<ORB_COUNT; k++)
							{
								if(ORB_VECTOR[k].check_unit_vicinity(ORB_VECTOR[i].orb_units[j].return_unit_pos('x'), ORB_VECTOR[i].orb_units[j].return_unit_pos('y')))
								{
									ORB_VECTOR[k].change_health(ORB_VECTOR[i].orb_units[j].return_unit_colour());
									cout<<k<<"\t"<<ORB_VECTOR[k].return_health()<<"\t"<<ORB_VECTOR[k].return_orb_colour()<<"\n";
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i<ORB_COUNT; i++)
		{
			CircleShape Unit_Shape(UNIT_RADIUS);
			for(int j = 0; j<ORB_VECTOR[i].orb_units.size(); j++)
			{
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
	main_menu();
	initialise();
	update();
}