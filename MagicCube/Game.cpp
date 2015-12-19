
#include <thread>
#include "World.h"
#include "Screen.h"
#include "Mob.h"

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

	//�������
	Mob.addMob(MobType[0]);
	//�������
	Camera.Mob = Mob.addMob(MobType[0])->MobID;

	GameMainThread = std::thread(gameMainThread);
	GameMainThread.detach();
}