#include <SFML/Graphics.hpp>
#include <iostream>
#include <Orb.h>
#include <Unit.h>
using namespace sf;


int play_rohan()

{
	//sf::Clock clock;
	//sf::Time elapsed1= clock.getElapsedTime();
	int orb_count=4,i;
	char array_colour[orb_count] = {'R','B','G','Y'};
	double orb_array[orb_count][2] = {{100,100},{200,200},{300,300},{400,400}};
	CircleShape bot(30);
	sf::RectangleShape rectangle;
	Font font;
	font.loadFromFile("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf");

	RenderWindow window(VideoMode(1080, 720), "Micro Wars");
	window.clear(Color::Black);
	window.display();
	window.clear(Color::Black);
	sf::Vector2f starting_position;
	sf::Vector2f current_position;
	window.clear(Color::Black);
	window.display();
	window.clear(Color::Black);

	std::vector <microwars::Orb> orb_vector;
	
	for(i=0;i<orb_count;i++)
	{
		orb_vector.push_back(microwars::Orb(orb_array[i][0],orb_array[i][1],array_colour[i],i,100,10));
	}


    while (window.isOpen())
    {
		window.display();
		window.clear();
        sf::Event event;
		
        while (window.pollEvent(event))
        {
			switch(event.type)
			{
				case Event::Closed:
					window.close();
					break;
				
				case Event::MouseButtonPressed:
					if(event.mouseButton.button == sf::Mouse::Left)
					{
						starting_position.x = event.mouseButton.x;
						starting_position.y = event.mouseButton.y;
					}
					break;
				case Event::MouseButtonReleased:
					if(event.mouseButton.button == sf::Mouse::Left)
					{
						current_position.x = event.mouseButton.x - starting_position.x;
						current_position.y = event.mouseButton.y - starting_position.y;
						
						rectangle.setFillColor(Color::Black);
						rectangle.setOutlineColor(Color::Cyan);
						rectangle.setOutlineThickness(1);
						rectangle.setSize(current_position);
						rectangle.setPosition(starting_position.x, starting_position.y);
						break;
					}
				default:
					break;
			}

        }
		window.draw(rectangle);   //Rectangle is region selected by mouse
		for( i=0; i<orb_count; i++)
			{
				bot.setPosition(orb_array[i][0],orb_array[i][1]);
				
				if( array_colour[i] == 'R' )
				{
					bot.setFillColor(sf::Color::Red);
				}
				if( array_colour[i] == 'B' )
				{
					bot.setFillColor(sf::Color::Blue);
				}
				if( array_colour[i]=='G' )
				{
					bot.setFillColor(sf::Color::Green);
				}
				if( array_colour[i]=='Y' )
				{
					bot.setFillColor(sf::Color::Yellow);
				}
				window.draw(bot);
			}
			for ( i=0; i<orb_count; i++)
			{
				int size = orb_vector[i].orb_units.size();
				for(int j=0; j<size; j++)
				{
					CircleShape basic_unit(4);
					basic_unit.setPosition( orb_vector[i].orb_units[j].return_unit_pos('x') ,orb_vector[i].orb_units[j].return_unit_pos('y'));
				if( orb_vector[i].return_orb_colour() == 'R' )
				{
					basic_unit.setFillColor(sf::Color::Red);
				}
				if( orb_vector[i].return_orb_colour() == 'B' )
				{
					basic_unit.setFillColor(sf::Color::Blue);
				}
				if( orb_vector[i].return_orb_colour() == 'G' )
				{
					basic_unit.setFillColor(sf::Color::Green);
				}
				if( orb_vector[i].return_orb_colour() == 'Y' )
				{
					basic_unit.setFillColor(sf::Color::Yellow);
				}
					window.draw(basic_unit);
					if( orb_vector[i].orb_units[j].move(600,600) == 0 )
					{
						orb_vector[i].orb_units[j].~Unit();
						orb_vector[i].orb_units.erase(orb_vector[i].orb_units.begin()+j);
						orb_vector[i].produce_unit();
					}
				}
			}
		
    }
}

