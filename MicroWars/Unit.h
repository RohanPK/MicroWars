#ifndef UNIT_H
#define UNIT_H

namespace microwars
{
	class Unit
	{
		private:
		
		float unit_pos_x, unit_pos_y;
		char unit_colour;
		int unit_ID;
		float unit_speed;
		float unit_speed_slope;
		float unit_speed_x, unit_speed_y;
		
		public:
		
		Unit(float x, float y, char colour, int ID, float speed);
		float return_current_pos(char option);
		int move(float final_x, float final_y);
		float return_unit_pos(char option);
		char return_unit_colour();
		int return_ID();
		~Unit();
	};
}

#endif // UNIT_H