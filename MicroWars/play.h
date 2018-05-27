	#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Orb.h"
#include "Unit.h"

using namespace sf;
using namespace std;
using namespace microwars;

#define G_ORB_COUNT 5
#define G_COLOUR_COUNT 4

struct Statistics
{
	int Orb_Present_Units;
	int Orb_Losses;
	int Orb_Produce_Rate;
};

struct GameEssentials
{
	int ORB_COUNT;
	int COLOUR_COUNT;
	int ORB_RADIUS;
	int UNIT_RADIUS;
	char PLAYER_COLOUR;
	int PLAYER_COUNT;
	
	char ORB_COLOUR[G_ORB_COUNT];
	float ORB_COORDINATES[G_ORB_COUNT][2];
	int ORB_INITIAL_UNITS[G_ORB_COUNT];
	int ORB_INITIAL_POWER[G_ORB_COUNT];
	int ORB_MAX_POWER[G_ORB_COUNT];
	
	Statistics ORB_STATS[G_COLOUR_COUNT];
	
	vector <Orb> ORB_VECTOR;
	vector <Unit> UNIT_VECTOR[5];
	RenderWindow *window;
	
	bool start_play;
};

void init_window();

void main_menu(RenderWindow &window);

void init_game(RenderWindow &window, bool &start_play);

void draw_game(GameEssentials &G);

void update_game(GameEssentials &G);