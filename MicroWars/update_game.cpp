#include "play.h"

void update_game(GameEssentials &G)
{
	Clock timer;
	Time wait_time = seconds(10000000);

	while (true)
	{
		for(int i = 0; i<G.ORB_COUNT; i++)
		{
			if(G.ORB_VECTOR[i].return_orb_colour() == G.PLAYER_COLOUR)
			{
				for(int j = 0; j<G.ORB_VECTOR[i].orb_units.size(); j++)
				{
					if(G.ORB_VECTOR[i].orb_units[j].return_selection_status())
					{
						if(G.ORB_VECTOR[i].orb_units[j].move())
						{
							for(int k = 0; k<G.ORB_COUNT; k++)
							{
								if(G.ORB_VECTOR[k].check_unit_vicinity(G.ORB_VECTOR[i].orb_units[j].return_unit_pos('x'), G.ORB_VECTOR[i].orb_units[j].return_unit_pos('y')))
								{
									G.ORB_VECTOR[k].change_health(G.ORB_VECTOR[i].orb_units[j].return_unit_colour());
									if(G.ORB_VECTOR[k].return_orb_colour() != G.ORB_VECTOR[i].orb_units[j].return_unit_colour() || (G.ORB_VECTOR[k].return_orb_colour() == G.ORB_VECTOR[i].orb_units[j].return_unit_colour() && G.ORB_VECTOR[k].return_health()<(100*G.ORB_VECTOR[k].return_max_power())))
									{
										G.ORB_VECTOR[i].orb_units[j].~Unit();
										G.ORB_VECTOR[i].orb_units.erase(G.ORB_VECTOR[i].orb_units.begin()+j);
									}
								}
							}
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
				G.ORB_VECTOR[i].produce_unit();
			}
		}
	}
}
