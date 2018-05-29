#include <vector>
using namespace std;
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
		float tesla_x_factor;

		public:
		
		Tesla(float x, float y, float radius, float x_factor);
		vector < int* > deleted_units;
		float return_tesla_pos(char option);
		int check_unit_vicinity(float x, float y);
		void change_health();
		int return_health();
		float return_x_factor();

		~Tesla();
	};

}

#endif // TESLA_H