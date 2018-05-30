#include<functional>
#include "play.h"

GameEssentials read_level()
{
	ifstream level_file("../assets/levels/level.txt");
	GameEssentials G;

	level_file>>G.ORB_COUNT;
	level_file>>G.ORB_RADIUS; 
	level_file>>G.TESLA_COUNT;
	level_file>>G.TESLA_RADIUS;
	level_file>>G.UNIT_RADIUS;
	level_file>>G.PLAYER_COUNT;

	for(int i=0; i<G.ORB_COUNT;i++)
	{
		level_file>>G.ORB_COLOUR[i];
	}
	
	char comma;
	for(int i=0; i<G.ORB_COUNT;i++)
	{
		level_file>>G.ORB_COORDINATES[i][0]>>comma>>G.ORB_COORDINATES[i][1];
	}
	
	for(int i=0; i<G.ORB_COUNT;i++)
	{
		level_file>>G.ORB_INITIAL_UNITS[i];
	}

	for(int i=0; i<G.ORB_COUNT;i++)
	{
		level_file>>G.ORB_INITIAL_POWER[i];
	}
	
	for(int i=0; i<G.ORB_COUNT;i++)
	{
		level_file>>G.ORB_MAX_POWER[i];
	}
	
	for(int i=0; i<G.TESLA_COUNT;i++)
	{
		level_file>>G.TESLA_COORDINATES[i][0]>>comma>>G.TESLA_COORDINATES[i][1];
	}
	
	for(int i=0; i<G.TESLA_COUNT;i++)
	{
		level_file>>G.TESLA_X_FACTOR[i];
	}
	return G;
}

void initialise(GameEssentials &G)
{
	//INITIALISING ORBS
	for(int i = 0; i<G.ORB_COUNT; i++)
	{
		G.ORB_VECTOR.push_back(Orb(G.ORB_COORDINATES[i][0],G.ORB_COORDINATES[i][1],G.ORB_RADIUS,G.ORB_COLOUR[i],G.ORB_INITIAL_POWER[i],G.ORB_MAX_POWER[i],100*G.ORB_INITIAL_POWER[i]));
		
		//SPAWNING INITIAL UNITS ON THE RESPECTIVE ORBS
		for(int j = 0; j<G.ORB_INITIAL_UNITS[i]; j++)
		{
			if(G.ORB_VECTOR[i].return_orb_colour()!='X')
			{
				G.UNIT_VECTOR[G.ORB_VECTOR[i].return_colour_index()].push_back(G.ORB_VECTOR[i].produce_unit());
			}
		}
	}
	
	//INITIALISING TESLAS
	for(int i = 0; i<G.TESLA_COUNT; i++)
	{
		G.TESLA_VECTOR.push_back(Tesla(G.TESLA_COORDINATES[i][0], G.TESLA_COORDINATES[i][1], G.TESLA_RADIUS, G.TESLA_X_FACTOR[i]));
	}
	
	//SETTING LOSSES ZERO
	for(int i = 0; i<G.PLAYER_COUNT; i++)
	{
		G.PLAYER_STATS[i].Losses = 0;
	}
}

void init_game(RenderWindow &window, bool &start_play)

{
	GameEssentials G;/* =
	{
		G_ORB_COUNT,																			//TOTAL ORBS
		30,																						//ORB RADIUS
		G_TESLA_COUNT,																			//TESLA COUNT
		50,																						//TESLA RADIUS
		4,																						//UNIT RADIUS
		G_PLAYER_COUNT,																			//NUMBER OF PLAYERS
		'Y',																					//PLAYER COLOUR
		{'B', 'G', 'R', 'R', 'Y', 'Y', 'Y'},													//ORB COLOURS
		{{100, 800}, {200, 300}, {1300, 200}, {400, 500}, {1000, 400}, {600,700}, {900,600}},	//ORB CO-ORDINATES:- IDEAL RANGE:((100-1500),(100-980))
		{0, 0, 0, 0, 200, 100, 1000},															//INITIAL UNITS
		{3, 1, 1, 2, 1, 3, 10},																	//INITIAL ORB POWER
		{3, 3, 3, 3, 1, 3, 10},																	//MAXIMUM ORB POWER
		{{800, 300}},																			//TESLA CO-ORDINATES
		{2},																					//TESLA X-FACTOR
	};*/
	G = read_level();
	G.PLAYER_COLOUR = 'Y';
	G.start_play = start_play;
	G.window = &window;
	
	Thread thread_draw(&draw_game, (std::ref)(G));
	Thread thread_logic(&update_game, (std::ref)(G));
	
	initialise(G);
	
	thread_logic.launch();
	thread_draw.launch();
}
