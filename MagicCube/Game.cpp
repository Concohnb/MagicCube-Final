
#include <thread>
#include "World.h"
#include "Screen.h"
#include "Mob.h"
#include <Windows.h>

std::thread GameMainThread;

//��ʼ��
int	 initGL();
void initBlock();
void initGame();
void initScreen();
void initTexture();
void initMob();

//��Ϸ��ѭ��
void gameMainThread()
{
	while (!glfwWindowShouldClose(window))
	{
		Sleep(10);
		if (Screen.getEnableScreen() == 0)
		{

		}
		else
		{
			Mob.refreshMobs();
		}
	}
}
void initGame()
{
	//��ʼ��OpenGL
	initGL();

	//��ʼ������
	initMob();

	//��ʼ����Ļ
	initScreen();

	//��ʼ������
	initTexture();

	//��ʼ��Block
	initBlock();

	Mob.addMob(MobType[0]);

	GameMainThread = std::thread(gameMainThread);
	GameMainThread.detach();
}