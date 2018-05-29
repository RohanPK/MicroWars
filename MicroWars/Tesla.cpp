#include "Tesla.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define TESLA_RADIUS 50
#define EPSILON 60

microwars::Tesla::Tesla(float x, float y, float radius, float x_factor)
{
	tesla_pos_x = x;
	tesla_pos_y = y;
	tesla_radius = radius;
	tesla_health = 0;
	tesla_x_factor = x_factor;
}

float microwars::Tesla::return_tesla_pos(char option)
{
	if(option == 'x')
	{
		return tesla_pos_x;
	}
	else if(option == 'y')
	{
		return tesla_pos_y;
	}
}
		
int microwars::Tesla::check_unit_vicinity(float x, float y)
{
	if(fabs(tesla_pos_x - x)<=EPSILON && fabs(tesla_pos_y - y)<=EPSILON)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void microwars::Tesla::change_health()
{
	if(tesla_health<100)
	{
		tesla_health++;
	}
	else
	{
		tesla_health = 0;
	}
}

int microwars::Tesla::return_health()
{
	return tesla_health;
}
		
float microwars::Tesla::return_x_factor()
{
	return tesla_x_factor;
}

microwars::Tesla::~Tesla()
{
}