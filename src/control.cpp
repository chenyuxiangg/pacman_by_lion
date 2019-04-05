#include "control.h"
#define GLOBAL
#include "global.h"
#include <ctime>

Control* Control::m_instance = nullptr;
Control::Control():m_replay(false),m_over(true){
	Init();
}

Control* Control::GetInstance(){
	if(!m_instance)
		m_instance = new Control();
	return m_instance;
	}

Control::~Control(){
	if(m_instance){
		delete m_instance;
		m_instance = nullptr;
		}
	}

void Control::Init(){
	m_keyStates.assign(256,false);
	}

void Control::Welcome(){
	glClearColor(0, 0.2, 0.4, 1.0);
	string message = "*************************************";
	string::iterator it = message.begin();
	glRasterPos2f(150, 200);
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "Pacman - by Mr.Chen";
	glColor3f(1, 1, 1);
	glRasterPos2f(225, 250);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "*************************************";
	glRasterPos2f(150, 300);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "To control Pacman use A to go right, D to go left, W to go up and S to go down.";
	glRasterPos2f(50, 400);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	message = "To start or restart the game, press the space key.";
	glRasterPos2f(170, 450);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);

	message = "For FeifeiSha by Mr.Chen.";
	glRasterPos2f(260,500);
	it = message.begin();
	while(it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*it++);
	}

void Control::Display(){
	if (g_points == 1){
		m_over = false;
	}
	KeyOperations();
	glClear(GL_COLOR_BUFFER_BIT);//清除颜色缓冲区(当前被激活为写操作的颜色缓存)
	GameOver();
	if (m_replay){
		if (!m_over){
			g_map->DrawMap();
			g_food->DrawFood((1.5 + g_pacman->GetCurrentPos().x) * squareSize, (1.5 + g_pacman->GetCurrentPos().y) * squareSize);
			g_pacman->Draw();
			//怪物移动
			g_monsters[0]->SetColor(Color(0.0,1.0,1.0));
			g_monsters[1]->SetColor(Color(1.0,0.0,0.0));
			g_monsters[2]->SetColor(Color(1.0,0.0,0.6));
			g_monsters[3]->SetColor(Color(1.0,0.3,0.0));
			MoveMonster(g_monsters[0]);
			MoveMonster(g_monsters[1]);
			MoveMonster(g_monsters[2]);
			MoveMonster(g_monsters[3]);
			for(int i = 0;i < g_monsters.size();++i){
				g_monsters[i]->Draw();
			}
		}
		else {
			ResultDisplay();
		}
	}
	else {
		Welcome();
	}
	glutSwapBuffers();
	}

void Control::Reshape(int w,int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 750, 750, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}

void Control::KeyPressed(unsigned char key,int x,int y){
	m_keyStates[key] = true;
	}

void Control::KeyUp(unsigned char key,int x,int y){
	m_keyStates[key] = false;
	}

