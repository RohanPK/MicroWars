#include "play.h"

void initialise(GameEssentials G)
{
	for(int i = 0; i<G.ORB_COUNT; i++)
	{
		G.ORB_VECTOR.push_back(Orb(G.ORB_COORDINATES[i][0],G.ORB_COORDINATES[i][1],G.ORB_RADIUS,G.ORB_COLOUR[i],i,1,G.ORB_MAX_POWER[i],100));
		for(int j = 0; j<G.ORB_INITIAL_UNITS[i]; j++)
		{
			G.ORB_VECTOR[i].produce_unit();
		}
	}
}

void init_game(RenderWindow &window)
{		
	GameEssentials G={5,30,4,'Y',{'Y','G','B','R','Y'}, {{50,200}, {178,654}, {250,124}, {560,633},{600,240}}, {100, 20, 0, 0,300}, {3,2,3,3,2}};
	
	G.window = &window;
	
	Thread thread_draw(&draw_game, G);
	Thread thread_logic(&update_game, G);
	
	initialise(G);
	
	thread_logic.launch();
	thread_draw.launch();
}