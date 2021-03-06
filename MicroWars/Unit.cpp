#include "Unit.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define EPSILON 10

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

microwars::Unit::Unit(float x, float y, float radius, char colour, float speed)
{
	unit_pos_x = x;
	unit_pos_y = y;
	unit_radius = radius;
	unit_speed_x = 0;
	unit_speed_y = 0;
	unit_colour = colour;
	unit_speed = speed;
	unit_selected = false;
	unit_destination_x = x;
	unit_destination_y = y;
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

void microwars::Unit::set_unit_destination(float final_x, float final_y)
{
	unit_selected = true;
	float randomising_x = ((float)(rand()%5000) - 2500.0)/(250.0);
	float randomising_y = ((float)(rand()%5000) - 2500.0)/(250.0);
	unit_destination_x = final_x + randomising_x;
	unit_destination_y = final_y + randomising_y;
}

int microwars::Unit::move()
{
	if(fabs(unit_destination_x - unit_pos_x)<=EPSILON && fabs(unit_destination_y - unit_pos_y)<=EPSILON)
	{
		unit_speed_x = 0;
		unit_speed_y = 0;
		unit_pos_x = unit_destination_x;
		unit_pos_y = unit_destination_y;
		unit_selected = false;
		return 1;
	}
	else
	{
		unit_speed_slope = (unit_destination_y - unit_pos_y)/(unit_destination_x - unit_pos_x);
		unit_speed_x = ((unit_speed)*factor(unit_destination_x, unit_pos_x))/sqrtf(1.0 + (unit_speed_slope*unit_speed_slope));
		unit_speed_y = ((unit_speed_x)*(unit_speed_slope));
		unit_pos_x += unit_speed_x;
		unit_pos_y += unit_speed_y;
		return 0;
	}
}

int microwars::Unit::check_unit_vicinity(float x, float y)
{
	if(fabs(unit_pos_x - x)<=EPSILON && fabs(unit_pos_y - y)<=EPSILON)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool microwars::Unit::return_selection_status()
{
	return unit_selected;
}

char microwars::Unit::return_unit_colour()
{
	return unit_colour;
}

int microwars::Unit::return_colour_index()
{
	switch(unit_colour)
	{
		case 'B':
		{
			return 0;
		}
		case 'G':
		{
			return 1;
		}
		case 'R':
		{
			return 2;
		}
		case 'Y':
		{
			return 3;
		}
		default:
		{
			break;
		}
	}
}
microwars::Unit::~Unit()
{
}