void Control::KeyOperations(){
	//获得当前位置
	float  x = (1.5 + g_pacman->GetCurrentPos().x) * squareSize;
	float y = (1.5 + g_pacman->GetCurrentPos().y) * squareSize;
	//更新按键
	if (m_keyStates['a']){
		x -= 2;
		int x1Quadrant = (int)((x - 16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		if (!g_map->m_bitmap.at(x1Quadrant).at((int)y/squareSize)){
			g_pacman->GetCurrentPos().x -= 2 / squareSize;
			g_pacman->GetCurrentRot() = LEFT;
		}
	}
	if (m_keyStates['d']){
		x += 2;
		int x2Quadrant = (int)((x + 16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		if (!g_map->m_bitmap.at(x2Quadrant).at((int)y / squareSize)){
			g_pacman->GetCurrentPos().x += 2 / squareSize;
			g_pacman->GetCurrentRot() = RIGHT;
		}
	}
	if (m_keyStates['w']){
		y -= 2;
		int y1Quadrant = (int)((y - 16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		if (!g_map->m_bitmap.at((int)x/squareSize).at(y1Quadrant)){
			g_pacman->GetCurrentPos().y -= 2 / squareSize;
			g_pacman->GetCurrentRot() = UP;
		}
	}
	if (m_keyStates['s']){
		y += 2;
		int y2Quadrant = (int)((y + 16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		if (!g_map->m_bitmap.at((int)x / squareSize).at(y2Quadrant)){
			g_pacman->GetCurrentPos().y += 2 / squareSize;
			g_pacman->GetCurrentRot() = DOWN;
		}
	}
	if (m_keyStates[' ']){
		if (!m_replay && m_over){
			ResetGame();
			m_replay = true;
		}
		else if (m_replay && m_over){
			m_replay = false;
		}
	}
	}

void Control::ResetGame(){
	m_over = false;
	ResetGlobal();
	Init();
	}

void Control::ResultDisplay(){
	if (g_points == 106){
		//胜利
		string message = "*************************************";
		string::iterator it = message.begin();
		glRasterPos2f(170, 250);
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "CONGRATULATIONS, YOU WON! ";
		glColor3f(1, 1, 1);
		glRasterPos2f(200, 300);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "*************************************";
		glRasterPos2f(170, 350);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "To start or restart the game, press the space key.";
		glRasterPos2f(170, 550);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	}else {
		//Lost
		string message = "*************************************";
		string::iterator it = message.begin();
		glRasterPos2f(210, 250);
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "SORRY, YOU LOST ... ";
		glColor3f(1, 1, 1);
		glRasterPos2f(250, 300);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "*************************************";
		glRasterPos2f(210, 350);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "You got: ";
		glRasterPos2f(260, 400);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		string result = to_string(g_points);
		message = (char*)result.c_str();
		glRasterPos2f(350, 400);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = " points!";
		glRasterPos2f(385, 400);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "To start or restart the game, press the space key.";
		glRasterPos2f(170, 550);
		it = message.begin();
		while (it!=message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	}
	}

void Control::GameOver(){
	int pacmanX = (int)(1.5 + g_pacman->GetCurrentPos().x);
	int pacmanY = (int)(1.5 + g_pacman->GetCurrentPos().y);
	int monster1X = (int)(g_monsters[0]->GetCurrentPos().x);
	int monster1Y = (int)(g_monsters[0]->GetCurrentPos().y);
	int monster2X = (int)(g_monsters[1]->GetCurrentPos().x);
	int monster2Y = (int)(g_monsters[1]->GetCurrentPos().y);
	int monster3X = (int)(g_monsters[2]->GetCurrentPos().x);
	int monster3Y = (int)(g_monsters[2]->GetCurrentPos().y);
	int monster4X = (int)(g_monsters[3]->GetCurrentPos().x);
	int monster4Y = (int)(g_monsters[3]->GetCurrentPos().y);
	if (pacmanX == monster1X && pacmanY == monster1Y){
		m_over = true;
	}
	if (pacmanX == monster2X && pacmanY == monster2Y){
		m_over = true;
	}
	if (pacmanX == monster3X && pacmanY == monster3Y){
		m_over = true;
	}
	if (pacmanX == monster4X && pacmanY == monster4Y){
		m_over = true;
	}
	if (g_points == 106){
		m_over = true;
	}
	}

void Control::MoveMonster(Monster* monster){
		//找到当前位置
		int x1Quadrant = (int)((monster->GetCurrentPos().x - (2/squareSize)) - (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		int x2Quadrant = (int)((monster->GetCurrentPos().x + (2/squareSize)) + (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		int y1Quadrant = (int)((monster->GetCurrentPos().y - (2/squareSize)) - (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		int y2Quadrant = (int)((monster->GetCurrentPos().y + (2/squareSize)) + (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
		//怪物移动和撞墙检测
		switch (monster->GetCurrentRot()){
		case UP:
			if (!g_map->m_bitmap.at((int)monster->GetCurrentPos().x).at(y1Quadrant)){ 
				monster->GetCurrentPos().y -= 2 / squareSize;
			}else {
				Rotation current = monster->GetCurrentRot();
				do{
					monster->GetCurrentRot() = (Rotation)(rand() % 4);
				} while (current == monster->GetCurrentRot());
			}
			break;
		case RIGHT:
			if (!g_map->m_bitmap.at(x2Quadrant).at((int)monster->GetCurrentPos().y)){
				monster->GetCurrentPos().x += 2 / squareSize;
			}
			else {
				Rotation current = monster->GetCurrentRot();
				do{
					monster->GetCurrentRot() = (Rotation)(rand() % 4);
				} while (current == monster->GetCurrentRot());
			}
			break;
		case DOWN:
			if (!g_map->m_bitmap.at((int)monster->GetCurrentPos().x).at(y2Quadrant)){
				monster->GetCurrentPos().y += 2 / squareSize;
			}
			else {
				Rotation current = monster->GetCurrentRot();
				do{
					monster->GetCurrentRot() = (Rotation)(rand() % 4);
				} while (current == monster->GetCurrentRot());
			}
			break;
		case LEFT:
			if (!g_map->m_bitmap.at(x1Quadrant).at((int)monster->GetCurrentPos().y)){
				monster->GetCurrentPos().x -= 2 / squareSize;
			}
			else {
				Rotation current = monster->GetCurrentRot();
				do{
					monster->GetCurrentRot() = (Rotation)(rand() % 4);
				} while (current == monster->GetCurrentRot());
			}
			break;
		default:
			break;
		}
		}

void Control::SDisplay(){
	Control::GetInstance()->Display();
	}

void Control::SKeyPressed(unsigned char key,int x,int y){
	Control::GetInstance()->KeyPressed(key,x,y);
	}

void Control::SKeyUp(unsigned char key,int x,int y){
	Control::GetInstance()->KeyUp(key,x,y);
	}
