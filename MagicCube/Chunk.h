#pragma once

#include "Block.h"
#include "ChunkMap.h"
#include "RenderGroup.h"

static int		MaxChunkNumber = 4096;

//���浥��Chunk������
class chunk
{
private:
	//��������
	blockData BlockData[16][16][256];
public:
	//RenderGroupָ��
	renderGroup *RenderGroup;

	//��ȡ�������ݣ��뱣֤BlockX��BlockY��BlockZ����Ӧ�ķ�Χ��
	blockData getBlock(unsigned char BlockX, unsigned char BlockY, unsigned char BlockZ)
	{
		if ((BlockX > 15) | (BlockY > 15) | (BlockZ > 15))
		{
			throw;
		}
		return BlockData[BlockX][BlockY][BlockZ];
	}
	//���÷������ݣ��뱣֤BlockX��BlockY��BlockZ����Ӧ�ķ�Χ��
	void setBlock(unsigned char BlockX, unsigned char BlockY, unsigned char BlockZ, blockData BlockData)
	{
		if ((BlockX > 15) | (BlockY > 15) | (BlockZ > 15))
		{
			throw;
		}
		chunk::BlockData[BlockX][BlockY][BlockZ] = BlockData;
	}
	bool	IsEmpty = true;

	int		ChunkX = 0;
	int		ChunkZ = 0;
};

static chunk	EmptyChunk;
