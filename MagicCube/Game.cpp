
#include <thread>
#include "World.h"
#include "Screen.h"
#include "Mob.h"

std::thread GameThread;


//��Ϸ��ѭ��
void gameMain()
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
	GameThread = std::thread(gameMain);
}