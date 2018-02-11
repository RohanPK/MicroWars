#include <vector>
#include "Unit.h"
#ifndef ORB_H
#define ORB_H

namespace microwars
{

class Orb
{
public:
	std::vector<unit::Unit> orb_units;
private:
	float orb_pos_x, orb_pos_y;
	char orb_colour;
	int orb_ID;
	int orb_health;
	int orb_power;
	int orb_no_of_units;

public:
	Orb(float x, float y, char colour, int ID, int health, int no_of_units);
	void produce_unit();
	void change_colour();
	float return_current_pos(char option);
	float return_orb_pos(char option);
	char return_orb_colour();
	int return_ID();
	~Orb();
	

};

}

#endif // ORB_H
