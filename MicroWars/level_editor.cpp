#include "play.h"

void save_to_disk(vector <Orb> Orb_Vector,vector <Tesla> Tesla_Vector, vector<int> Initial_Units_Vector)
{
	ofstream level_file;
	level_file.open("../assets/levels/level.txt");
	level_file<<Orb_Vector.size()<<"\n";															//TOTAL ORBS
	level_file<<"30\n";																				//ORB RADIUS
	level_file<<Tesla_Vector.size()<<"\n";															//TESLA COUNT
	level_file<<"50\n";																				//TESLA RADIUS
	level_file<<"4\n";																				//UNIT RADIUS
	level_file<<"4\n";																				//NUMBER OF PLAYERS
	for(int i=0; i<Orb_Vector.size();i++)
	{
		level_file<<Orb_Vector[i].return_orb_colour()<<" ";											//ORB COLOURS
	}
	level_file<<"\n";
	for(int i=0; i<Orb_Vector.size();i++)
	{
		level_file<<Orb_Vector[i].return_orb_pos('x')<<","<<Orb_Vector[i].return_orb_pos('y')<<" ";	//ORB CO-ORDINATES:- IDEAL RANGE:((100-1500),(100-980))
	}
	level_file<<"\n";
	for(int i=0; i<Initial_Units_Vector.size();i++)
	{
		level_file<<Initial_Units_Vector[i]<<" ";													//INITIAL UNITS
	}
	level_file<<"\n";
	for(int i=0; i<Orb_Vector.size();i++)
	{
		level_file<<Orb_Vector[i].return_power()<<" ";												//INITIAL ORB POWER
	}
	level_file<<"\n";
	for(int i=0; i<Orb_Vector.size();i++)
	{
		level_file<<Orb_Vector[i].return_max_power()<<" ";											//MAXIMUM ORB POWER
	}
	level_file<<"\n";
	for(int i=0; i<Tesla_Vector.size();i++)
	{
		level_file<<Tesla_Vector[i].return_tesla_pos('x')<<","<<Tesla_Vector[i].return_tesla_pos('y')<<" ";	//TESLA CO-ORDINATES
	}
	level_file<<"\n";
	for(int i=0; i<Tesla_Vector.size();i++)
	{
		level_file<<Tesla_Vector[i].return_x_factor()<<" ";											//TESLA CO-ORDINATES
	}
	level_file<<"\n";
}


