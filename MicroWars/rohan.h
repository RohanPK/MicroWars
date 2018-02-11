#include <SFML/Graphics.hpp>
#include <iostream>
#include <Orb.h>
#include <Unit.h>
using namespace sf;


int play()

{
	sf::Clock clock;
	sf::Time elapsed1= clock.getElapsedTime();
	
	
	char array_colour[7] = {'R','B','G','R','G','B','R'};
	double orb_array[7][2] = {(100,100),(200,100),(300,100),(400,100),(500,100),(600,100),(700,600)};
	CircleShape bot(30);
	
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

	std::vector <orb::Orb> orb_vector;
	
	for(int i=0;i<7;i++)
	{
		orb_vector.push_back(orb::Orb(orb_array[i][0],orb_array[i][1],array_colour[i],i,100,10));
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
						window.clear(Color::Black);
						starting_position.x = event.mouseButton.x;
						starting_position.y = event.mouseButton.y;
					}
					break;
				case Event::MouseButtonReleased:
					if(event.mouseButton.button == sf::Mouse::Left)
					{
						current_position.x = event.mouseButton.x - starting_position.x;
						current_position.y = event.mouseButton.y - starting_position.y;
						sf::RectangleShape rectangle;
						rectangle.setFillColor(Color::Black);
						rectangle.setOutlineColor(Color::Cyan);
						rectangle.setOutlineThickness(1);
						rectangle.setSize(current_position);
						rectangle.setPosition(starting_position.x, starting_position.y);
						window.draw(rectangle);
						window.display();
						break;
					}
				default:
					break;
			}

        }
		for(int i=0;i<7;i++)
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
				window.draw(bot);
			}
			/*for (int i=0; i<7;i++)
			{
				int size=orb_vector[i].orb_units.size();
				for(int j=0;j<size;j++)
				{
					CircleShape basic_unit(4);
					basic_unit.setPosition( orb_vector[i].orb_units[j].return_unit_pos('x') ,orb_vector[i].orb_units[j].return_unit_pos('y'));
					basic_unit.setFillColor(sf::Color::White);
					window.draw(basic_unit);
					if(orb_vector[i].orb_units[j].move(100,100) == 0)
					{
						orb_vector[i].orb_units[j].~Unit();
						orb_vector[i].orb_units.erase(orb_vector[i].orb_units.begin()+j);
						orb_vector[i].produce_unit();
					}
				}
			}*/
		
    }
}

