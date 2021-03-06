#include "play.h"

void update_game(GameEssentials &G)
{
	Clock timer_produce_units;
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
								if(G.ORB_VECTOR[k].return_orb_colour() == G.UNIT_VECTOR[i][j].return_unit_colour() && G.ORB_VECTOR[k].return_health() == (100*G.ORB_VECTOR[k].return_max_power() - 1))
								{
									G.UNIT_VECTOR[i][j].~Unit();
									G.PLAYER_STATS[i].Losses++;
									G.UNIT_VECTOR[i].erase(G.UNIT_VECTOR[i].begin()+j);
								}
								G.ORB_VECTOR[k].change_health(G.UNIT_VECTOR[i][j].return_unit_colour());
								if(G.ORB_VECTOR[k].return_orb_colour() != G.UNIT_VECTOR[i][j].return_unit_colour() || (G.ORB_VECTOR[k].return_orb_colour() == G.UNIT_VECTOR[i][j].return_unit_colour() && G.ORB_VECTOR[k].return_health()<(100*G.ORB_VECTOR[k].return_max_power())))
								{
									G.UNIT_VECTOR[i][j].~Unit();
									G.PLAYER_STATS[i].Losses++;
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
									for(int l = 0; l<G.TESLA_VECTOR[k].return_x_factor(); l++)
									{
										if(G.UNIT_VECTOR[temp].size() != 0)
										{
											int rand_unit;
											rand_unit = rand()%G.UNIT_VECTOR[temp].size();
											int temp_array[2];
											temp_array[0]=G.UNIT_VECTOR[temp][rand_unit].return_unit_pos('x');
											temp_array[1]=G.UNIT_VECTOR[temp][rand_unit].return_unit_pos('y');
											vector <sfLine> line_temp;
											int randomising_x = ((rand()%5000) - 2500)/(20);
											int randomising_y = ((rand()%5000) - 2500)/(20);
											int rand_x=(G.TESLA_COORDINATES[k][0]+temp_array[0])/2 + randomising_x;
											int rand_y=(G.TESLA_COORDINATES[k][1]+temp_array[1])/2 + randomising_y;
											line_temp.push_back(sfLine(Vector2f(G.TESLA_COORDINATES[k][0],G.TESLA_COORDINATES[k][1]),Vector2f(rand_x,rand_y)));
											line_temp.push_back(sfLine(Vector2f(rand_x,rand_y),Vector2f(temp_array[0],temp_array[1])));
											G.LINE_VECTOR.push_back(line_temp);
											G.UNIT_VECTOR[temp][rand_unit].~Unit();
											G.PLAYER_STATS[temp].Losses++;
											G.UNIT_VECTOR[temp].erase(G.UNIT_VECTOR[temp].begin()+rand_unit);
										}
									}
									G.TESLA_VECTOR[k].change_health();
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
							G.UNIT_VECTOR[j].erase(G.UNIT_VECTOR[j].begin()+l);
							G.UNIT_VECTOR[k][m].~Unit();
							G.PLAYER_STATS[k].Losses++;
							G.UNIT_VECTOR[k].erase(G.UNIT_VECTOR[k].begin()+m);
						}
					}
				}
			}
		}
		
		//PRODUCTION-RATE SUM
		for(int i = 0; i<G.PLAYER_COUNT; i++)
		{
			G.PLAYER_STATS[i].Produce_Rate = 0;
		}
		for (int i=0;i<G.ORB_COUNT;i++)
		{
			if(G.ORB_VECTOR[i].return_orb_colour()!='X')
			{
				G.PLAYER_STATS[G.ORB_VECTOR[i].return_colour_index()].Produce_Rate+=G.ORB_VECTOR[i].return_power();
			}
		}
		
		//PRESENT-UNITS ASSIGNMENT
		for(int i = 0; i<G.PLAYER_COUNT; i++)
		{
			G.PLAYER_STATS[i].Present_Units = G.UNIT_VECTOR[i].size();
		}
		
		//UNIT PRODUCTION
		if(timer_produce_units.getElapsedTime().asSeconds()>= wait_time.asSeconds())
		{
			timer_produce_units.restart();
			for (int i=0;i<G.ORB_COUNT;i++)
			{
				if(G.ORB_VECTOR[i].return_orb_colour()!='X')
				{
					for(int j=0;j<G.ORB_VECTOR[i].return_power();j++)
					{
						G.UNIT_VECTOR[G.ORB_VECTOR[i].return_colour_index()].push_back(G.ORB_VECTOR[i].produce_unit());
					}
				}
			}
		}
		
	if(G.exit_play)
	{
		break;
	}
	
	sleep(sf::milliseconds(10));
	}
}
