#include "play.h"

void update_game(GameEssentials &G)
{
	Clock timer;
	Time wait_time = seconds(1);
	
	while (true)
	{
		//ORB-UNIT INTERACTION
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
									G.PLAYER_STATS[i].Losses++;
									G.PLAYER_STATS[i].Present_Units--;
									G.UNIT_VECTOR[i].erase(G.UNIT_VECTOR[i].begin()+j);
								}
							}
						}
					}
				}
			}
		}
		
		//TESLA-UNIT INTERACTION
		for(int i = 0; i<G.PLAYER_COUNT; i++)
		{
			for(int j = 0; j<G.UNIT_VECTOR[i].size(); j++)
			{
				if(G.UNIT_VECTOR[i][j].return_selection_status())
				{
					if(G.UNIT_VECTOR[i][j].move())
					{
						for(int k = 0; k<G.TESLA_COUNT; k++)
						{
							if(G.TESLA_VECTOR[k].check_unit_vicinity(G.UNIT_VECTOR[i][j].return_unit_pos('x'), G.UNIT_VECTOR[i][j].return_unit_pos('y')))
							{
								G.TESLA_VECTOR[k].change_health();
								G.UNIT_VECTOR[i][j].~Unit();
								G.PLAYER_STATS[i].Losses++;
								G.PLAYER_STATS[i].Present_Units--;
								G.UNIT_VECTOR[i].erase(G.UNIT_VECTOR[i].begin()+j);
								if(G.TESLA_VECTOR[k].return_health() == 100)
								{
									int temp = 0;
									for(int l = 1; l<G.PLAYER_COUNT; l++)
									{
										if(G.PLAYER_STATS[l].Present_Units > G.PLAYER_STATS[temp].Present_Units)
										{
											temp = l;
										}
									}
									for(int l = 0; l<G.TESLA_VECTOR[k].return_x_factor()*100; l++)
									{
										int rand_unit;
										rand_unit = rand()%G.PLAYER_STATS[temp].Present_Units;
										G.UNIT_VECTOR[temp][rand_unit].~Unit();
										G.PLAYER_STATS[temp].Losses++;
										G.PLAYER_STATS[temp].Present_Units--;
										G.UNIT_VECTOR[temp].erase(G.UNIT_VECTOR[temp].begin()+rand_unit);
									}
								}
							}
						}
					}
				}
			}
		}
		
		//UNIT-UNIT INTERACTION
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
							G.PLAYER_STATS[j].Losses++;
							G.PLAYER_STATS[j].Present_Units--;
							G.UNIT_VECTOR[j].erase(G.UNIT_VECTOR[j].begin()+l);
							G.UNIT_VECTOR[k][m].~Unit();
							G.PLAYER_STATS[k].Losses++;
							G.PLAYER_STATS[k].Present_Units--;
							G.UNIT_VECTOR[k].erase(G.UNIT_VECTOR[k].begin()+m);
						}
					}
				}
			}
		}
		
		//UNIT PRODUCTION
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
						G.PLAYER_STATS[G.ORB_VECTOR[i].return_colour_index()].Present_Units+=G.ORB_VECTOR[i].return_power();
					}
				}
			}
		}
	}
}
