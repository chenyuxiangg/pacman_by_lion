#ifndef PACMAN_H
#define PACMAN_H
#include "creature.h"
class Pacman:public Creature{
	public:
		Pacman(float x = 0.0,float y = 0.0,Rotation rot = DEFAULT);
		virtual ~Pacman();
		virtual void Draw();
	};

#endif
