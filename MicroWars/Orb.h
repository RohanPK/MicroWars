#include "Unit.h"

#ifndef ORB_H
#define ORB_H

namespace microwars
{
	class Orb
	{
		private:
		
		float orb_pos_x, orb_pos_y;
		float orb_radius;
		char orb_colour;
		char orb_residual_health_colour;
		int orb_health;
		int orb_power;
		int orb_max_power;

		public:
		
		Orb(float x, float y, float radius, char colour, int power, int no_of_units, int initial_health);
		Unit produce_unit();
		float return_orb_pos(char option);
		char return_orb_colour();
		int check_unit_vicinity(float x, float y);
		void change_health(char colour);
		int return_health();
		int return_power();
		int return_max_power();
		int return_colour_index();

		~Orb();
	};

}

#endif // ORB_H