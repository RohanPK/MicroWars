#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Orb.h"
#include "Unit.h"
#include "main_menu.h"

using namespace sf;
using namespace std;
using namespace microwars;

	RenderWindow window(VideoMode(1080, 720), "Micro Wars");

	Image game_icon;

void init_window()
{
	game_icon.loadFromFile("../assets/images/game_icon.png");
	window.setIcon(game_icon.getSize().x,game_icon.getSize().y,game_icon.getPixelsPtr());

}
