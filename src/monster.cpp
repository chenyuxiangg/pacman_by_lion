#include "monster.h"
Monster::Monster(float x,float y,Rotation rot):Creature(x,y,rot){}

Monster::~Monster(){}

void Monster::Draw(){
	int x,y;
	glBegin(GL_LINES);
	glColor3f(m_col.r,m_col.g,m_col.b);
	//画头
	for(int k = 0;k < 32;++k){
		x = (int)k / 2.0 * cos(360 * M_PI / 180.0) + (m_pos.x*squareSize);
		y = (int)k / 2.0 * sin(360 * M_PI / 180.0) + (m_pos.y*squareSize);
		for(int i = 180;i <= 360;++i){
			glVertex2f(x,y);
			x = (int)k/2.0 * cos(i*M_PI/180.0) + (m_pos.x*squareSize);
			y = (int)k/2.0 * sin(i*M_PI/180.0) + (m_pos.y*squareSize);
			glVertex2f(x,y);
			}
		}
	glEnd();
	//身体
	glRectf((m_pos.x*squareSize)-17,m_pos.y*squareSize,(m_pos.x*squareSize)+15,(m_pos.y*squareSize)+15);
	glBegin(GL_POINTS);
	glColor3f(0,0.2,0.4);
	//眼睛和腿
	glVertex2f((m_pos.x*squareSize)-11,(m_pos.y*squareSize)+14);
	glVertex2f((m_pos.x*squareSize)-1,(m_pos.y*squareSize)+14);
	glVertex2f((m_pos.x*squareSize)+8,(m_pos.y*squareSize)+14);
	glVertex2f((m_pos.x*squareSize)+4,(m_pos.y*squareSize)-3);
	glVertex2f((m_pos.x*squareSize)-7,(m_pos.y*squareSize)-3);
	glEnd();
	}
