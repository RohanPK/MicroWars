#include "play.h"

void main_menu(RenderWindow &window)
{
	bool start_play = false;
	
	window.display();

	Vector2f Scale_Window=Vector2f(1.78,1.5);
	
	Font font_title,font_buttons;
	font_title.loadFromFile("../assets/fonts/title.ttf");
	
	Text menu_title("MicroWars",font_title,150);
	menu_title.setColor(sf::Color::Red);
	Vector2f position_menu(300*Scale_Window.x+50,50*Scale_Window.y);
	menu_title.setPosition(position_menu);
	
	Text menu_play("Play",font_title,75);
	menu_play.setColor(sf::Color::Red);
	Vector2f position_play(450*Scale_Window.x,200*Scale_Window.y);
	menu_play.setPosition(position_play);
	
	Text menu_options("Options",font_title,75);
	menu_options.setColor(sf::Color::Red);
	Vector2f position_options(450*Scale_Window.x,250*Scale_Window.y);
	menu_options.setPosition(position_options);
	
	Text menu_quit("Quit",font_title,75);
	menu_quit.setColor(sf::Color::Red);
	Vector2f position_quit(450*Scale_Window.x,300*Scale_Window.y);
	menu_quit.setPosition(position_quit);
	
	RectangleShape menu_box;
	
	Texture background_image;
	background_image.loadFromFile("../assets/images/main_menu.png");
	
	Sprite background;
	background.setTexture(background_image);
	background.setScale(1,1);

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

			if( Mouse::getPosition(window).x >= position_play.x && Mouse::getPosition(window).x <= (position_play.x+150) && Mouse::getPosition(window).y >=position_play.y && Mouse::getPosition(window).y <= (position_play.y+75) )
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

			if( Mouse::getPosition(window).x >= position_options.x && Mouse::getPosition(window).x <= (position_options.x+150) && Mouse::getPosition(window).y >=position_options.y && Mouse::getPosition(window).y <= (position_options.y+75) )
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

			if( Mouse::getPosition(window).x >= position_quit.x && Mouse::getPosition(window).x <= (position_quit.x+150) && Mouse::getPosition(window).y >=position_quit.y && Mouse::getPosition(window).y <= (position_quit.y+75) )
			{
				menu_quit.setColor(Color::White);
				
				if( event.mouseButton.button == Mouse::Left )
				{
					background_music.stop();
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
			background_music.stop();
			break;
		}

		window.draw(menu_title);
		window.draw(menu_play);
		window.draw(menu_options);
		window.draw(menu_quit);
	}
	
	init_game(window, start_play);
}