#include "Unit.h"
#include <math.h>

#define EPSILON 0.2

int factor(float a, float b)
{
	if(a > b)
	{
		return 1;
	}
	else if(a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

microwars::Unit::Unit(float x, float y, char colour, int ID, float speed)
{
	unit_pos_x = x;
	unit_pos_y = y;
	unit_speed_x = 0;
	unit_speed_y = 0;
	unit_colour = colour;
	unit_ID = ID;
	unit_speed = speed;
}

float microwars::Unit::return_unit_pos(char option)
{
	if(option == 'x')
	{
		return unit_pos_x;
	}
	else if(option == 'y')
	{
		return unit_pos_y;
	}
}

char microwars::Unit::return_unit_colour()
{
	return unit_colour;
}

int microwars::Unit::return_ID()
{
	return unit_ID;
}

int microwars::Unit::move(float final_x, float final_y)
{
	if(fabs(final_x - unit_pos_x)<=EPSILON && fabs(final_y - unit_pos_y)<=EPSILON)
	{
		unit_speed_x = 0;
		unit_speed_y = 0;
		unit_pos_x = final_x;
		unit_pos_y = final_y;
		return 0;
	}
	else
	{
		unit_speed_slope = (final_y - unit_pos_y)/(final_x - unit_pos_x);
		unit_speed_x = ((unit_speed)*factor(final_x, unit_pos_x))/sqrtf(1.0 + (unit_speed_slope*unit_speed_slope));
		unit_speed_y = ((unit_speed_x)*(unit_speed_slope));
		unit_pos_x += unit_speed_x;
		unit_pos_y += unit_speed_y;
		return 1;
	}
}

microwars::Unit::~Unit()
{
	
}