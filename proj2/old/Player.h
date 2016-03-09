/*****************************************
** File:    Player.h
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/20/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
**      This file holds all the definitions for the player class
**
***********************************************/
//-------------------------------------------------------
// Name: 
// Function: 
// PreCondition:  
// PostCondition: 
// Returns:
//---------------------------------------------------------
#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Hand.h"

class Player
{
public:
	//Constructors
	Player();
	Player(char name, int money);

	//-------------------------------------------------------
	// Name: GetMoney
	// Function: Returns the total amount of money the user has
	// PreCondition:  User has valid amount of funds
	// PostCondition: Gives a positive integer
	// Returns: integer of funds
	//---------------------------------------------------------
	int GetMoney() const;

	//-------------------------------------------------------
	// Name: TakeMoney
	// Function: Removes money from the player's funds
	// PreCondition: Valid positive integer
	// PostCondition: Number is taken out of the account.
	// Returns: Nothing
	//---------------------------------------------------------
	void TakeMoney(const int amount);

	//-------------------------------------------------------
	// Name: AddMoney
	// Function: Removes money from the player's funds
	// PreCondition: Valid positive integer
	// PostCondition: Number is added to the account.
	// Returns: Nothing
	//---------------------------------------------------------
	void AddMoney(const int amount);

	//-------------------------------------------------------
	// Name: GetName
	// Function: Returns pointer to copied name
	// PreCondition: None
	// PostCondition: A valid pointer to the players' name
	// Returns: Pointer to name
	//---------------------------------------------------------
	char GetName();

	//-------------------------------------------------------
	// Name: SetName
	// Function: Set the players' name
	// PreCondition: Name is pointer to character name
	// PostCondition: Name is set
	// Returns: None
	//---------------------------------------------------------
	void SetName(char *name);

	//-------------------------------------------------------
	// Name: SetMoney
	// Function: Sets funds for the player to a specific integer
	// PreCondition: Valid integer
	// PostCondition: Players funds will be set to given number
	// Returns: Nothing
	//---------------------------------------------------------
	void SetMoney(const int money);

	//-------------------------------------------------------
	// Name: ValidBet
	// Function: Tells if number is a valid bet
	// PreCondition: Given a good integer
	// PostCondition: Boolean of whether it is a valid bet
	// Returns: Nothing
	//---------------------------------------------------------
	bool ValidBet(const int amount);

	//-------------------------------------------------------
	// Name: GiveCard
	// Function: Add card to players hand
	// PreCondition: Card is a valid card
	// PostCondition: Card is added to the hand
	// Returns: Nothing
	//---------------------------------------------------------
	void GiveCard(Card card);

	//-------------------------------------------------------
	// Name: OutPutHand
	// Function: Print out all cards in hand
	// PreCondition: Nothing
	// PostCondition: Output of all cards in hand
	// Returns: Nothing
	//---------------------------------------------------------
	void OutPutHand();

private:
	int m_funds;
	int playerBet;
	char *m_playerName;

	Hand m_hand;

	//-------------------------------------------------------
	// Name: ModifyMoney
	// Function: Modify money value
	// PreCondition: Given valid integer
	// PostCondition: Will modify the money to exact values
	// Returns: Nothing
	//---------------------------------------------------------
	void ModifyMoney(const int amount);
};
#endif