#include "gamemap.h"
#define GLOBAL
#include "global.h"
GameMap::GameMap(){
	Init();
	}

void GameMap::Init(){
	m_obstaclesTop = { 2, 2, 3, 6, 3, 6, 4, 5, 4, 2, 5, 4, 5, 3, 6, 5, 6, 1, 9, 2, 7, 2, 8, 5, 9, 5, 10, 3, 10, 4, 11, 2, 11, 5, 12, 6, 12, 6, 13, 2 };
	m_obstaclesMiddle = { 2, 9, 3, 7, 3, 7, 4, 8, 4, 9, 5, 11, 5, 6, 6, 10, 6, 10, 7, 8, 7, 8, 8, 9, 6, 7, 7, 6, 8, 6, 9, 7, 10, 6, 9, 10, 9, 10, 8, 8, 11, 9, 10, 11, 11, 8, 12, 7, 12, 7, 13, 9 };
	m_obstaclesBottom = { 2, 10, 3, 13, 3, 13, 4, 12, 5, 12, 6, 13, 6, 13, 7, 11, 8, 11, 9, 13, 9, 13, 10, 12, 11, 12, 12, 13, 12, 13, 13, 10 };
	m_bitmap.push_back({ true, true, true, true, true, true, true, true, true, true, true, true, true, true, true });
	m_bitmap.push_back({ true, false, false, false, false, false, false, false, false, false, false, false, false, false, true });
	m_bitmap.push_back({ true, false, true, true, true, true, false, true, true, false, true, true, true, false, true });
	m_bitmap.push_back({ true, false, false, false, false, true, false, true, false, false, false, false, true, false, true});
	m_bitmap.push_back({ true, false, true, true, false, false, false, false, false, true, true, false, false, false, true});
	m_bitmap.push_back({ true, false, false, true, true, false, true, true, true, true, false, false, true, false, true});
	m_bitmap.push_back({ true, true, false, false, false, false, true, false, true, true, false, true, true, false, true});
	m_bitmap.push_back({ true, true, true, true, true, false, false, false, true, false, false, false, false, false, true});
	m_bitmap.push_back({ true, true, false, false, false, false, true, false, true, true, false, true, true, false, true });
	m_bitmap.push_back({ true, false, false, true, true, false, true, true, true, true, false, false, true, false, true });
	m_bitmap.push_back({ true, false, true, true, false, false, false, false, false, true, true, false, false, false, true });
	m_bitmap.push_back({ true, false, false, false, false, true, false, true, false, false, false, false, true, false, true });
	m_bitmap.push_back({ true, false, true, true, true, true, false, true, true, false, true, true, true, false, true });
	m_bitmap.push_back({ true, false, false, false, false, false, false, false, false, false, false, false, false, false, true });
	m_bitmap.push_back({ true, true, true, true, true, true, true, true, true, true, true, true, true, true, true });
	}

void GameMap::DrawMap(){
	glColor3f(1.0, 1.0, 1.0);
	//边界
	for (vector<int>::size_type i = 0; i < m_border.size(); i = i + 4){
		glRectf(m_border.at(i) * squareSize, m_border.at(i + 1)*squareSize, m_border.at(i + 2)*squareSize, m_border.at(i + 3)*squareSize);
	}

	//障碍物
	for (vector<int>::size_type j = 0; j < m_obstaclesBottom.size(); j = j + 4){
		glRectf(m_obstaclesBottom.at(j) * squareSize, m_obstaclesBottom.at(j + 1)*squareSize, m_obstaclesBottom.at(j + 2)*squareSize, m_obstaclesBottom.at(j + 3)*squareSize);
	}
	for (vector<int>::size_type k = 0; k < m_obstaclesMiddle.size(); k = k + 4){
		glRectf(m_obstaclesMiddle.at(k) * squareSize, m_obstaclesMiddle.at(k + 1)*squareSize, m_obstaclesMiddle.at(k + 2)*squareSize, m_obstaclesMiddle.at(k + 3)*squareSize);
	}
	for (vector<int>::size_type p = 0; p < m_obstaclesTop.size(); p = p + 4){
		glRectf(m_obstaclesTop.at(p) * squareSize, m_obstaclesTop.at(p + 1)*squareSize, m_obstaclesTop.at(p + 2)*squareSize, m_obstaclesTop.at(p + 3)*squareSize);
	}
	}

void GameMap::Update(){
	
	}

GameMap::~GameMap(){}
