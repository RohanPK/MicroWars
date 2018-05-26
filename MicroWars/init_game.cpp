#include<functional>
#include "play.h"

void initialise(GameEssentials &G)
{
	for(int i = 0; i<G.ORB_COUNT; i++)
	{
		G.ORB_VECTOR.push_back(Orb(G.ORB_COORDINATES[i][0],G.ORB_COORDINATES[i][1],G.ORB_RADIUS,G.ORB_COLOUR[i],i,G.ORB_INITIAL_POWER[i],G.ORB_MAX_POWER[i],100));
		for(int j = 0; j<G.ORB_INITIAL_UNITS[i]; j++)
		{
			if(G.ORB_VECTOR[i].return_orb_colour()!='X')
			{
				G.ORB_VECTOR[i].produce_unit();
			}
		}
	}
}

void init_game(RenderWindow &window, bool &start_play)

{		
	GameEssentials G =  {
						G_ORB_COUNT,
						G_COLOUR_COUNT,
						30,
						4,
						'Y',
						{'B', 'G', 'Y', 'Y', 'R'}, 
						{{200, 200}, {178, 600}, {400, 250}, {660, 580}, {800, 240}}, 
						{100, 20, 60, 50, 300},
						{1, 2, 2, 1, 1},
						{3, 2, 3, 3, 2},
						{{100, 0, 1}, {20, 0, 2}, {110, 0, 3}, {300, 0, 1}}
						};

	G.start_play = start_play;
	G.window = &window;
	
	Thread thread_draw(&draw_game, (std::ref)(G));
	Thread thread_logic(&update_game, (std::ref)(G));
	
	initialise(G);
	
	thread_logic.launch();
	thread_draw.launch();
}