#include "creature.h"
Creature::Creature(float x,float y,Rotation rot):m_rotation(rot),
m_col(Color(1.0,1.0,1.0)){
	m_pos.x = x;
	m_pos.y = y;
	}

Creature::~Creature(){}

Color Creature::SetColor(const Color& col){
	Color old = m_col;
	m_col = col;
	return old;
	}

Point Creature::UpdatePos(const Point& pos){
	Point old = m_pos;
	m_pos = pos;
	return old;
	}

Rotation Creature::UpdateRot(const Rotation& rot){
	Rotation old = m_rotation;
	m_rotation = rot;
	return old;
	}

Point& Creature::GetCurrentPos(){
	return m_pos;
	}

Rotation& Creature::GetCurrentRot(){
	return m_rotation;
	}

Color Creature::GetColor(){
	return m_col;
	}
