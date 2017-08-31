#pragma once
#include "heaptype.h"
#include "heaptype.cpp"

class FullPQ
{};

class EmptyPQ
{};

template<class ItemType>
class PQType
{
	public:
		PQType(int);
		~PQType();
		void MakeEmpty();
		bool IsEmpty();
		bool IsFull();
		void Enqueue(ItemType);
		void Dequeue(ItemType&);
		void PrintQueue();
	private:
		int length;
		HeapType<ItemType> items;
		int maxItems;
};
