
#include "Screen.h"
#include "Chunk.h"
#include "Mob.h"
//��ʼ��Chunk
world MainWorld;

int initGL();
int renderMainLoop();
void initGame();
void initScreen();
void initTexture();
void initMob();

int main()
{
	//��ʼ��OpenGL
	initGL();

	//��ʼ������
	initMob();

	Mob.addMob(MobType[0]);
	//��ʼ����Ϸ
	initGame();

	//��ʼ����Ļ
	initScreen();
	//��ʼ������
	initTexture();
	//��ʼ��Block
	initBlock();

	//���һ����Ļ���Ҽ���
	Screen.enableScreen(screenInfo::GameScreen);

	//��ȡ�µ�RenderGroup��ָ��
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//����Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(100);

	Blocks[0].AddRenderData(&RenderData, 0, 1, 0, 0, 0, 0, 0);
	//////////////////////////////////////////////
	//OK��

	//��������
	RenderGroup->setData(&RenderData);
	//������Ⱦ��
	RenderGroup->IsEnable = true;


	//��Ⱦ��ѭ��
	return renderMainLoop();
}