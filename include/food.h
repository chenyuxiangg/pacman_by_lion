#ifndef FOOD_H
#define FOOD_H
#include <GL/gl.h>
#include "structs.h"
class Food{
	public:
		Food();
		~Food();
		void Init();
		bool FoodEaten(const float& x,const float& y,const float& pacx,const float& pacy);
		void DrawFood(const float& pacx,const float& pacy);

	private:
		deque<float> m_food;
	};

#endif
