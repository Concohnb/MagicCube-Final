
#include "Screen.h"
#include "Chunk.h"
#include "Mob.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int renderMainLoop();
void initGame();

int main()
{
	initGame();
	//���һ����Ļ���Ҽ���
	Screen.enableScreen(screenInfo::GameScreen);

	//////////////////////////////////////////////

	for (int i2 = -32; i2 < 32; i2++)
	{
		for (int j2 = -32; j2 < 32; j2++)
		{
			//��ȡ�µ�RenderGroup��ָ��
			renderGroup* RenderGroup = Screen.addRenderGroup();

			//����Shader
			RenderGroup->setShader(&Shader[0]);

			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					Blocks[0].AddRenderData(RenderGroup, 0, 1, 1, 1, 1, 1, 1, i + i2 * 16, -2, j + j2 * 16);
				}
			}

			RenderGroup->refreshData();
			//������Ⱦ��
			RenderGroup->IsEnable = true;
		}
	}
	//////////////////////////////////////////////
	//OK��

	renderMainLoop();
	//��Ⱦ��ѭ��
	return 0;
}