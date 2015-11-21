#pragma once

#include "Block.h"
#include "ChunkMap.h"
#include "RenderGroup.h"

static int		MaxChunkNumber = 2500;

//���浥��Chunk������
class chunk
{
private:
	//��������
	blockData BlockData[16][16][256];
public:
	//RenderGroupָ��
	renderGroup *RenderGroup;

	void RefreshRenderData()
	{

	}
	//��ȡ�������ݣ��뱣֤BlockX��BlockY��BlockZ����Ӧ�ķ�Χ��
	blockData getBlock(unsigned char BlockX, unsigned char BlockY, unsigned char BlockZ)
	{
		if ((BlockX > 15) | (BlockY > 15) | (BlockZ > 15))
		{
			throw;
		}
		return BlockData[BlockX][BlockY][BlockZ];
	}
	//��ȡ�������ݣ��뱣֤BlockX��BlockY��BlockZ����Ӧ�ķ�Χ��
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

//����һ��Chunk��һ����˵ÿ��world���н���һ��chunks��ı�����
class chunks
{
	//Ѱ�ҿ��е�ChunkID
	unsigned int findFreeChunkID()
	{
		if (FreeChunksList.size() == 0)
		{
			if (HasUseChunkID == MaxChunkNumber)
			{
				return -1;
			}
			return HasUseChunkID++;
		}

		int FreeChunkID = FreeChunksList.back();

		FreeChunksList.pop_back();

		return FreeChunkID;
	}

	int		HasUseChunkID = 0;

	std::list<int>		FreeChunksList;
	chunkMap			ChunkMap;
	std::vector<chunk>	Chunk;

public:
	//��Chunk��ID������Chunk����û��ʲô���ã�
	chunk* operator [](unsigned int Count)
	{
		return &Chunk[Count];
	}
	//��ʼ��Chunks�����ڿ��ܻ������޸�
	chunks()
	{
		Chunk.reserve(MaxChunkNumber);
	}
	//���һ��Chunk������ֵ��ʾ���Ƿ�ɹ����Chunk
	bool addChunk(int ChunkX, int ChunkZ)
	{
		int FreeChunk = findFreeChunkID();

		if (FreeChunk == -1)
		{
			return false;
		}
		Chunk[FreeChunk].IsEmpty = false;
		Chunk[FreeChunk].ChunkX = ChunkX;
		Chunk[FreeChunk].ChunkZ = ChunkZ;
		ChunkMap.addChunk(ChunkX, ChunkZ, FreeChunk);

		return true;
	}
	//ɾ��chunk
	void delChunk(int ChunkX, int ChunkZ)
	{
		int getChunkID = ChunkMap.delChunk(ChunkX, ChunkZ);

		if (getChunkID == -1)
		{
			return;
		}
		Chunk[getChunkID].IsEmpty = true;

		FreeChunksList.push_back(getChunkID);
	}
	//Ѱ��chunk
	chunk* findChunk(int ChunkX, int ChunkZ)
	{
		int getChunkID = ChunkMap.findChunk(ChunkX, ChunkZ);

		if (getChunkID == -1)
		{
			EmptyChunk.IsEmpty = true;

			return &EmptyChunk;
		}
		return &Chunk[getChunkID];
	}
};