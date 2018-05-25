#include "play.h"

void draw_game(GameEssentials &G)
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

	vector < vector < CircleShape> > Orb_Shape_Vector;
	CircleShape Orb_Shape(G.ORB_RADIUS);
	CircleShape Power_Circle_One(2*G.ORB_RADIUS);
	Power_Circle_One.setOutlineThickness(1);
	CircleShape Power_Circle_Two(3*G.ORB_RADIUS);
	Power_Circle_Two.setOutlineThickness(1);
	Orb_Shape.setOrigin(G.ORB_RADIUS/2,G.ORB_RADIUS/2);
	Power_Circle_One.setOrigin(2*G.ORB_RADIUS/2,2*G.ORB_RADIUS/2);
	Power_Circle_Two.setOrigin(3*G.ORB_RADIUS/2,3*G.ORB_RADIUS/2);

	vector < RectangleShape > Health_Bar_Vector;
	RectangleShape health_bar;
	health_bar.setSize(Vector2f(100, 10));
	health_bar.setOutlineColor(Color(255, 255, 255));
	health_bar.setOutlineThickness(1);
	
	for(int i=0; i<5; i++)
	{
		vector <CircleShape> Orb_Shape_temp;
		Orb_Shape.setTexture(NULL);
		switch (i) 
		{
			case 0 :
			{
				Orb_Shape.setTexture(p_blue_Texture,true);
				Color blue_transparent(0,0,255,30);
				Power_Circle_One.setFillColor(blue_transparent);
				Power_Circle_Two.setFillColor(blue_transparent);
				health_bar.setFillColor(Color(0,0,255));
				break;
			}
			case 1 :
			{
				Orb_Shape.setTexture(p_green_Texture,true);
				Color green_transparent(0,255,0,30);
				Power_Circle_One.setFillColor(green_transparent);
				Power_Circle_Two.setFillColor(green_transparent);
				health_bar.setFillColor(Color(0,255,0));
				break;
			}
			
			case 2 :
			{
				Orb_Shape.setTexture(p_red_Texture,true);
				Color red_transparent(255,0,0,30);
				Power_Circle_One.setFillColor(red_transparent);
				Power_Circle_Two.setFillColor(red_transparent);
				health_bar.setFillColor(Color(255,0,0));
				break;
			}
			
			case 3 :
			{	
				Orb_Shape.setTexture(p_yellow_Texture,true);
				Color yellow_transparent(255,255,0,30);
				Power_Circle_One.setFillColor(yellow_transparent);
				Power_Circle_Two.setFillColor(yellow_transparent);
				health_bar.setFillColor(Color(255,255,0));
				break;
			}
			
			case 4:
			{
				Orb_Shape.setTexture(p_grey_Texture,true);
				Color grey_transparent(128,128,128,30);
				Power_Circle_One.setFillColor(grey_transparent);
				Power_Circle_Two.setFillColor(grey_transparent);
				health_bar.setFillColor(Color(128,128,128));
				break;
			}
		}

		Orb_Shape_temp.push_back(Orb_Shape);
		Orb_Shape_temp.push_back(Power_Circle_One);
		Orb_Shape_temp.push_back(Power_Circle_Two);
		Orb_Shape_Vector.push_back(Orb_Shape_temp);
		Health_Bar_Vector.push_back(health_bar);
	}
	Vector2f starting_position;
	Vector2f final_position;
	Vector2f span;
	
	RectangleShape *selection_box = new RectangleShape;
	
	G.window->display();
	while(G.window->isOpen())
	{

		G.window->display();
		G.window->clear();
		G.window->draw(background);
		
		Event event;

		while (G.window->pollEvent(event))
		{

			switch(event.type)
			{
				case Event::Closed:
					G.window->close();
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
						if(G.start_play)
						{
							G.start_play=false;
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
			G.window->draw(*selection_box);
		}

		for(int i = 0; i<G.ORB_COUNT; i++)
		{
			if( G.ORB_VECTOR[i].return_orb_colour() == G.PLAYER_COLOUR)
			{
				if (event.mouseButton.button == Mouse::Right && Mouse::isButtonPressed(Mouse::Button::Right))
				{
					Vector2f destination_point;
					
					destination_point.x	= event.mouseButton.x;
					destination_point.y = event.mouseButton.y;
					
					for(int j = 0; j<G.ORB_VECTOR[i].orb_units.size(); j++)
					{
						if(G.ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'Y')
						{
							if(G.ORB_VECTOR[i].orb_units[j].return_unit_pos('x') >=  min(final_position.x,starting_position.x))
							{
								if(G.ORB_VECTOR[i].orb_units[j].return_unit_pos('x') <= max(final_position.x,starting_position.x)) 
								{
									if(G.ORB_VECTOR[i].orb_units[j].return_unit_pos('y') >= min(final_position.y,starting_position.y))
									{
										if(G.ORB_VECTOR[i].orb_units[j].return_unit_pos('y') <= max(final_position.y,starting_position.y))
										{
											if( destination_point.x!=0 && destination_point.y!=0 )
											{
												G.ORB_VECTOR[i].orb_units[j].set_unit_destination(destination_point.x, destination_point.y);
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
		for(int i = 0; i<G.ORB_COUNT; i++)
			{
				int colour_index;
				RectangleShape line(sf::Vector2f(2,10));

				if(G.ORB_VECTOR[i].return_orb_colour() == 'R')
				{
					colour_index=2;
					if(G.ORB_VECTOR[i].return_power()>=2)
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Red);
					if(G.ORB_VECTOR[i].return_power()==3)
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Red);
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'B')
				{
					colour_index=0;
					if(G.ORB_VECTOR[i].return_power()>=2)
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Blue);
					if(G.ORB_VECTOR[i].return_power()==3)
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Blue);
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'G')
				{
					colour_index=1;
					if(G.ORB_VECTOR[i].return_power()>=2)
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Green);
					if(G.ORB_VECTOR[i].return_power()==3)
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Green);
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'Y')
				{
					colour_index=3;
					if(G.ORB_VECTOR[i].return_power()>=2)
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Yellow);
					if(G.ORB_VECTOR[i].return_power()==3)
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Yellow);
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'X')
				{
					colour_index=4;
					if(G.ORB_VECTOR[i].return_power()>=2)
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::White);
					if(G.ORB_VECTOR[i].return_power()==3)
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::White);
				}
				
				Orb_Shape_Vector[colour_index][0].setPosition(G.ORB_COORDINATES[i][0]-G.ORB_RADIUS/2,G.ORB_COORDINATES[i][1]-G.ORB_RADIUS/2);
				Orb_Shape_Vector[colour_index][1].setPosition(G.ORB_COORDINATES[i][0]-2*G.ORB_RADIUS/2,G.ORB_COORDINATES[i][1]-2*G.ORB_RADIUS/2);
				Orb_Shape_Vector[colour_index][2].setPosition(G.ORB_COORDINATES[i][0]-3*G.ORB_RADIUS/2,G.ORB_COORDINATES[i][1]-3*G.ORB_RADIUS/2);
				
				if( G.ORB_VECTOR[i].return_max_power()>2)
					G.window->draw(Orb_Shape_Vector[colour_index][2]);
				if( G.ORB_VECTOR[i].return_max_power()>1)
					G.window->draw(Orb_Shape_Vector[colour_index][1]);
				G.window->draw(Orb_Shape_Vector[colour_index][0]);

				Health_Bar_Vector[colour_index].setPosition(G.ORB_COORDINATES[i][0]-50,G.ORB_COORDINATES[i][1]+30);
				Health_Bar_Vector[colour_index].setSize(Vector2f(G.ORB_VECTOR[i].return_health(),10));
				G.window->draw(Health_Bar_Vector[colour_index]);
				if( G.ORB_VECTOR[i].return_health()>=25 )
				{
					line.setPosition(G.ORB_COORDINATES[i][0]-50+25,G.ORB_COORDINATES[i][1]+30);
					G.window->draw(line);
					if( G.ORB_VECTOR[i].return_health()>=50 )
					{
						line.setPosition(G.ORB_COORDINATES[i][0]-50+50,G.ORB_COORDINATES[i][1]+30);
						G.window->draw(line);
						if( G.ORB_VECTOR[i].return_health()>=75 )
						{
							line.setPosition(G.ORB_COORDINATES[i][0]-50+75,G.ORB_COORDINATES[i][1]+30);
							G.window->draw(line);
						}
					}
				}
			}

		for (int i = 0; i<G.ORB_COUNT; i++)
		{
			CircleShape Unit_Shape(G.UNIT_RADIUS);

			for(int j = 0; j<G.ORB_VECTOR[i].orb_units.size(); j++)
			{
				Unit_Shape.setPosition(G.ORB_VECTOR[i].orb_units[j].return_unit_pos('x'),G.ORB_VECTOR[i].orb_units[j].return_unit_pos('y'));
				Unit_Shape.setOutlineThickness(0);
				
				if(G.ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'R')
				{
					Unit_Shape.setFillColor(Color::Red);
				}
				
				if(G.ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'B')
				{
					Unit_Shape.setFillColor(Color::Blue);
				}
				
				if(G.ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'G')
				{
					Unit_Shape.setFillColor(Color::Green);
				}
				
				if(G.ORB_VECTOR[i].orb_units[j].return_unit_colour() == 'Y')
				{
					Unit_Shape.setFillColor(Color::Yellow);
					if(G.ORB_VECTOR[i].orb_units[j].return_selection_status())
					{
						Unit_Shape.setOutlineColor(Color::White);
						Unit_Shape.setOutlineThickness(1);
					}
				}
				
				G.window->draw(Unit_Shape);
			}
		}
	}
}