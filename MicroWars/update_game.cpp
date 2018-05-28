#include "play.h"

void update_game(GameEssentials &G)
{
	Clock timer;
	Time wait_time = seconds(1);
	
	while (true)
	{
		for(int i = 0; i<G.PLAYER_COUNT; i++)
		{
			for(int j = 0; j<G.UNIT_VECTOR[i].size(); j++)
			{
				if(G.UNIT_VECTOR[i][j].return_selection_status())
				{
					if(G.UNIT_VECTOR[i][j].move())
					{
						for(int k = 0; k<G.ORB_COUNT; k++)
						{
							if(G.ORB_VECTOR[k].check_unit_vicinity(G.UNIT_VECTOR[i][j].return_unit_pos('x'), G.UNIT_VECTOR[i][j].return_unit_pos('y')))
							{
								G.ORB_VECTOR[k].change_health(G.UNIT_VECTOR[i][j].return_unit_colour());
								if(G.ORB_VECTOR[k].return_orb_colour() != G.UNIT_VECTOR[i][j].return_unit_colour() || (G.ORB_VECTOR[k].return_orb_colour() == G.UNIT_VECTOR[i][j].return_unit_colour() && G.ORB_VECTOR[k].return_health()<(100*G.ORB_VECTOR[k].return_max_power())))
								{
									G.UNIT_VECTOR[i][j].~Unit();
									G.ORB_STATS[i].Orb_Losses++;
									G.ORB_STATS[i].Orb_Present_Units--;
									G.UNIT_VECTOR[i].erase(G.UNIT_VECTOR[i].begin()+j);
								}
							}
						}
					}
				}
			}
		}

		for(int j = 0; j<G.PLAYER_COUNT; j++)
		{
			for(int k = j+1; k<G.PLAYER_COUNT; k++)
			{
				for(int l = 0; l<G.UNIT_VECTOR[j].size(); l++)
				{
					for(int m = 0; m<G.UNIT_VECTOR[k].size(); m++)
					{
						if(G.UNIT_VECTOR[j][l].check_unit_vicinity(G.UNIT_VECTOR[k][m].return_unit_pos('x'), G.UNIT_VECTOR[k][m].return_unit_pos('y')))
						{
							G.UNIT_VECTOR[j][l].~Unit();
							G.ORB_STATS[j].Orb_Losses++;
							G.ORB_STATS[j].Orb_Present_Units--;
							G.UNIT_VECTOR[j].erase(G.UNIT_VECTOR[j].begin()+l);
							G.UNIT_VECTOR[k][m].~Unit();
							G.ORB_STATS[k].Orb_Losses++;
							G.ORB_STATS[k].Orb_Present_Units--;
							G.UNIT_VECTOR[k].erase(G.UNIT_VECTOR[k].begin()+m);
						}
					}
				}
			}
		}

		if(timer.getElapsedTime().asSeconds()>= wait_time.asSeconds())
		{
			timer.restart();
			for (int i=0;i<G.ORB_COUNT;i++)
			{
				if(G.ORB_VECTOR[i].return_orb_colour()!='X')
				{
					for(int j=0;j<G.ORB_VECTOR[i].return_power();j++)
					{
						G.UNIT_VECTOR[G.ORB_VECTOR[i].return_colour_index()].push_back(G.ORB_VECTOR[i].produce_unit());
						G.ORB_STATS[G.ORB_VECTOR[i].return_colour_index()].Orb_Present_Units+=G.ORB_VECTOR[i].return_power();
					}
				}
			}
		}
	}
}
