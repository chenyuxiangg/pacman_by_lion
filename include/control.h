#ifndef CONTROL_H
#define CONTROL_H
#include "structs.h"
#include "monster.h"
class Control{
	private:
		Control();
		Control(Control&) = delete;
		Control operator=(Control&) = delete;
	public:
		~Control();
		void Init();
		//游戏开始控制
		void Welcome();
		void Display();
		static void SDisplay();
		static Control* GetInstance();
		static void Reshape(int w,int h);
		static void SKeyPressed(unsigned char key,int x,int y);
		static void SKeyUp(unsigned char key,int x,int y);
		//按键控制
		void KeyPressed(unsigned char key,int x,int y);
		void KeyUp(unsigned char key,int x,int y);
		void KeyOperations();
		//重置游戏
		void ResetGame();
		//AI控制
		void MoveMonster(Monster* monster);
		//游戏评判
		void ResultDisplay();
		//游戏结束
		void GameOver();
		
	private:
		bool m_replay;
		bool m_over;
		vector<bool> m_keyStates;
		static Control* m_instance;
	};

#endif
