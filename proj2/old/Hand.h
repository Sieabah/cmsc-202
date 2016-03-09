/*****************************************
** File:    Hand.h
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/20/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
**      This file holds all the definitions for the hand class
**
***********************************************/
#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand
{
public:
	//-------------------------------------------------------
	// Name: Hand
	// Function: Default constructor
	// PreCondition: 
	// PostCondition: 
	// Returns: 
	//---------------------------------------------------------
	Hand();

	//-------------------------------------------------------
	// Name: AddCard
	// Function: Add card to hand
	// PreCondition: Valid card
	// PostCondition: 
	// Returns: 
	//---------------------------------------------------------
	void AddCard(Card card);

	//-------------------------------------------------------
	// Name: GetValueOfHand
	// Function: Count value of the cards in hand.
	// PreCondition: None
	// PostCondition: Gives
	// Returns: 
	//---------------------------------------------------------
	int GetValueOfHand();

	//-------------------------------------------------------
	// Name: OutPutHand
	// Function: Print out all cards in hand
	// PreCondition: Nothing
	// PostCondition: Output of all cards in hand
	// Returns: Nothing
	//---------------------------------------------------------
	void OutPutHand();

	//-------------------------------------------------------
	// Name: 
	// Function: 
	// PreCondition: 
	// PostCondition: 
	// Returns: 
	//---------------------------------------------------------
	//void GiveCard(Card card);
private:
	std::vector<Card> m_cards;
};

#endif