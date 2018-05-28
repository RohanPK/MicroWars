#ifndef TESLA_H
#define TESLA_H

namespace microwars
{
	class Tesla
	{
		private:
		
		float tesla_pos_x, tesla_pos_y;
		float tesla_radius;
		int tesla_health;
		int tesla_x_factor;

		public:
		
		Tesla(float x, float y, float radius, int x_factor);
		float return_tesla_pos(char option);
		int check_unit_vicinity(float x, float y);
		void change_health();
		int return_health();
		int return_x_factor();

		~Tesla();
	};

}

#endif // TESLA_H