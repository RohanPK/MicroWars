#include "Orb.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define UNIT_SPEED 0.2
#define UNIT_RADIUS 4
#define ORB_RADIUS 30
#define EPSILON 40

microwars::Orb::Orb(float x, float y, float radius, char colour, int ID, int power, int no_of_units, int initial_health)
{
	orb_pos_x = x;
	orb_pos_y = y;
	orb_radius = radius;
	orb_colour = colour;
	orb_ID = ID;
	orb_power = power;
	orb_residual_health_colour = 'X';
	orb_no_of_units = no_of_units;
	orb_health = initial_health;
}

void microwars::Orb::produce_unit()
{	
	for(int count = 0; count<(orb_health/orb_no_of_units); count++)
	{
		float randomising_x = ((rand()%5000) - 2500.0)/(100.0);
		float randomising_y = ((rand()%5000) - 2500.0)/(100.0);
		microwars::Unit new_unit(orb_pos_x + randomising_x, orb_pos_y + randomising_y, UNIT_RADIUS, orb_colour, count, UNIT_SPEED);
		orb_units.push_back(new_unit);
	}
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

int microwars::Orb::return_ID()
{
	return orb_ID;
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
	if(colour == orb_residual_health_colour || colour == orb_colour)
	{
		if(orb_health < 100*orb_power)
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
	std::cout<<"Blue Health"<<orb_health<<"\n";
}

int microwars::Orb::return_health()
{
	return orb_health;
}

int microwars::Orb::return_power()
{
	return orb_power;
}


microwars::Orb::~Orb()
{
}