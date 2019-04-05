#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <GL/gl.h>
#include "structs.h"
class GameMap{
	public:
		GameMap();
		~GameMap();
		void Init();
		void DrawMap();
		void Update();
		
	public:
		vector<int> m_border;			//墙
		vector<int> m_obstaclesTop;		//上障碍物
		vector<int> m_obstaclesMiddle;	//中障碍物
		vector<int> m_obstaclesBottom;	//下障碍物
		vector<vector<bool>> m_bitmap;	//可移动区域
	};

#endif