int edit_level(RenderWindow &window,bool &start_edit)
{
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

	vector < vector <CircleShape> >Orb_Shape_Vector(6,vector <CircleShape>(2));
	vector < Orb > Orb_Vector;
	vector < Tesla > Tesla_Vector;
	vector < int > Initial_Units_Vector;
	
	RectangleShape Stats_Container;
	Stats_Container.setSize(Vector2f(310, 1080));
	Stats_Container.setFillColor(Color::Black);
	Stats_Container.setPosition(1610,0);

	Font font_mouse;
	font_mouse.loadFromFile("../assets/fonts/power.ttf");
	Font font_save;
	font_save.loadFromFile("../assets/fonts/exit.ttf");

	Text save_level("SAVE",font_mouse,45);
	save_level.setColor(sf::Color::White);
	Vector2f position_save(1610,980);
	save_level.setPosition(position_save.x +60,position_save.y + 20);
	RectangleShape save_button;
	save_button.setSize(Vector2f(400,100));
	save_button.setFillColor(Color::Red);
	save_button.setPosition(position_save);

	for(int i=0; i<Orb_Shape_Vector.size(); i++)
	{
		Orb_Shape_Vector[i][0].setTexture(NULL);
		Orb_Shape_Vector[i][0].setRadius(30);
		switch (i) 
		{
			case 0 :
			{
				Orb_Shape_Vector[i][0].setTexture(p_blue_Texture,true);
				break;
			}
			case 1 :
			{
				Orb_Shape_Vector[i][0].setTexture(p_green_Texture,true);
				break;
			}
			
			case 2 :
			{
				Orb_Shape_Vector[i][0].setTexture(p_red_Texture,true);
				break;
			}
			
			case 3 :
			{	
				Orb_Shape_Vector[i][0].setTexture(p_yellow_Texture,true);
				break;
			}
			
			case 4:
			{
				Orb_Shape_Vector[i][0].setTexture(p_grey_Texture,true);
				break;
			}
			
			case 5:
			{
				Orb_Shape_Vector[i][0].setTexture(p_tesla_Texture,true);
				break;
			}
		}
	}
	
	int colour_index = 0;
	int current_power = 0;
	int max_power = 0;
	int x_factor = 0;
	char colour_letter = 'B';
	int initial_units = 0;

	Text mouse_text("(0,0)",font_mouse,15);
	Text orb_text("0,0",font_mouse,15);
	
	while(window.isOpen())
	{
		window.display();
		window.clear();

		Event event;
		Vector2i mouse_position= Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				case Event::Closed:
				{
					window.close();
					return 0;
					break;
				}
				
				case Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::Num1)
					{
						colour_index=0;
						colour_letter='B';
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Num2)
					{
						colour_index=1;
						colour_letter='G';
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Num3)
					{
						colour_index=2;
						colour_letter='R';
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Num4)
					{
						colour_index=3;
						colour_letter='Y';
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Num5)
					{
						colour_index=4;
						colour_letter='X';
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Num6)
					{
						colour_index=5;
						current_power=max_power;
						colour_letter='T';
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Left)
					{
						if(colour_index == 5)
						{
							x_factor-=10;
						}
						else
						{
							max_power--;
						}
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Right)
					{
						if(colour_index == 5)
						{
							x_factor+=10;
						}
						else
						{
							max_power++;
						}
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Down )
					{
						if(colour_index == 5)
						{
							x_factor-=100;;
						}
						else
						{
							current_power--;
						}
						break;
					}
					
					else if (event.key.code == sf::Keyboard::Up )
					{
						if(colour_index == 5)
						{
							x_factor+=100;
						}
						else
						{
							current_power++;
						}
						break;
					}
					
					else if(event.key.code == sf::Keyboard::W)
					{
						if(colour_index<4)
						{
							initial_units += 100;
						}
						break;
					}
					
					else if(event.key.code == sf::Keyboard::S)
					{
						if(colour_index<4)
						{
							initial_units -= 100;
						}
						break;
					}
					
					else if(event.key.code == sf::Keyboard::A)
					{
						if(colour_index<4)
						{
							initial_units -= 10;
						}
						break;
					}
					
					else if(event.key.code == sf::Keyboard::D)
					{
						if(colour_index<4)
						{
							initial_units += 10;
						}
						break;
					}
				}
				default:
					break;
			}
		}

		if( Mouse::getPosition(window).x >= position_save.x && Mouse::getPosition(window).x <= (1920) && Mouse::getPosition(window).y >=position_save.y && Mouse::getPosition(window).y <= (1080) )
		{
			save_level.setColor(Color::White);
			if( event.mouseButton.button == Mouse::Left && start_edit==false)
			{
				break;
			}
		}
		else
		{
			save_level.setColor(Color::Black);
		}

		Orb_Shape_Vector[colour_index][0].setPosition(mouse_position.x-30,mouse_position.y-30);
		
		string information;
		if(colour_index == 5)
		{
			information="("+ to_string(mouse_position.x) +','+ to_string(mouse_position.y)+")"+"\nX Factor:"+to_string(x_factor);
		}
		else if(colour_index == 4)
		{
			information="("+ to_string(mouse_position.x) +','+ to_string(mouse_position.y)+")"+"\nCurrent Power:"+to_string(current_power)+"\nMax Power:"+to_string(max_power);
		}
		else
		{
			information="("+ to_string(mouse_position.x) +','+ to_string(mouse_position.y)+")"+"\nCurrent Power:"+to_string(current_power)+"\nMax Power:"+to_string(max_power)+"\nInitial Units:"+to_string(initial_units);
		}
		mouse_text.setString(information);
		mouse_text.setPosition(mouse_position.x+20,mouse_position.y+20);
		window.draw(mouse_text);
		window.draw(Orb_Shape_Vector[colour_index][0]);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(start_edit)
			{
				start_edit=false;
			}
			else
			{
				if ( colour_index !=5 )
				{
					if( max_power>=current_power )
						{
							Orb_Vector.push_back(Orb(mouse_position.x,mouse_position.y,30,colour_letter,current_power,max_power,current_power*100));							
							Initial_Units_Vector.push_back(initial_units);
						}
				}
				else
				{
					Tesla_Vector.push_back(Tesla(mouse_position.x,mouse_position.y,50,x_factor));
				}
			}
			sleep(sf::seconds(0.5));
		}
		for(int i=0;i<Orb_Vector.size();i++)
		{
			Orb_Shape_Vector[Orb_Vector[i].return_colour_index()][0].setPosition(Orb_Vector[i].return_orb_pos('x')-30,Orb_Vector[i].return_orb_pos('y')-30);
			orb_text.setPosition(Orb_Vector[i].return_orb_pos('x'),Orb_Vector[i].return_orb_pos('y')+20);
			orb_text.setString("P:"+to_string(Orb_Vector[i].return_power())+"\nMP:"+to_string(Orb_Vector[i].return_max_power()));
			window.draw(Orb_Shape_Vector[Orb_Vector[i].return_colour_index()][0]);
			window.draw(orb_text);
		}
		for(int i=0;i<Tesla_Vector.size();i++)
		{
			Orb_Shape_Vector[5][0].setPosition(Tesla_Vector[i].return_tesla_pos('x')-30,Tesla_Vector[i].return_tesla_pos('y')-30);
			orb_text.setPosition(Tesla_Vector[i].return_tesla_pos('x'),Tesla_Vector[i].return_tesla_pos('y')+30);
			orb_text.setString("X:"+to_string(Tesla_Vector[i].return_x_factor()));
			window.draw(Orb_Shape_Vector[5][0]);
			window.draw(orb_text);
		}

		window.draw(Stats_Container);
		window.draw(save_button);
		window.draw(save_level);

		sleep(sf::milliseconds(10));
	}

	save_to_disk(Orb_Vector,Tesla_Vector,Initial_Units_Vector);
	main_menu(window);
}
