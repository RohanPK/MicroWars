#include <iostream>
#include <SFML/Graphics.hpp>
#include "play.h"

using namespace sf;
using namespace std;
using namespace microwars;

void init_window()
{
	RenderWindow window(VideoMode(1080, 720), "Micro Wars", Style::Titlebar|Style::Close);
	Image game_icon;
	game_icon.loadFromFile("../assets/images/game_icon.png");
	window.setIcon(game_icon.getSize().x,game_icon.getSize().y,game_icon.getPixelsPtr());
	window.setVerticalSyncEnabled(true);
	main_menu(window);
}
