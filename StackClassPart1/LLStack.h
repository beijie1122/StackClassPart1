#pragma once
#include "Node.h"
#include <iostream>
class LLStack
{
	Node* head;
	int size;
public:
	LLStack();

	void Push(int Element);

	void Pop();

	bool IsEmpty();

	int GetSize();

	int Top();

	~LLStack();


};

