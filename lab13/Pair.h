#ifndef PAIR_H
#define PAIR_H

//*
template <class T> 
class Pair 
{
public:
	Pair()
	{}
	Pair(T first, T second) : m_first(first), m_second(second) {}

	T GetFirst() const { return m_first; }
	T GetSecond() const { return m_second; }

	bool operator==(const Pair& other) const
	{
		return (m_first == other.GetFirst() && m_second == other.GetSecond())
		|| (m_first == other.GetSecond() && m_second == other.GetFirst());
	}

private:
	T m_first;
	T m_second;
};

#include "Pair.cpp"

#endif //PAIR_H
