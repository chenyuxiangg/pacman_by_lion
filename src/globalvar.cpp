#include "pacman.h"
#include "gamemap.h"
#include "food.h"
#include "monster.h"
#include "structs.h"

Pacman*		g_pacman = new Pacman();
GameMap*	g_map = new GameMap();
Food*		g_food = new Food();
vector<Monster*> g_monsters = {(new Monster(10.5,8.5,UP)),(new Monster(13.5,1.5,RIGHT)),(new Monster(4.5,6.5,DOWN)),(new Monster(2.5,13.5,LEFT))};
int g_points = 0;
const float squareSize = 50.0;


