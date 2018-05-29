#ifndef UNIT_H
#define UNIT_H

namespace microwars
{
	class Unit
	{
		private:
		
		float unit_pos_x, unit_pos_y;
		float unit_radius;
		char unit_colour;
		float unit_speed;
		float unit_speed_slope;
		float unit_speed_x, unit_speed_y;
		bool unit_selected;
		float unit_destination_x, unit_destination_y;
		
		public:
		
		Unit(float x, float y, float radius, char colour, float speed);
		float return_unit_pos(char option);
		void set_unit_destination(float final_x, float final_y);
		int move();
		int check_unit_vicinity(float x, float y);
		bool return_selection_status();
		char return_unit_colour();
		int return_colour_index();
		~Unit();
	};
}

#endif // UNIT_H