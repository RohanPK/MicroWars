#include <vector>
#include "Unit.h"

#ifndef ORB_H
#define ORB_H

namespace microwars
{
	class Orb
	{
		public:
		
		std::vector<microwars::Unit> orb_units;
		
		private:
		
		float orb_pos_x, orb_pos_y;
		float orb_radius;
		char orb_colour;
		int orb_ID;
		char orb_residual_health_colour;
		int orb_health;
		int orb_power;
		int orb_no_of_units;

		public:
		
		Orb(float x, float y, float radius, char colour, int ID, int power, int no_of_units);
		void produce_unit();
		float return_current_pos(char option);
		float return_orb_pos(char option);
		char return_orb_colour();
		int change_health(char colour);
		int return_ID();
		~Orb();
	};
}

#endif // ORB_H