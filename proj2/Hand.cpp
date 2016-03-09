/*****************************************
** File:    Hand.cpp
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/20/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   This file contains the declaration for the Hand class.
 *   The class manages and implements the mechanics for a hand of
 *	 cards. Removing, counting, and printing is handled
**
***********************************************/
#include "Hand.h"

Hand::Hand(){}

//AddCard
//Add cards to players' hand
void Hand::AddCard(Card newCard)
{
	m_cards.push_back(newCard);
}

//ValueHand
//Count cards and return total
int Hand::ValueHand()
{
	int aces = 0;
	int total = 0;

	//Count each card
	for (int i = 0; i < SizeOfHand(); i++)
	{
		//Check for aces, make aces worth 11
		if(m_cards[i].GetBlackjackValue() == 1)
		{
			total += 11;
			aces++;
		}
		else
		{
			//Tally total
			total += m_cards[i].GetBlackjackValue();
		}
	}

	//Acount for aces if we went over 21
	while(total > 21 && aces > 0)
	{
		total -= 10;
		aces--;
	}

	return total;
}

//SizeOfHand
//Returns size of hand
int Hand::SizeOfHand()
{
	return m_cards.size();
}

//ClearHand
//Dumps all cards in hand
void Hand::ClearHand()
{
	m_cards.clear();
}

//PrintCards
//Prints out all cards.
void Hand::PrintCards(bool dealer)
{
	//Print each card
	for (int i = 0; i < SizeOfHand(); ++i)
	{
		//if dealer, hide remaining card(s)
		if(dealer && i > 0)
		{
			std::cout << "[hidden card]";
		}
		else
		{
			//Print the rest
			m_cards[i].OutputCard();
			if(i < SizeOfHand()-1)
			{
				std::cout << ", ";
			}
		}
	}
}