#ifndef GLOBAL_H
#define GLOBAL_H
#include <GL/glut.h>
#include "pacman.h"
#include "monster.h"
#include "gamemap.h"
#include "food.h"
#include "structs.h"
#include "const_var.h"

extern Pacman* 				g_pacman;
extern vector<Monster*> 	g_monsters;
extern GameMap* 			g_map;
extern Food* 				g_food;
extern int					g_points;

//初始化全局变量
void InitGlobal();

//初始化窗口及GL
void InitWindow(int* argc,char* argv[]);

//重置全局变量
void ResetGlobal();

//清理全局变量
void CleanUp();
#endif
