#include "Orb.h"
#include <iostream>

microwars::Orb::Orb(float var_x, float var_y, char var_colour, int var_ID, int var_power, int var_no_of_units)
{
	orb_pos_x = var_x;
	orb_pos_y = var_y;
	orb_colour=var_colour;
	orb_ID = var_ID;
	orb_power = var_power;
	orb_residual_health_colour = 'X';
	orb_no_of_units = var_no_of_units;
	orb_health = orb_no_of_units*orb_power;
	produce_unit();
}

void microwars::Orb::produce_unit()
{	
	for(int count=0; count<orb_power; count++)
	{
		microwars::Unit var_unit(orb_pos_x, orb_pos_y, orb_colour, orb_ID, 0.1);
		orb_units.push_back(var_unit);
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

int microwars::Orb::change_health(char colour)
{
	if(colour == orb_residual_health_colour)
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
	return orb_health;
}

microwars::Orb::~Orb()
{
}
