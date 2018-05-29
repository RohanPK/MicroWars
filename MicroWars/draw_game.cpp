#include "play.h"

void draw_game(GameEssentials &G)
{
	//LOAD TEXTURES
	Texture texture_yellow,texture_red,texture_green,texture_blue,texture_grey,texture_tesla;
	
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

	texture_tesla.loadFromFile("../assets/images/tesla.png");
	texture_tesla.setSmooth(true);
	const sf::Texture *p_tesla_Texture = &texture_tesla;

	Sprite background;
	
	Texture background_image;
	background_image.loadFromFile("../assets/images/play_background.png");
	background.setTexture(background_image);
	background.setScale(1.3,1.5);

	//ORB SHAPE ARRAY
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

	RectangleShape Stats_Container;
	Stats_Container.setSize(Vector2f(310, 1080));
	Stats_Container.setFillColor(Color(0,0,0,90));
	Stats_Container.setPosition(1610,0);
	Font font_stats;
	font_stats.loadFromFile("../assets/fonts/KGHAPPY.ttf");
	Text stats_text("",font_stats,20);

	Font font_health;
	font_health.loadFromFile("../assets/fonts/KGHAPPY.ttf");

	for(int i=0; i<6; i++)
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
			
			case 5:
			{
				Orb_Shape.setTexture(p_tesla_Texture,true);
				Orb_Shape.setRadius(G.TESLA_RADIUS);
				health_bar.setFillColor(Color::Magenta);
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
	G.window->setFramerateLimit(60);
	G.window->display();
	
	Clock run_time;
	int elapsed_minutes;

	Clock line_animation;
	Time animation_delay=seconds(0.005);

	while(G.window->isOpen())
	{

		G.window->display();
		G.window->clear();
		G.window->draw(background);
		G.window->draw(Stats_Container);
		Event event;

		while (G.window->pollEvent(event))
		{
			//SELECTION-BOX
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

		//MOVE UNITS
		int i;
		switch(G.PLAYER_COLOUR)
		{
			case 'B':
			{
				i = 0;
				break;
			}
			case 'G':
			{
				i = 1;
				break;
			}
			case 'R':
			{
				i = 2;
				break;
			}
			case 'Y':
			{
				i = 3;
				break;
			}
			default:
			{
				break;
			}
		}
		if (event.mouseButton.button == Mouse::Right && Mouse::isButtonPressed(Mouse::Button::Right))
		{
			Vector2f destination_point;
			
			destination_point.x	= event.mouseButton.x;
			destination_point.y = event.mouseButton.y;
			for(int j = 0; j<G.UNIT_VECTOR[i].size(); j++)
			{
				if(G.UNIT_VECTOR[i][j].return_unit_colour() == G.PLAYER_COLOUR )
				{
					if(G.UNIT_VECTOR[i][j].return_unit_pos('x') >=  min(final_position.x,starting_position.x))
					{
						if(G.UNIT_VECTOR[i][j].return_unit_pos('x') <= max(final_position.x,starting_position.x)) 
						{
							if(G.UNIT_VECTOR[i][j].return_unit_pos('y') >= min(final_position.y,starting_position.y))
							{
								if(G.UNIT_VECTOR[i][j].return_unit_pos('y') <= max(final_position.y,starting_position.y))
								{
									if( destination_point.x!=0 && destination_point.y!=0 )
									{
										if( destination_point.x<=Stats_Container.getPosition().x)
										{
											G.UNIT_VECTOR[i][j].set_unit_destination(destination_point.x, destination_point.y);
										}
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

		//DRAW TESLA
		for(int i=0;i<G.TESLA_COUNT;i++)
		{
			Orb_Shape_Vector[5][0].setPosition(G.TESLA_COORDINATES[i][0]-(G.TESLA_RADIUS/2) -10,G.TESLA_COORDINATES[i][1]-(G.TESLA_RADIUS/2) -10);
			
			int health_length = (G.TESLA_VECTOR[i].return_health()%101);
			Health_Bar_Vector[5].setPosition(G.TESLA_COORDINATES[i][0]-50,G.TESLA_COORDINATES[i][1]+40);
			Health_Bar_Vector[5].setSize(Vector2f(health_length,10));
			
			if( G.TESLA_VECTOR[i].return_health()>0)
			{
				G.window->draw(Health_Bar_Vector[5]);
			}
			G.window->draw(Orb_Shape_Vector[5][0]);
		}
		

		for(int i=0; i<G.LINE_VECTOR.size();i++)
		{
			G.window->draw(G.LINE_VECTOR[i][0]);
			G.window->draw(G.LINE_VECTOR[i][1]);
			if(line_animation.getElapsedTime()>animation_delay)
			{
				line_animation.restart();
				G.LINE_VECTOR.erase(G.LINE_VECTOR.begin()+i);
			}
		}

		//DRAW ORB AND HEALTH
		for(int i = 0; i<G.ORB_COUNT; i++)
			{
				int colour_index;
				RectangleShape line(sf::Vector2f(2,10));
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'R')
				{
					colour_index=2;
					Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::White);
					Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::White);
					if(G.ORB_VECTOR[i].return_power()>=2)
					{
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Red);
					}
					if(G.ORB_VECTOR[i].return_power()==3)
					{
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Red);
					}
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'B')
				{
					colour_index=0;
					Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::White);
					Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::White);
					if(G.ORB_VECTOR[i].return_power()>=2)
					{
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Blue);
					}
					if(G.ORB_VECTOR[i].return_power()==3)
					{
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Blue);
					}
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'G')
				{
					colour_index=1;
					Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::White);
					Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::White);
					if(G.ORB_VECTOR[i].return_power()>=2)
					{
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Green);
					}
					if(G.ORB_VECTOR[i].return_power()==3)
					{
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Green);
					}
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'Y')
				{
					colour_index=3;
					Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::White);
					Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::White);
					if(G.ORB_VECTOR[i].return_power()>=2)
					{
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::Yellow);
					}
					if(G.ORB_VECTOR[i].return_power()==3)
					{
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::Yellow);
					}
				}
				
				if(G.ORB_VECTOR[i].return_orb_colour() == 'X')
				{
					colour_index=4;
					Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::White);
					Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::White);
					if(G.ORB_VECTOR[i].return_power()>=2)
					{
						Orb_Shape_Vector[colour_index][2].setOutlineColor(Color::White);
					}
					if(G.ORB_VECTOR[i].return_power()==3)
					{
						Orb_Shape_Vector[colour_index][1].setOutlineColor(Color::White);
					}
				}
				
				Orb_Shape_Vector[colour_index][0].setPosition(G.ORB_COORDINATES[i][0]-G.ORB_RADIUS/2,G.ORB_COORDINATES[i][1]-G.ORB_RADIUS/2);
				Orb_Shape_Vector[colour_index][1].setPosition(G.ORB_COORDINATES[i][0]-2*G.ORB_RADIUS/2,G.ORB_COORDINATES[i][1]-2*G.ORB_RADIUS/2);
				Orb_Shape_Vector[colour_index][2].setPosition(G.ORB_COORDINATES[i][0]-3*G.ORB_RADIUS/2,G.ORB_COORDINATES[i][1]-3*G.ORB_RADIUS/2);
				
				if( G.ORB_VECTOR[i].return_max_power()>2)
				{
					G.window->draw(Orb_Shape_Vector[colour_index][2]);
				}
				if( G.ORB_VECTOR[i].return_max_power()>1)
				{
					G.window->draw(Orb_Shape_Vector[colour_index][1]);
				}
				G.window->draw(Orb_Shape_Vector[colour_index][0]);

				int health_length = (G.ORB_VECTOR[i].return_health()%101);
				Health_Bar_Vector[colour_index].setPosition(G.ORB_COORDINATES[i][0]-50,G.ORB_COORDINATES[i][1]+40);
				Health_Bar_Vector[colour_index].setSize(Vector2f(health_length,10));
				if( G.ORB_VECTOR[i].return_health()>0)
				{
					G.window->draw(Health_Bar_Vector[colour_index]);
				}
				
				string health_text;
				if(G.ORB_VECTOR[i].return_orb_colour() != 'X')
				{
					health_text=to_string(G.ORB_VECTOR[i].return_health());
				}
				else
				{
					health_text='0';
				}
				Text health_number(health_text,font_health,20);
				health_number.setPosition(Vector2f(G.ORB_COORDINATES[i][0]-15,G.ORB_COORDINATES[i][1]+60));
				G.window->draw(health_number);
			}

		//DRAW UNITS
		for (int i = 0; i<G.PLAYER_COUNT; i++)
		{
			CircleShape Unit_Shape(G.UNIT_RADIUS);

			for(int j = 0; j<G.UNIT_VECTOR[i].size(); j++)
			{
				Unit_Shape.setPosition(G.UNIT_VECTOR[i][j].return_unit_pos('x'),G.UNIT_VECTOR[i][j].return_unit_pos('y'));
				Unit_Shape.setOutlineThickness(0);
				
				if(G.UNIT_VECTOR[i][j].return_unit_colour() == 'R')
				{
					Unit_Shape.setFillColor(Color::Red);
				}
				
				if(G.UNIT_VECTOR[i][j].return_unit_colour() == 'B')
				{
					Unit_Shape.setFillColor(Color::Blue);
				}
				
				if(G.UNIT_VECTOR[i][j].return_unit_colour() == 'G')
				{
					Unit_Shape.setFillColor(Color::Green);
				}
				
				if(G.UNIT_VECTOR[i][j].return_unit_colour() == 'Y')
				{
					Unit_Shape.setFillColor(Color::Yellow);
				}

				if(G.UNIT_VECTOR[i][j].return_selection_status())
				{
					Unit_Shape.setOutlineColor(Color::White);
					Unit_Shape.setOutlineThickness(1);
				}
				G.window->draw(Unit_Shape);
			}
		}

		//DRAW STATS
		Vector2i base_text_location =Vector2i(1620,50);
		for(int i=0;i<4;i++)
		{
			if(G.PLAYER_STATS[i].Produce_Rate!=0 || G.PLAYER_STATS[i].Produce_Rate==0)
			{
				if ( i== 0 )
				{
					stats_text.setColor(Color::Blue);
				}
				else if (i == 1 )
				{
					stats_text.setColor(Color::Green);
				}
				else if (i == 2 )
				{
					stats_text.setColor(Color::Red);
				}
				else if (i == 3 )
				{
					stats_text.setColor(Color::Yellow);
				}
				int offset=40;
				stats_text.setPosition(base_text_location.x,base_text_location.y);
				stats_text.setString("Units:  "+to_string(G.PLAYER_STATS[i].Present_Units));
				G.window->draw(stats_text);
				stats_text.setPosition(base_text_location.x,base_text_location.y+offset);
				stats_text.setString("Production:  "+to_string(G.PLAYER_STATS[i].Produce_Rate)+" units/s");
				G.window->draw(stats_text);
				stats_text.setPosition(base_text_location.x,base_text_location.y+2*offset);
				stats_text.setString("Losses:  "+to_string(G.PLAYER_STATS[i].Losses));
				G.window->draw(stats_text);
			}
			base_text_location.y=base_text_location.y+250;
		}

	//DISPLAY TIMER
	Time elapsed_seconds = run_time.getElapsedTime();
	if( elapsed_seconds.asSeconds()/60>=1)
	{
		run_time.restart();
		elapsed_minutes++;
	}
	
	stats_text.setColor(Color::Cyan);
	
	if(elapsed_seconds.asSeconds()<10)
	{
		stats_text.setString("\tTIME ELAPSED: "+to_string(elapsed_minutes)+":0"+to_string(int(elapsed_seconds.asSeconds())));
	}
	else
	{
		stats_text.setString("\tTIME ELAPSED: "+to_string(elapsed_minutes)+":"+to_string(int(elapsed_seconds.asSeconds())));
	}
	stats_text.setPosition(base_text_location.x,base_text_location.y);
	G.window->draw(stats_text);

	//PREVENT RUNNING AT CPU SPEED
	sleep(sf::milliseconds(10));
	}
}