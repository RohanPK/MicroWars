#include <SFML/Graphics.hpp>

using namespace sf;

int play_ishan()
{
	RenderWindow window(VideoMode(1080, 720), "Micro Wars");
	window.clear(Color::Black);
	window.display();
	window.clear(Color::Black);
	sf::Vector2f starting_position;
	sf::Vector2f current_position;
	window.clear(Color::Black);
	window.display();
	window.clear(Color::Black);
    while (window.isOpen())
    {
        Event event;
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
						rectangle.setOutlineThickness(2);
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
    }
}

