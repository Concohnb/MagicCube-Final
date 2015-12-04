
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

	initScreen();

	initTexture();

	//���һ����Ļ���Ҽ���
	//Screen.enableScreen(Screen.addScreen());
	//���һ����Ļ���Ҽ���
	Screen.enableScreen(screenInfo::GameScreen);

	//��ȡ�µ�RenderGroup��ָ��
	renderGroup* RenderGroup = Screen.addRenderGroup();

	//����Shader
	RenderGroup->setShader(&Shader[0]);
	std::vector<GLfloat> RenderData;

	RenderData.reserve(100);
	//�ṩ��Ⱦ����
	for (int i = 0; i < 1000; i++)
	{
		RenderData.push_back(-0.5);
		RenderData.push_back(0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(0.0);
		RenderData.push_back(0.0);
		/////////////////////
		RenderData.push_back(-0.5);
		RenderData.push_back(-0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(0.0);
		RenderData.push_back(1.0);
		//////////////////////
		RenderData.push_back(0.5);
		RenderData.push_back(-0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(1.0);
		RenderData.push_back(1.0);
		////////////////////
		RenderData.push_back(0.5);
		RenderData.push_back(0.5);
		RenderData.push_back(i*0.00001);

		RenderData.push_back(1.0);
		RenderData.push_back(0.0);
	}
	//////////////////////////////////////////////
	//OK��

	//��������
	RenderGroup->setData(&RenderData);
	//������Ⱦ��
	RenderGroup->IsEnable = true;


	//��Ⱦ��ѭ��
	return renderMainLoop();
}