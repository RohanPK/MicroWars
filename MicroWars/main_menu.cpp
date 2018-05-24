#include "play.h"

void main_menu(RenderWindow &window)
{
	bool start_play = false;
	
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
					start_play = true;
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
					start_play = true;
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
	
	init_game(window);
}