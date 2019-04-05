#include "global.h"

void InitGlobal(){
	g_pacman = new Pacman();
	g_map = new GameMap();
	g_food = new Food();
	g_monsters[0] = new Monster(10.5,8.5,UP);
	g_monsters[1] = new Monster(13.5,1.5,RIGHT);
	g_monsters[2] = new Monster(4.5,6.5,DOWN);
	g_monsters[3] = new Monster(2.5,13.5,LEFT);
	g_points = 0;
	}

void CleanUp(){
	if(g_pacman){
		delete g_pacman;
		g_pacman = nullptr;
		}

	if(g_map){
		delete g_map;
		g_map = nullptr;
		}

	if(g_food){
		delete g_food;
		g_food = nullptr;
		}

	for(int i = 0;i < g_monsters.size();++i){
		if(g_monsters[i]){
			delete g_monsters[i];
			g_monsters[i] = nullptr;
			}
		}
	g_points = 0;
	}

void ResetGlobal(){
	CleanUp();
	InitGlobal();
	}

void InitWindow(int* argc,char* argv[]){
	glutInit(argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(750,750);
	glutInitWindowPosition(500,50);
	glutCreateWindow("Pacman - by yuxiang chen");
	}
