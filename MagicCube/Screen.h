#pragma once

#include "RenderGroup.h"
#include <mutex>

typedef void(*screenOpenglCode)();

class screen
{
	//ÿ�����������Σ���������Ϊ12(��״)+8(����)+16(��ɫ),����������Ժ��ڼ�
	std::vector<renderGroup> RenderGroup;

	screenOpenglCode ScreenOpenglCode;
public:
	screen(screenOpenglCode ScreenOpenglCode)
	{
		screen::ScreenOpenglCode = ScreenOpenglCode;
	}
	renderGroup* addRenderGroup()
	{
		RenderGroup.push_back(renderGroup());

		return &RenderGroup[RenderGroup.size() - 1];
	}
	renderGroup* getRenderGroup(int Count)
	{
		return &RenderGroup[Count];
	}
	void drawScreen()
	{
		ScreenOpenglCode();

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
	std::mutex NowEnableScreenMutex;

	unsigned int	NowEnableScreen = 0;
public:
	//��Ⱦ
	void enableScreen(unsigned int ScreenID)
	{
		if (ScreenID < Screen.size())
		{
			glBindVertexArray(VertexArrays[ScreenID]);

			NowEnableScreenMutex.lock();
			NowEnableScreen = ScreenID;
			NowEnableScreenMutex.unlock();
		}
	}
	void drawScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Screen[NowEnableScreen].drawScreen();
	}
	//�޸�����
	unsigned int addScreen(screenOpenglCode ScreenOpenglCode)
	{
		Screen.push_back(screen(ScreenOpenglCode));
		VertexArrays.resize(Screen.size());

		glGenVertexArrays(1,&VertexArrays[Screen.size() - 1]);

		return (unsigned int)Screen.size() - 1;
	}
	renderGroup* addRenderGroup()
	{
		return Screen[NowEnableScreen].addRenderGroup();
	}
	//��ȡ����
	unsigned int getEnableScreen()
	{
		NowEnableScreenMutex.lock();

		int ReturnData = NowEnableScreen;

		NowEnableScreenMutex.unlock();

		return ReturnData;
	}
	unsigned int getSize()
	{
		return (unsigned int)Screen.size();
	}
};

namespace screenInfo
{
	extern unsigned int TitleScreen;
	extern unsigned int GameScreen;
}
extern screens Screen;
