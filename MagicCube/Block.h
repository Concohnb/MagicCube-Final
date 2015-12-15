#pragma once

#include "MagicCube.h"

typedef void(*addRenderData)(std::vector<GLfloat> *TodalData, int Addition, bool RenderTop, bool RenderDown, bool RenderLeft, bool RenderRight, bool RenderFront, bool RenderBack);

struct blockData
{
	unsigned short	BlockID			= 0;
	unsigned char	BlockAddition	= 0;
};

class blocks
{
private:
	//block��
	class block
	{
		unsigned int	BlockID;

		std::string BlockName;

	public:
		addRenderData AddRenderData;

		//��ʼ��Block
		block(unsigned int BlockID, const char* BlockName, addRenderData AddRenderData)
		{
			block::BlockID			= BlockID;
			block::BlockName		= BlockName;
			block::AddRenderData	= AddRenderData;

		}
		//��ȡBlockID
		unsigned int getBlockID()
		{
			return BlockID;
		}
		//��ȡBlock����
		std::string getBlockName()
		{
			return BlockName;
		}
	};
	//������������block����
	std::vector<block> Blocks;
public:
	//ͨ��ID����Block
	block operator [](unsigned int BlockID)
	{
		if (BlockID > Blocks.size())
		{
			return block(0,"NULL",NULL);
		}
		return Blocks[BlockID];
	}
	//���һ���µ�Block
	void addBlock(const char* BlockName, addRenderData AddRenderData)
	{
		Blocks.push_back(block((unsigned int)Blocks.size(), BlockName, AddRenderData));
	}
};

//����Blocks
extern blocks Blocks;

//��ʼ��Block
void initBlock();