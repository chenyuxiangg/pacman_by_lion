#ifndef MONSTER_H
#define MONSTER_H
#include "creature.h"
class Monster:public Creature{
	public:
		Monster(float x = 0.0,float y = 0.0,Rotation rot = DEFAULT);
		virtual ~Monster();
		virtual void Draw();
	};

#endif
