/*****************************************
** File:    Player.h
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/20/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   This file contains the declaration for the Player class.
 *   The class manages and implements the mechanics for a player
 *    such as the interface with the hand and holding values
**
***********************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Card.h"

class Player
{
public:
	/****************************************************************
     * Name: Player
     *   default (no-arg) constructor
     ****************************************************************/
	Player();

	/****************************************************************
     * Name: Player
     *   Default constructor w/ arguments
     * Preconditions: 
     *	 name - pointer to name
     * Postconditions:
     *   
     ****************************************************************/
	Player(char *name, int funds);

	/****************************************************************
     * Name: SetName
     *   Sets player name
     * Preconditions: 
     *	 name- pointer to name
     * Postconditions:
     *   Player name is set
     ****************************************************************/
     void SetName(char *name);

     /****************************************************************
     * Name: GetName
     *   Returns pointer to name
     * Preconditions: 
     *	 none.
     * Postconditions:
     *   returns pointer to the players name
     ****************************************************************/
     char *GetName();

     /****************************************************************
     * Name: SetFunds
     *   Sets players funds
     * Preconditions: 
     *	 number - positive integer
     * Postconditions:
     *   Player funds is set to given number
     ****************************************************************/
     void SetFunds(int number);

     /****************************************************************
     * Name: GetFunds
     *   Returns player funds
     * Preconditions: 
     *	 none.
     * Postconditions:
     *   Returns integer of player funds
     ****************************************************************/
     int GetFunds();

     /****************************************************************
     * Name: SetBet
     *   Sets player bets
     * Preconditions: 
     *	 number - valid positive integer ** (Validity isn't checked)
     * Postconditions:
     *   bet is set to number given
     ****************************************************************/
     void SetBet(int number);

     /****************************************************************
     * Name: GetBet
     *   Gets player bet
     * Preconditions: 
     *	 none.
     * Postconditions:
     *   Returns interger of player bet
     ****************************************************************/
     int GetBet();

     /****************************************************************
     * Name: ValidBet
     *   Determines if number given is a valid bet
     * Preconditions: 
     *	 number - an integer
     * Postconditions:
     *    Returns if number is positive and valid for betting
     ****************************************************************/
     bool ValidBet(int number);

     /****************************************************************
     * Name: GiveCard
     *   Add card to players hand
     * Preconditions: 
     *     card- Valid card
     * Postconditions:
     *   Card is added to hand
     ****************************************************************/
     void GiveCard(Card card);

     /****************************************************************
     * Name: OutputHand
     *   Prints out entire hand
     * Preconditions: 
     *     dealer - if we're printing for the dealer
     * Postconditions:
     *   none.
     ****************************************************************/
     void OutputHand(bool dealer=false);

     /****************************************************************
     * Name: GetHandValue
     *   Get numeric hand values
     * Preconditions: 
     *     Gets value of entire hand
     * Postconditions:
     *   returns integer of hand
     ****************************************************************/
     int GetHandValue();

     /****************************************************************
     * Name: GetFancyHandValue
     *   Prints fancy values for hand
     * Preconditions: 
     *     none.
     * Postconditions:
     *   none.
     ****************************************************************/
     void GetFancyHandValue();

     /****************************************************************
     * Name: GetHandSize
     *   Returns amount of card that are in the hand
     * Preconditions: 
     *     none.
     * Postconditions:
     *   returns integer of cards
     ****************************************************************/
     int GetHandSize();

     /****************************************************************
     * Name: Busted
     *   Tells object the player has busted
     * Preconditions: 
     *     none.
     * Postconditions:
     *   player is busted
     ****************************************************************/
     void Busted();

     /****************************************************************
     * Name: IsBusted
     *   Returns if player is busted
     * Preconditions: 
     *     none.
     * Postconditions:
     *   boolean if player is busted
     ****************************************************************/
     bool IsBusted();

     /****************************************************************
     * Name: ResetGame
     *   Resets hand and busted, does not reset funds, or bet value
     * Preconditions: 
     *     none.
     * Postconditions:
     *   m_hand is empty
     *    m_busted is false
     ****************************************************************/
     void ResetGame();

private:
     //Player name
	char *m_name;

     //Money variables
	int m_funds;
	int m_currentBet;

     //Busted boolean
     bool m_busted;

     //Player's hand
     Hand m_hand;
};

#endif