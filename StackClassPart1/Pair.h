#pragma once

template<typename T, typename V>
class Pair
{
	T x;
	V y;
public:

	Pair();
	~Pair();

	void SetX(T x);
	void SetY(V y);
	int GetX();
	int GetY();

};

template<typename T, typename V>
inline Pair<T, V>::Pair()
{

}

template<typename T, typename V>
inline Pair<T, V>::~Pair()
{
}

template<typename T, typename V>
inline void Pair<T, V>::SetX(T x)
{
	this->x = x;
}

template<typename T, typename V>
inline void Pair<T, V>::SetY(V y)
{
	this->y = y;
}

template<typename T, typename V>
inline int Pair<T, V>::GetX()
{
	return x;
}

template<typename T, typename V>
inline int Pair<T, V>::GetY()
{
	return y;
}
