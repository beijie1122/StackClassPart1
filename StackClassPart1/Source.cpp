#include <iostream>
#include <stack>
#include "Pair.h"
#include <string>
#include <vector>

template<typename T>
class Stack
{
public:
	Stack();
	Stack(int cap);
	~Stack();
	int SizeofStack();
	bool IsStackEmpy();
	void PushElement(T Element);
	void PopElement();
	int TopOfStack();

private:
	T* arr;
	int nextIndex;
	int Capacity;
};

template<typename T>
inline Stack<T>::Stack()
{
	arr = new T[4];
	nextIndex = 0;
	Capacity = 4;
}

//DO NOT USE THIS, THIS IS FOR STATIC STACK 
template<typename T>
inline Stack<T>::Stack(int cap)
{
	arr = new T[cap];
	nextIndex = 0;
	Capacity = cap;

}

template<typename T>
inline void Stack<T>::PushElement(T Element)
{
	if (nextIndex == Capacity)
	{
		std::cout << "Old Stack is too small, updating size....\n";
		T* newArr = new T[2 * Capacity];
		for (int i = 0; i < Capacity; i++)
		{
			newArr[i] = arr[i];
		}

		delete[]arr;
		arr = newArr;
		Capacity = Capacity * 2;
	}
		arr[nextIndex] = Element;
		nextIndex++;
		std::cout << "Added " << Element << " To the stack!\n";


}

template<typename T>
inline void Stack<T>::PopElement()
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

template<typename T>
inline int Stack<T>::SizeofStack()
{
	return nextIndex;
}

template<typename T>
inline int Stack<T>::TopOfStack()
{
	if (IsStackEmpy())
	{
		std::cout << "Your Stack is empty" << "\n";
		return -1;
	}
	return arr[nextIndex - 1];
}

template<typename T>
inline bool Stack<T>::IsStackEmpy()
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

template<typename T>
inline Stack<T>::~Stack()
{

}



int main()
{
	//Stack<int> s;

	//s.PushElement(10);
	//s.PushElement(20);
	//s.PushElement(30);
	//s.PushElement(40);
	//s.PushElement(50);
	//s.PushElement(60);

	Stack<char> s;

	s.PushElement('a');
	s.PushElement('b');
	s.PushElement('c');
	s.PushElement('d');
	s.PushElement('e');
	s.PushElement('f');
	s.PushElement('g');

	std::cout << s.TopOfStack() << "\n";

	s.PopElement();

	std::cout << s.TopOfStack() << "\n";

	std::cout << s.IsStackEmpy() << "\n";

	s.PopElement();

	std::cout << s.TopOfStack() << "\n";

	Pair<int, double> p1;

	p1.SetX(10.1);
	p1.SetY(22.22);

	std::cout << p1.GetX() << " " << p1.GetY() << "\n";


	Pair<Pair<int, int>, char> P2;

	P2.SetY('a');

	Pair<int, int> P3;

	P3.SetX(20);

	P3.SetY(30);

	P2.SetX(P3);

	std::cout << P2.GetY() << P2.GetX().GetX() << P2.GetX().GetY() << "\n";

	std::string StackInput{ "{[]}" };

	std::stack<char> MatchingParaStack;

	bool IsStringMatching = true;

	for (size_t i = 0; i < StackInput.size(); i++)
	{
		if (StackInput.at(i) == '{' || StackInput.at(i) == '[' || StackInput.at(i) == '(')
		{
			MatchingParaStack.push(StackInput.at(i));
		}
		else if (StackInput.empty())
		{
			std::cout << "Unable to perform the test, not enough variables to measure!\n";
			IsStringMatching = false;
		}
		else
		{
			if (MatchingParaStack.top() == '[' && StackInput.at(i) == ']')
			{
				MatchingParaStack.pop();
			}
			else if (MatchingParaStack.top() == '{' && StackInput.at(i) == '}')
			{
				MatchingParaStack.pop();
			}
			else if (MatchingParaStack.top() == '(' && StackInput.at(i) == ')')
			{
				MatchingParaStack.pop();
			}
			else
			{
				IsStringMatching = false;
			}
		}
	}

	std::cout << "The result of the Stack and String test is: " << IsStringMatching << "\n";

	int ThirdVar;

	int Answer;

	std::stack<int> ReversePolishStack;

	std::vector<std::string> Tokens = {"4", "13", "5", "/", "+"};

	for (size_t i = 0; i < Tokens.size(); i++)
	{
		if (Tokens[i] == "+" || Tokens[i] == "-" || Tokens[i] == "*" || Tokens[i] == "/")
		{
			int FirstVar = ReversePolishStack.top();
			ReversePolishStack.pop();
			int SecondVar = ReversePolishStack.top();
			ReversePolishStack.pop();

			if (Tokens[i] == "+")
			{
				ThirdVar = FirstVar + SecondVar;			
			}
			else if (Tokens[i] == "-")
			{
				ThirdVar = FirstVar - SecondVar;
			}
			else if (Tokens[i] == "*")
			{
				ThirdVar = FirstVar * SecondVar;
			}
			else if (Tokens[i] == "/")
			{
				ThirdVar = FirstVar / SecondVar;
			} 
			ReversePolishStack.push(ThirdVar);
		}
		else
		{
			ReversePolishStack.push(atoi(Tokens[i].c_str()));
		}
	}

	Answer = ReversePolishStack.top();

	std::cout << "The Answer to the equation is: " << Answer << "\n";

	return 0;
}