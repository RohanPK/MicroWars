#include <iostream>
#include <SFML/Graphics.hpp>
#include "play.h"

using namespace sf;
using namespace std;
using namespace microwars;

Image game_icon;

void init_window()
{
	RenderWindow window(VideoMode(1080, 720), "Micro Wars");
	
	game_icon.loadFromFile("../assets/images/game_icon.png");
	window.setIcon(game_icon.getSize().x,game_icon.getSize().y,game_icon.getPixelsPtr());
	main_menu(window);
}
