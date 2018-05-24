#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Orb.h"
#include "Unit.h"

using namespace sf;
using namespace std;
using namespace microwars;

#define ORB_COUNT 5
#define ORB_RADIUS 30
#define UNIT_RADIUS 4

#define PLAYER_COLOUR 'Y'

vector <Orb> ORB_VECTOR;

char ORB_COLOUR[ORB_COUNT] = {'Y', 'G', 'B', 'R','Y'};
float ORB_COORDINATES[ORB_COUNT][2] = {{50,200}, {178,654}, {250,124}, {560,633},{600,240}};
int ORB_INITIAL_UNITS[ORB_COUNT] = {100, 20, 0, 0,300};
int ORB_MAX_POWER[ORB_COUNT] = {3,2,3,3,2};

RenderWindow window(VideoMode(1080, 720), "Micro Wars");

bool start_play;

void main_menu()
{
	window.display();

	Font font_title,font_buttons;
	font_title.loadFromFile("../assets/fonts/title.ttf");
	
	Text menu_title("MicroWars",font_title,100);
	menu_title.setColor(sf::Color::Red);
	Vector2f position_menu(300,50);
	menu_title.setPosition(position_menu);
	
	Text menu_play("Play",font_title,50);
	menu_play.setColor(sf::Color::Red);
	Vector2f position_play(450,200);
	menu_play.setPosition(position_play);
	
	Text menu_options("Options",font_title,50);
	menu_options.setColor(sf::Color::Red);
	Vector2f position_options(450,250);
	menu_options.setPosition(position_options);
	
	Text menu_quit("Quit",font_title,50);
	menu_quit.setColor(sf::Color::Red);
	Vector2f position_quit(450,300);
	menu_quit.setPosition(position_quit);
	
	RectangleShape menu_box;
	
	Texture background_image;
	background_image.loadFromFile("../assets/images/main_menu.png");
	
	Sprite background;
	background.setTexture(background_image);
	background.setScale(0.5625,0.6667);

	Music background_music;
	background_music.openFromFile("../assets/sounds/temporary.ogg");
	background_music.play();
	
	while(window.isOpen())
	{
		window.display();
		window.clear();
		window.draw(background);
		
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

			if( Mouse::getPosition(window).x >= position_play.x && Mouse::getPosition(window).x <= (position_play.x+100) && Mouse::getPosition(window).y >=position_play.y && Mouse::getPosition(window).y <= (position_play.y+50) )
			{
				menu_play.setColor(Color::White);
				
				if( event.mouseButton.button == Mouse::Left )
				{
					start_play=true;
				}
			}
			else
			{
				menu_play.setColor(Color::Red);
			}

			if( Mouse::getPosition(window).x >= position_options.x && Mouse::getPosition(window).x <= (position_options.x+100) && Mouse::getPosition(window).y >=position_options.y && Mouse::getPosition(window).y <= (position_options.y+50) )
			{
				menu_options.setColor(Color::White);
				
				if( event.mouseButton.button == Mouse::Left )
				{
					start_play=true;
				}
			}
			else
			{
				menu_options.setColor(Color::Red);
			}

			if( Mouse::getPosition(window).x >= position_quit.x && Mouse::getPosition(window).x <= (position_quit.x+100) && Mouse::getPosition(window).y >=position_quit.y && Mouse::getPosition(window).y <= (position_quit.y+50) )
			{
				menu_quit.setColor(Color::White);
				
				if( event.mouseButton.button == Mouse::Left )
				{
					window.close();
				}
			}
			else
			{
				menu_quit.setColor(Color::Red);
			}
		}
		
		if(start_play)
		{
			break;
		}

		window.draw(menu_title);
		window.draw(menu_play);
		window.draw(menu_options);
		window.draw(menu_quit);
	}
}


void initialise()
{
	window.display();
	
	for(int i = 0; i<ORB_COUNT; i++)
	{
		ORB_VECTOR.push_back(Orb(ORB_COORDINATES[i][0],ORB_COORDINATES[i][1],ORB_RADIUS,ORB_COLOUR[i],i,1,ORB_MAX_POWER[i],100));
		for(int j = 0; j<ORB_INITIAL_UNITS[i]; j++)
		{
			ORB_VECTOR[i].produce_unit();
		}
	}
}

