#include "Orb.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define UNIT_SPEED 0.2
#define UNIT_RADIUS 4
#define ORB_RADIUS 30
#define EPSILON 40

microwars::Orb::Orb(float x, float y, float radius, char colour, int power, int max_power, int initial_health)
{
	orb_pos_x = x;
	orb_pos_y = y;
	orb_radius = radius;
	orb_colour = colour;
	orb_power = power;
	orb_residual_health_colour = 'X';
	orb_max_power = max_power;
	orb_health = initial_health;
}

microwars::Unit microwars::Orb::produce_unit()
{

	float randomising_x = ((rand()%5000) - 2500.0)/(100.0);
	float randomising_y = ((rand()%5000) - 2500.0)/(100.0);
	microwars::Unit new_unit(orb_pos_x + randomising_x, orb_pos_y + randomising_y, UNIT_RADIUS, orb_colour, UNIT_SPEED);
	return new_unit;

}

float microwars::Orb::return_orb_pos(char option)
{
	if(option == 'x')
	{
		return orb_pos_x;
	}
	else if(option == 'y')
	{
		return orb_pos_y;
	}
}

char microwars::Orb::return_orb_colour()
{
	return orb_colour;
}

int microwars::Orb::check_unit_vicinity(float x, float y)
{
	if(fabs(orb_pos_x - x)<=EPSILON && fabs(orb_pos_y - y)<=EPSILON)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void microwars::Orb::change_health(char colour)
{
	if(colour == orb_colour)
	{
		if(orb_health < 100*orb_max_power)
		{
			orb_health++;
		}
	}
	else if(colour == orb_residual_health_colour)
	{
		if(orb_health < 100)
		{
			orb_health++;
		}
		else
		{
			orb_colour = colour;
		}
	}
	else if(orb_colour == 'X')
	{
		if(colour == orb_residual_health_colour || orb_residual_health_colour == 'X')
		{
			orb_residual_health_colour = colour;
			orb_health++;
		}
	}
	else
	{
		if(orb_health > 0)
		{
			orb_health--;
		}
		else
		{
			orb_colour = 'X';
			orb_residual_health_colour = 'X';
		}
	}
	orb_power = (orb_health/100) ;
	if(orb_health<100 && orb_colour!= 'X')
	{
		orb_power = 1;
	}
}

int microwars::Orb::return_health()
{
	return orb_health;
}

int microwars::Orb::return_power()
{
	return orb_power;
}

int microwars::Orb::return_max_power()
{
	return orb_max_power;
}

int microwars::Orb::return_colour_index()
{
	if( orb_colour == 'B')
	{
		return 0;
	}
	if( orb_colour == 'G')
	{
		return 1;
	}
	if( orb_colour == 'R')
	{
		return 2;
	}
	if( orb_colour == 'Y')
	{
		return 3;
	}
	if( orb_colour == 'X')
	{
		return 4;
	}
}

microwars::Orb::~Orb()
{
}