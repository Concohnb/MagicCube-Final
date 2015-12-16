#pragma once

#include "Chunk.h"

//����һ��World��һ����˵ÿ��world���н���һ��chunks��ı�����
class world
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
	~world()
	{
		Chunk.clear();
	}
	//��Chunk��ID������Chunk����û��ʲô���ã�
	chunk* operator [](unsigned int Count)
	{
		return &Chunk[Count];
	}
	//��ʼ��Chunks�����ڿ��ܻ������޸�
	world()
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

extern world MainWorld;