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
						G_ORB_COUNT,                          //Total Orbs
						30,                                   //Orb Radius
						G_TESLA_COUNT,                        //Tesla Count
						50,                                   //Tesla Radius
						4,                                    //Unit Radius
						G_PLAYER_COUNT,                       //Number of unique colours
						'Y',                                  //Player Colour
						{'B', 'G', 'Y', 'Y', 'X', 'R', 'R'},  //Player Colour Array
						{{100, 200}, {178, 340}, {900, 250}, {660, 580}, {800, 820}, {260,400},{750,950}},    //Orb Co-ordinates
						{100, 20, 160, 100, 10, 0, 10},       //Initial Units
						{1, 1, 2, 1, 1, 0, 1},                //Initial Power
						{3, 2, 3, 3, 2, 2, 2},                //Max Power
						{{800, 240}},                         //Array of Tesla Co-ordinates
						{1.5},                                //Tesla X factor
						{{100, 0, 1}, {0, 0, 0}, {10, 0, 1}, {260, 0, 3}}                                      //Initial Stats
						};

	G.start_play = start_play;                                //Start_Play is used to ignore the first click when play is clicked
	G.window = &window;
	
	Thread thread_draw(&draw_game, (std::ref)(G));
	Thread thread_logic(&update_game, (std::ref)(G));
	
	initialise(G);
	
	thread_logic.launch();
	thread_draw.launch();
}