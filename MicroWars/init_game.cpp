#include<functional>
#include "play.h"

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
}

void init_game(RenderWindow &window, bool &start_play)

{
	GameEssentials G =  
	{
		G_ORB_COUNT,																			//TOTAL ORBS
		30,																						//ORB RADIUS
		G_TESLA_COUNT,																			//TESLA COUNT
		50,																						//TESLA RADIUS
		4,																						//UNIT RADIUS
		G_PLAYER_COUNT,																			//NUMBER OF PLAYERS
		'G',																					//PLAYER COLOUR
		{'B', 'G', 'R', 'R', 'Y', 'Y', 'X'},													//ORB COLOURS
		{{100, 800}, {200, 300}, {1300, 200}, {400, 500}, {1500, 400}, {600,700}, {900,600}},	//ORB CO-ORDINATES:- IDEAL RANGE:((100-1500),(100-980))
		{100, 200, 100, 100, 200, 0, 0},														//INITIAL UNITS
		{3, 1, 1, 2, 1, 1, 0},																	//INITIAL ORB POWER
		{3, 3, 3, 3, 3, 2, 2},																	//MAXIMUM ORB POWER
		{{800, 500}},																			//TESLA CO-ORDINATES
		{2},																					//TESLA X-FACTOR
		{{100, 0, 3}, {200, 0, 1}, {200, 0, 3}, {200, 0, 2}}									//INITIAL STATS
	};

	G.start_play = start_play;
	G.window = &window;
	
	Thread thread_draw(&draw_game, (std::ref)(G));
	Thread thread_logic(&update_game, (std::ref)(G));
	
	initialise(G);
	
	thread_logic.launch();
	thread_draw.launch();
}