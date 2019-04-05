#ifndef CREATURE_H
#define CREATURE_H
#include <GL/gl.h>
#include "structs.h"
#include "const_var.h"
class Creature{
	public:
		Creature(float x = 0.0,float y = 0.0,Rotation rot = DEFAULT);
		virtual ~Creature();
		virtual void Draw() = 0;
		Point& GetCurrentPos();
		Rotation& GetCurrentRot();
		Color GetColor();
		Color SetColor(const Color& col);
		Point UpdatePos(const Point& pos);
		Rotation UpdateRot(const Rotation& rot);

	protected:
		Point m_pos;
		Rotation m_rotation;
		Color m_col;
	};
#endif
