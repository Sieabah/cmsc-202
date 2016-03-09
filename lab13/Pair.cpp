/*
#ifndef PAIR_CPP
#define PAIR_CPP

#include "Pair.h"

Pair::Pair() {}

//TEMPLATED
template <class T>
Pair::Pair(T first, T second)
: m_first(first), m_second(second)
{
	//m_first = first;
	//m_second = second;
}

template <class T>
T Pair::GetFirst() const
{
	return m_first;
}

template <class T>
T Pair::GetSecond() const
{
	return m_second;
}

bool Pair::operator== (const Pair& other) const
{
	return (m_first == other.GetFirst() && m_second == other.GetSecond())
		|| (m_first == other.GetSecond() && m_second == other.GetFirst());
}

#endif //PAIR_CPP
*/