#pragma once

#include "RenderGroup.h"
#include "Player.h"
class screen
{
	//ÿ�����������Σ���������Ϊ12(��״)+8(����)+16(��ɫ),����������Ժ��ڼ�
	std::vector<renderGroup> RenderGroup;

	bool IsGameScreen = false;
public:
	renderGroup* addRenderGroup()
	{
		RenderGroup.push_back(renderGroup());

		return &RenderGroup[RenderGroup.size() - 1];
	}
	renderGroup* getRenderGroup(int Count)
	{
		return &RenderGroup[Count];
	}
	screen(bool IsGameScreen)
	{
		screen::IsGameScreen = IsGameScreen;
	}
	void screenLoop()
	{
		if (IsGameScreen)
		{
			//��Ϸ��ѭ��
			Player.playerMove();
		}
	}
	void drawScreen()
	{
		for (unsigned int i = 0; i < RenderGroup.size(); i++)
		{
			RenderGroup[i].draw();
		}
	}
};

//������Ҫ������Ҫ�޸ĵ�Screen��Ȼ���ٽ��в���
class screens
{
	std::vector<screen> Screen;
	std::vector<GLuint> VertexArrays;

	unsigned int	NowEnableScreen = 0;
public:
	//��Ⱦ
	void enableScreen(unsigned int ScreenID)
	{
		if (ScreenID < Screen.size())
		{
			glBindVertexArray(VertexArrays[ScreenID]);

			NowEnableScreen = ScreenID;
		}
	}
	void drawScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Screen[NowEnableScreen].drawScreen();
	}
	//�޸�����
	unsigned int addScreen(bool IsGameScreen)
	{
		Screen.push_back(screen(IsGameScreen));
		VertexArrays.resize(Screen.size());

		glGenVertexArrays(1,&VertexArrays[Screen.size() - 1]);

		return Screen.size() - 1;
	}
	renderGroup* addRenderGroup()
	{
		return Screen[NowEnableScreen].addRenderGroup();
	}
	//��ȡ����
	unsigned int getSize()
	{
		return Screen.size();
	}
	//������Ļ�ڵ���Ϣ
	void screenLoop()
	{
		Screen[NowEnableScreen].screenLoop();
	}
};

extern screens Screen;