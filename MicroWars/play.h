#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Orb.h"
#include "Tesla.h"
#include "Unit.h"

using namespace sf;
using namespace std;
using namespace microwars;

#define G_ORB_COUNT 7
#define G_PLAYER_COUNT 4
#define G_TESLA_COUNT 5

struct Statistics
{
	int Present_Units;
	int Losses;
	int Produce_Rate;
};

struct GameEssentials
{
	int ORB_COUNT;
	int ORB_RADIUS;
	
	int TESLA_COUNT;
	int TESLA_RADIUS;
	
	int UNIT_RADIUS;
	
	int PLAYER_COUNT;
	
	char PLAYER_COLOUR;
	
	char ORB_COLOUR[G_ORB_COUNT];
	float ORB_COORDINATES[G_ORB_COUNT][2];
	int ORB_INITIAL_UNITS[G_ORB_COUNT];
	int ORB_INITIAL_POWER[G_ORB_COUNT];
	int ORB_MAX_POWER[G_ORB_COUNT];
	
	float TESLA_COORDINATES[G_TESLA_COUNT][2];
	float TESLA_X_FACTOR[G_TESLA_COUNT];
	
	Statistics PLAYER_STATS[G_PLAYER_COUNT];
	
	vector <Orb> ORB_VECTOR;
	vector <Unit> UNIT_VECTOR[G_PLAYER_COUNT];
	vector <Tesla> TESLA_VECTOR;
	
	RenderWindow *window;
	
	bool start_play;
};

void init_window();

void main_menu(RenderWindow &window);

void init_game(RenderWindow &window, bool &start_play);

void draw_game(GameEssentials &G);

void update_game(GameEssentials &G);