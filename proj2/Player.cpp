/*****************************************
** File:    Player.cpp
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/20/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   This file contains the declaration for the Player class.
 *   The class manages and implements the mechanics for a player
 *	 such as the interface with the hand and holding values
**
***********************************************/
#include "Player.h"
#include <iostream>

//Player
//Default constructor
Player::Player()
{
	
}

//Player
//Constructor with default values
Player::Player(char *name, int funds)
{
	m_name = name;
	m_funds = funds;
	m_busted = false;
}

//SetName
//Set player name
void Player::SetName(char *name)
{
	m_name = name;
}

//GetName
//Returns player name
char *Player::GetName()
{
	return m_name;
}

//SetFunds
//Sets players funds
void Player::SetFunds(int number)
{
	m_funds = number;
}

//GetFunds
//Returns players funds
int Player::GetFunds()
{
	return m_funds;
}

//SetBet
//Sets current bet for player
void Player::SetBet(int number)
{
	m_currentBet = number;
}

//GetBet
//Returns bet amount
int Player::GetBet()
{
	return m_currentBet;
}

//ValidBet
//Determines if bet is valid
bool Player::ValidBet(int number)
{
	//If subtraction of funds >= 0 and number is positive or 0
	return (m_funds - number >= 0 && number >= 0);
}

//GiveCard
//Add card to hand
void Player::GiveCard(Card card)
{
	m_hand.AddCard(card);
}

//OutputHand
//Print cards from hand
void Player::OutputHand(bool dealer)
{
	m_hand.PrintCards(dealer);
}

//GetHandValue
//Return entire value of hand
int Player::GetHandValue()
{
	return m_hand.ValueHand();
}

//GetFancyHandValue
//Prints out hand value with text
void Player::GetFancyHandValue()
{
	//If 21, print blackjack instead of number
	if(m_hand.ValueHand() == 21)
	{
		std::cout << "blackjack";
	}
	else
	{
		std::cout << m_hand.ValueHand();
	}
}

//GetHandSize
//Returns amount of cards in hand
int Player::GetHandSize()
{
	return m_hand.SizeOfHand();
}

//Busted
//Tells the object the player has been busted
void Player::Busted()
{
	m_busted = true;
}

//IsBusted
//Returns whether player is busted
bool Player::IsBusted()
{
	return m_busted;
}

//ResetGame
//Resets hand and bust, keeping funds.
void Player::ResetGame()
{
	m_hand.ClearHand();
	m_busted = false;
}