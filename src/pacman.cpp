#include "pacman.h"
Pacman::Pacman(float x,float y,Rotation rot):Creature(x,y,rot){}

Pacman::~Pacman(){}

void Pacman::Draw(){
	int x,y;
	glBegin(GL_LINES);
	glColor3f(m_col.r,m_col.g,m_col.b);
	for(int k = 0;k < 32;k++){
		x = (int)k / 2.0 * cos((30 + 90*m_rotation) * M_PI / 180.0) + ((1.5+m_pos.x) * squareSize);
		y = (int)k / 2.0 * sin((30 + 90*m_rotation)*M_PI / 180.0) + ((1.5+m_pos.y) * squareSize);
		for(int i = 30;i < 330;++i){
			glVertex2f(x,y);
			x = (int)k / 2.0 * cos((i + 90 * m_rotation) * M_PI / 180.0) + ((1.5+m_pos.x) * squareSize);
			y = (int)k / 2.0 * sin((i + 90 * m_rotation) * M_PI / 180.0) + ((1.5+m_pos.y) * squareSize);
			glVertex2f(x,y);
			}
		}
	glEnd();
	}
