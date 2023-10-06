#include "LLStack.h"

LLStack::LLStack()
{
	head = nullptr;
	size = 0;
}

void LLStack::Push(int Element)
{
	Node* n = new Node(Element);
	n->next = head;
	head = n;
	size++;

}

void LLStack::Pop()
{
	if (IsEmpty())
	{
		std::cout << "Your Stack is empty\n";
		return;
	}

	Node* temp = head;
	head = head->next;
	temp->next = nullptr;
	delete temp;
	size--;

}

bool LLStack::IsEmpty()
{
	return size == 0;
}

int LLStack::GetSize()
{
	return size;
}

int LLStack::Top()
{
	if (IsEmpty())
	{
		std::cout << "Your Stack is Empty\n";
		return 0;
	}

	return head->data;
}

LLStack::~LLStack()
{

}
