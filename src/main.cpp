#include "global.h"
#include "control.h"

int main(int argc,char* argv[]){
	InitWindow(&argc,argv);				//初始化创建屏幕、设置显示方式、设置窗口大小、设置窗口起始位置、设置窗口标题
	glutDisplayFunc(Control::SDisplay);	//窗口更新
	glutReshapeFunc(Control::Reshape);	//窗口变化
	glutIdleFunc(Control::SDisplay);	//循环画图
	glutKeyboardFunc(Control::SKeyPressed);
	glutKeyboardUpFunc(Control::SKeyUp);
	glutMainLoop();
	CleanUp();
	return 0;
	}
