/*****************************************
** File:    Hand.h
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/20/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   This file contains the declaration for the Hand class.
 *   The class manages and implements the mechanics for a hand of
 *   cards. Removing, counting, and printing is handled
**
***********************************************/
#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include "Card.h"

class Hand
{
public:
    /****************************************************************
     * Name: Hand
     *   default (no-arg) constructor
     ****************************************************************/
    Hand();

    /****************************************************************
     * Name: AddCard
     *   Add cards to players' hand
     * Preconditions: 
     *   Card is a valid card
     * Postconditions:
     *   Card is added to the hand
     ****************************************************************/
    void AddCard(Card newCard);

    /****************************************************************
     * Name: ValueHand
     *   Count cards and return total
     * Preconditions: 
     *   None.
     * Postconditions:
     *   Returns positive integer
     ****************************************************************/
    int ValueHand();

    /****************************************************************
     * Name: PrintCards
     *   Prints user readable versions of cards
     * Preconditions: 
     *   None. 
     * Postconditions:
     *   Prints all cards to console
     ****************************************************************/
    void PrintCards(bool dealer=false);

    /****************************************************************
     * Name: SizeOfHand
     *   Returns size of hand to caller
     * Preconditions: 
     *   None.
     * Postconditions:
     *   Positive integer
     ****************************************************************/
    int SizeOfHand();

    /****************************************************************
     * Name: ClearHand
     *   Dumps all cards in hand
     * Preconditions: 
     *   None.
     * Postconditions:
     *   No cards remaining in hand
     ****************************************************************/
    void ClearHand();

private:
    //Vector for the 'hand'
    std::vector<Card> m_cards;
};

#endif