void draw_game()
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
	
	Sprite background;
	
	Texture background_image;
	background_image.loadFromFile("../assets/images/play_background.png");
	
	background.setTexture(background_image);
	background.setScale(0.84375,0.9);

	CircleShape Orb_Shape(ORB_RADIUS);
	
	CircleShape Power_Circle_One(2*ORB_RADIUS);
	Power_Circle_One.setOutlineThickness(1);
	
	CircleShape Power_Circle_Two(3*ORB_RADIUS);
	Power_Circle_Two.setOutlineThickness(1);

	Vector2f starting_position;
	Vector2f final_position;
	Vector2f span;
	
	RectangleShape *selection_box = new RectangleShape;
	
	window.display();
	while(window.isOpen())
	{
		Orb_Shape.setOrigin(ORB_RADIUS/2,ORB_RADIUS/2);
		Power_Circle_One.setOrigin(2*ORB_RADIUS/2,2*ORB_RADIUS/2);
		Power_Circle_Two.setOrigin(3*ORB_RADIUS/2,3*ORB_RADIUS/2);

		window.display();
		window.clear();
		window.draw(background);
		
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
						if(start_play)
						{
							start_play=false;
						}
						else
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
							selection_box->setFillColor(Color::Transparent);
							selection_box->setOutlineColor(Color::Cyan);
							selection_box->setOutlineThickness(1);
							selection_box->setPosition(starting_position.x, starting_position.y);
						}
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
			if( ORB_VECTOR[i].return_orb_colour() == PLAYER_COLOUR)
			{
				if (event.mouseButton.button == Mouse::Right && Mouse::isButtonPressed(Mouse::Button::Right))
				{
					Vector2f destination_point;
					
					destination_point.x	= event.mouseButton.x;
					destination_point.y = event.mouseButton.y;
					
					for(int j = 0; j<ORB_VECTOR[i].orb_units.size(); j++)
					{
						if(ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'Y')
						{
							if(ORB_VECTOR[i].orb_units[j].return_unit_pos('x') >=  min(final_position.x,starting_position.x))
							{
								if(ORB_VECTOR[i].orb_units[j].return_unit_pos('x') <= max(final_position.x,starting_position.x)) 
								{
									if(ORB_VECTOR[i].orb_units[j].return_unit_pos('y') >= min(final_position.y,starting_position.y))
									{
										if(ORB_VECTOR[i].orb_units[j].return_unit_pos('y') <= max(final_position.y,starting_position.y))
										{
											if( destination_point.x!=0 && destination_point.y!=0 )
											{
												ORB_VECTOR[i].orb_units[j].set_unit_destination(destination_point.x, destination_point.y);
											}
										}
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
				Orb_Shape.setPosition(ORB_COORDINATES[i][0]-ORB_RADIUS/2,ORB_COORDINATES[i][1]-ORB_RADIUS/2);
				Power_Circle_One.setPosition(ORB_COORDINATES[i][0]-2*ORB_RADIUS/2,ORB_COORDINATES[i][1]-2*ORB_RADIUS/2);
				Power_Circle_One.setOutlineColor(Color::White);
				Power_Circle_Two.setPosition(ORB_COORDINATES[i][0]-3*ORB_RADIUS/2,ORB_COORDINATES[i][1]-3*ORB_RADIUS/2);
				Power_Circle_Two.setOutlineColor(Color::White);

				if(ORB_VECTOR[i].return_orb_colour() == 'R')
				{
					Orb_Shape.setTexture(NULL);
					Orb_Shape.setTexture(p_red_Texture,true);
					
					Color red_transparent(255,0,0,30);
					Power_Circle_One.setFillColor(red_transparent);
					Power_Circle_Two.setFillColor(red_transparent);

					if(ORB_VECTOR[i].return_power()>=2)
						Power_Circle_One.setOutlineColor(Color::Red);
					if(ORB_VECTOR[i].return_power()==3)
						Power_Circle_Two.setOutlineColor(Color::Red);
				}
				
				if(ORB_VECTOR[i].return_orb_colour() == 'B')
				{
					Orb_Shape.setTexture(NULL);
					Orb_Shape.setTexture(p_blue_Texture,true);
					
					Color blue_transparent(0,0,255,30);
					Power_Circle_One.setFillColor(blue_transparent);
					Power_Circle_Two.setFillColor(blue_transparent);

					if(ORB_VECTOR[i].return_power()>=2)
						Power_Circle_One.setOutlineColor(Color::Blue);
					if(ORB_VECTOR[i].return_power()==3)
						Power_Circle_Two.setOutlineColor(Color::Blue);
				}
				
				if(ORB_VECTOR[i].return_orb_colour() == 'G')
				{
					Orb_Shape.setTexture(NULL);
					Orb_Shape.setTexture(p_green_Texture,true);
					
					Color green_transparent(0,255,0,30);
					Power_Circle_One.setFillColor(green_transparent);
					Power_Circle_Two.setFillColor(green_transparent);

					if(ORB_VECTOR[i].return_power()>=2)
						Power_Circle_One.setOutlineColor(Color::Green);
					if(ORB_VECTOR[i].return_power()==3)
						Power_Circle_Two.setOutlineColor(Color::Green);
				}
				
				if(ORB_VECTOR[i].return_orb_colour() == 'Y')
				{
					Orb_Shape.setTexture(NULL);
					Orb_Shape.setTexture(p_yellow_Texture,true);
					
					Color yellow_transparent(255,255,0,30);
					Power_Circle_One.setFillColor(yellow_transparent);
					Power_Circle_Two.setFillColor(yellow_transparent);

					if(ORB_VECTOR[i].return_power()>=2)
						Power_Circle_One.setOutlineColor(Color::Yellow);
					if(ORB_VECTOR[i].return_power()==3)
						Power_Circle_Two.setOutlineColor(Color::Yellow);
				}
				
				if(ORB_VECTOR[i].return_orb_colour() == 'X')
				{
					Orb_Shape.setTexture(NULL);
					Orb_Shape.setTexture(p_grey_Texture,true);
					
					Color grey_transparent(128,128,128,30);
					Power_Circle_One.setFillColor(grey_transparent);
					Power_Circle_Two.setFillColor(grey_transparent);

					if(ORB_VECTOR[i].return_power()>=2)
						Power_Circle_One.setOutlineColor(Color::White);
					if(ORB_VECTOR[i].return_power()==3)
						Power_Circle_One.setOutlineColor(Color::White);
				}
				
				if( ORB_VECTOR[i].return_max_power()>2)
					window.draw(Power_Circle_Two);
				if( ORB_VECTOR[i].return_max_power()>1)
					window.draw(Power_Circle_One);
				window.draw(Orb_Shape);
			}

		for (int i = 0; i<ORB_COUNT; i++)
		{
			CircleShape Unit_Shape(UNIT_RADIUS);

			for(int j = 0; j<ORB_VECTOR[i].orb_units.size(); j++)
			{
				Unit_Shape.setPosition(ORB_VECTOR[i].orb_units[j].return_unit_pos('x'),ORB_VECTOR[i].orb_units[j].return_unit_pos('y'));
				
				if(ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'R')
				{
					Unit_Shape.setFillColor(Color::Red);
				}
				
				if(ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'B')
				{
					Unit_Shape.setFillColor(Color::Blue);
				}
				
				if(ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'G')
				{
					Unit_Shape.setFillColor(Color::Green);
				}
				
				if(ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'Y')
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

void update_game_logic()
{
	Clock timer;
	Time wait_time = seconds(10000000);

	while (true)
	{
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
									if(ORB_VECTOR[k].return_orb_colour() != ORB_VECTOR[i].orb_units[j].return_unit_colour() || (ORB_VECTOR[k].return_orb_colour() == ORB_VECTOR[i].orb_units[j].return_unit_colour() && ORB_VECTOR[k].return_health()<(100*ORB_VECTOR[k].return_max_power())))
									{
										ORB_VECTOR[i].orb_units[j].~Unit();
										ORB_VECTOR[i].orb_units.erase(ORB_VECTOR[i].orb_units.begin()+j);
									}
								}
							}
						}
					}
				}
			}
		}

		if( timer.getElapsedTime().asSeconds()>= wait_time.asSeconds())
		{
			timer.restart();
			for (int i=0;i<ORB_COUNT;i++)
			{
				ORB_VECTOR[i].produce_unit();
			}
		}
	}
}

void play()
{
	Image game_icon;
	game_icon.loadFromFile("../assets/images/game_icon.png");
	window.setIcon(game_icon.getSize().x,game_icon.getSize().y,game_icon.getPixelsPtr());

	Thread thread_draw(&draw_game);
	Thread thread_logic(&update_game_logic);
	
	main_menu();
	initialise();
	
	thread_logic.launch();
	thread_draw.launch();

}
