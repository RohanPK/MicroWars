#include "Orb.h"
#include <iostream>
#define orb_radius 5 

microwars::Orb::Orb(float var_x, float var_y, char var_colour, int var_ID, int var_health, int var_no_of_units)
{

	orb_pos_x = var_x;
	orb_pos_y = var_y;
	orb_colour=var_colour;
	orb_ID = var_ID;
	orb_health = var_health;
	orb_no_of_units = var_no_of_units;
	orb_power = 1;
	produce_unit();
	produce_unit();
	produce_unit();
}

void microwars::Orb::produce_unit()

{	
	for(int count=0; count<orb_power; count++)
	{
		unit::Unit var_unit(orb_pos_x, orb_pos_y, orb_colour, orb_ID, 0.1);
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

/*void microwars::Orb::change_colour()
{
	if(orb_colour=='X' && orb_health<=-100)
	{
		orb_colour=;
	}
}
*/
microwars::Orb::~Orb()
{
}

