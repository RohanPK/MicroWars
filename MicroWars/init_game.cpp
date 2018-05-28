#include<functional>
#include "play.h"

void initialise(GameEssentials &G)
{
	for(int i = 0; i<G.ORB_COUNT; i++)
	{
		G.ORB_VECTOR.push_back(Orb(G.ORB_COORDINATES[i][0],G.ORB_COORDINATES[i][1],G.ORB_RADIUS,G.ORB_COLOUR[i],G.ORB_INITIAL_POWER[i],G.ORB_MAX_POWER[i],100));
		for(int j = 0; j<G.ORB_INITIAL_UNITS[i]; j++)
		{
			if(G.ORB_VECTOR[i].return_orb_colour()!='X')
			{
				G.UNIT_VECTOR[G.ORB_VECTOR[i].return_colour_index()].push_back(G.ORB_VECTOR[i].produce_unit());
			}
		}
	}
	for(int i = 0; i<G.TESLA_COUNT; i++)
	{
		G.TESLA_VECTOR.push_back(Tesla(G.TESLA_COORDINATES[i][0], G.TESLA_COORDINATES[i][1], G.TESLA_RADIUS, G.TESLA_X_FACTOR[i]));
	}
}

void init_game(RenderWindow &window, bool &start_play)

{
	GameEssentials G =  {
						G_ORB_COUNT,
						30,
						G_TESLA_COUNT,
						50,
						4,
						G_PLAYER_COUNT,
						'Y',
						{'B', 'G', 'Y', 'Y', 'X', 'R', 'R'}, 
						{{200, 200}, {178, 600}, {400, 250}, {660, 580}, {800, 240}, {260,400},{750,350}}, 
						{100, 20, 160, 150, 10, 0, 10},
						{1, 0, 2, 1, 1, 0, 1},
						{3, 2, 3, 3, 2, 2, 2},
						{{500, 300}},
						{1},
						{{100, 0, 1}, {20, 0, 0}, {10, 0, 1}, {310, 0, 3}}
						};

	G.start_play = start_play;
	G.window = &window;
	
	Thread thread_draw(&draw_game, (std::ref)(G));
	Thread thread_logic(&update_game, (std::ref)(G));
	
	initialise(G);
	
	thread_logic.launch();
	thread_draw.launch();
}