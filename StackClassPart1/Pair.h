#pragma once

template<typename T, typename V>
class Pair
{
	T x;
	V y;
public:

	Pair();
	~Pair();

	void SetX(T x)
	{
		this->x = x;
	}
	void SetY(V y)
	{
		this->y = y;
	}
	T GetX()
	{
		return x;
	}
	V GetY()
	{
		return y;
	}

};

template<typename T, typename V>
inline Pair<T, V>::Pair()
{

}

template<typename T, typename V>
inline Pair<T, V>::~Pair()
{
}
