#ifndef STRUCTS_H
#define STRUCTS_H
#include <vector>
#include <deque>
#include <string>
#include <math.h>
using namespace std;
//点
typedef struct POINT{
	float x;
	float y;
	POINT(float xx = 0.0,float yy = 0.0){x = xx;y = yy;}
	}Point;

//方向枚举
enum Rotation{RIGHT,DOWN,LEFT,UP,DEFAULT};

//颜色结构
typedef struct COLOR{
	float r;
	float g;
	float b;
	float a;
	COLOR(float rr = 1.0,float gg = 1.0,float bb = 1.0,float aa = 1.0){
		r = rr; g = gg; b = bb; a = aa;
		}
	}Color;
#endif
