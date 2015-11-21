#pragma once

#include "MagicCube.h"

class chunkMap
{
	class chunkLocation
	{
		int ChunkX = 0;
		int ChunkZ = 0;

		unsigned int ChunkID = 0;

	public:
		//��ʼ��
		//�ֱ��ṩChunk�������ChunkID
		chunkLocation(int inputChunkX, int inputChunkZ, unsigned int inputChunkID)
		{
			ChunkX = inputChunkX;
			ChunkZ = inputChunkZ;

			ChunkID = inputChunkID;
		}
		//ֻ�ṩChunk�����꣬ChunkIDΪ�գ�ֻ�ڲ���Chunkʱʹ�ã��������ʹ�������᲻��ȫ
		chunkLocation(int inputChunkX, int inputChunkZ)
		{
			ChunkX = inputChunkX;
			ChunkZ = inputChunkZ;

			ChunkID = 0;
		}

		//����������
		bool operator==(chunkLocation Location)
		{
			if ((Location.ChunkX == ChunkX) && (Location.ChunkZ == ChunkZ))
			{
				return true;
			}
			return false;
		}
		//�жϴ�С�����ж�X�����ж�Z��
		bool operator>(chunkLocation Location)
		{
			if ((Location.ChunkX < ChunkX))
			{
				return true;
			}
			else if ((Location.ChunkX == ChunkX))
			{
				if ((Location.ChunkZ < ChunkZ))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		//�жϴ�С�����ж�X�����ж�Z��
		bool operator<(chunkLocation Location)
		{
			if ((Location.ChunkX > ChunkX))
			{
				return true;
			}
			else if ((Location.ChunkX == ChunkX))
			{
				if ((Location.ChunkZ > ChunkZ))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

		//����ChunkID
		unsigned int getChunkID()
		{
			return ChunkID;
		}
	};

	//���ֲ���
	unsigned int binarySearchChunk(int ChunkX,int ChunkZ)
	{
		if (!HasSort)
		{
			//��������
			std::sort(ChunkMap.begin(), ChunkMap.end());
			HasSort = true;
		}

		if (ChunkMap.empty() || ChunkMap.size() == 0)
			return -1;

		chunkLocation FindChunkLoc(ChunkX, ChunkZ);

		int NowRight = 0;
		int NowMid = 0;

		int NowLeft = ChunkMap.size() - 1;

		while (NowRight <= NowLeft)
		{
			NowMid = (NowRight + NowLeft) / 2;

			if (ChunkMap[NowMid] < FindChunkLoc)
				NowRight = NowMid + 1;
			else if (ChunkMap[NowMid] > FindChunkLoc)
				NowLeft = NowMid - 1;
			else
			{
				return NowMid;
			}
		}
		return -1;
	}

	std::vector<chunkLocation> ChunkMap;

	bool HasSort = true;

public:
	//���Chunk��ChunkMap
	void addChunk(int ChunkX, int ChunkZ, unsigned int ChunkID)
	{
		ChunkMap.push_back(chunkLocation(ChunkX, ChunkZ, ChunkID));
		HasSort = false;
	}
	//��ChunkMap���Ƴ�Chunk
	unsigned int delChunk(int ChunkX, int ChunkZ)
	{
		int FindChunkID = binarySearchChunk(ChunkX, ChunkZ);

		if (FindChunkID == -1)
		{
			return -1;
		}
		const int ReturnChunkID = ChunkMap[FindChunkID].getChunkID();

		std::vector<chunkLocation>::iterator FindIterator = ChunkMap.begin() + FindChunkID;

		ChunkMap.erase(FindIterator);

		return ReturnChunkID;
	}
	//����Chunk
	unsigned int findChunk(int ChunkX, int ChunkZ)
	{
		int FindChunkID = binarySearchChunk(ChunkX, ChunkZ);
		
		if (FindChunkID == -1)
		{
			return -1;
		}
		return ChunkMap[FindChunkID].getChunkID();
	}
};