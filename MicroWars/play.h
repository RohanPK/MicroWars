#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Orb.h"
#include "Tesla.h"
#include "Unit.h"

using namespace sf;
using namespace std;
using namespace microwars;

#define G_ORB_COUNT 7
#define G_PLAYER_COUNT 4
#define G_TESLA_COUNT 1

class sfLine : public sf::Drawable
{
public:
    sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2):
        color(sf::Color::White), thickness(2.f)
    {
        sf::Vector2f direction = point2 - point1;
        sf::Vector2f unitDirection = direction/std::sqrt(direction.x*direction.x+direction.y*direction.y);
        sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

        sf::Vector2f offset = (thickness/2.f)*unitPerpendicular;

        vertices[0].position = point1 + offset;
        vertices[1].position = point2 + offset;
        vertices[2].position = point2 - offset;
        vertices[3].position = point1 - offset;

        for (int i=0; i<4; ++i)
            vertices[i].color = color;
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(vertices,4,sf::Quads);
    }


public:
    sf::Vertex vertices[4];
    float thickness;
    sf::Color color;
};

struct Statistics
{
	int Present_Units;
	int Losses;
	int Produce_Rate;
};

struct GameEssentials
{
	int ORB_COUNT;
	int ORB_RADIUS;
	
	int TESLA_COUNT;
	int TESLA_RADIUS;
	
	int UNIT_RADIUS;
	
	int PLAYER_COUNT;
	
	char PLAYER_COLOUR;
	
	char ORB_COLOUR[G_ORB_COUNT];
	float ORB_COORDINATES[G_ORB_COUNT][2];
	int ORB_INITIAL_UNITS[G_ORB_COUNT];
	int ORB_INITIAL_POWER[G_ORB_COUNT];
	int ORB_MAX_POWER[G_ORB_COUNT];
	
	float TESLA_COORDINATES[G_TESLA_COUNT][2];
	float TESLA_X_FACTOR[G_TESLA_COUNT];
	
	Statistics PLAYER_STATS[G_PLAYER_COUNT];
	
	vector <Orb> ORB_VECTOR;
	vector <Unit> UNIT_VECTOR[G_PLAYER_COUNT];
	vector <Tesla> TESLA_VECTOR;
	vector < vector <sfLine> > LINE_VECTOR;
	RenderWindow *window;
	
	bool start_play;
	bool exit_play;
};

void init_window();

int main_menu(RenderWindow &window);

void init_game(RenderWindow &window, bool &start_play);

int draw_game(GameEssentials &G);

void update_game(GameEssentials &G);