#pragma once

template<typename T>
class Pair
{
	T x;
	T y;
public:

	Pair();
	~Pair();

	void SetX(T x);
	void SetY(T y);
	int GetX();
	int GetY();

};

template<typename T>
inline Pair<T>::Pair()
{

}

template<typename T>
inline Pair<T>::~Pair()
{
}

template<typename T>
inline void Pair<T>::SetX(T x)
{
	this->x = x;
}

template<typename T>
inline void Pair<T>::SetY(T y)
{
	this->y = y;
}

template<typename T>
inline int Pair<T>::GetX()
{
	return x;
}

template<typename T>
inline int Pair<T>::GetY()
{
	return y;
}
