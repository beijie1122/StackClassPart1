#include <iostream>
#include <stack>

class Stack
{
public:
	Stack();
	Stack(int cap);
	~Stack();
	int SizeofStack();
	bool IsStackEmpy();
	void PushElement(int Element);
	void PopElement();
	int TopOfStack();

private:
	int* arr;
	int nextIndex;
	int Capacity;
};

Stack::Stack()
{
	arr = new int[4];
	nextIndex = 0;
	Capacity = 4;
}

Stack::Stack(int cap)
{
	arr = new int[cap];
	nextIndex = 0;
	Capacity = cap;

}

void Stack::PushElement(int Element)
{
	if (nextIndex == Capacity)
	{
		std::cout << "You have run out of space within your array" << "\n";
		return;
	}
	else
	{
		arr[nextIndex] = Element;
		nextIndex++;
	}

}

void Stack::PopElement()
{
	if (nextIndex == 0)
	{
		std::cout << "Your stack is already empty, please add elements to pop" << "\n";
		return;
	}
	else
	{
		nextIndex--;
	}
}

int Stack::SizeofStack()
{
	return nextIndex;
}

int Stack::TopOfStack()
{
	if (IsStackEmpy())
	{
		std::cout << "Your Stack is empty" << "\n";
		return -1;
	}
	return arr[nextIndex - 1];
}

bool Stack::IsStackEmpy()
{
	/*
	if (nextIndex == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/

	return nextIndex == 0;

	//LOGIC:
	//If 0 == 0, will return True (1)
	//If 5 == 0, will return False (0)

}

Stack::~Stack()
{
}



int main()
{
	Stack s(5);

	s.PushElement(10);
	s.PushElement(20);
	s.PushElement(30);
	s.PushElement(40);
	s.PushElement(50);
	s.PushElement(60);

	std::cout << s.TopOfStack() << "\n";

	s.PopElement();

	std::cout << s.TopOfStack() << "\n";

	std::cout << s.IsStackEmpy() << "\n";

	s.PopElement();

	std::cout << s.TopOfStack() << "\n";

	return 0;
}