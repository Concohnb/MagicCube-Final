
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

	//��ȡ�µ�RenderGroup��ָ��
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//����Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(10000);

	Blocks[0].AddRenderData(&RenderData, 0, 1, 1, 1, 1, 1, 1);
	//////////////////////////////////////////////
	//OK��

	//��������
	RenderGroup->setData(&RenderData);
	//������Ⱦ��
	RenderGroup->IsEnable = true;

	Mob.addMob(MobType[0]);

	renderMainLoop();
	//��Ⱦ��ѭ��
	return 0;
}