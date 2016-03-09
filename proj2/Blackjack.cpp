/*****************************************
** File:    Blackjack.cpp
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/20/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   This file contains the declaration for the Blackjack class.
 *   The class manages and implements the mechanics for a multi-player
 *   version of the Blackjack/21 program, including bets.
**
***********************************************/

#include "Blackjack.h"
#include <iostream>
#include <stdlib.h> 

static const int STARTING_MONEY = 100;
static const int BLACKJACK = 21;
static const int SOFT_STAY = 17;
//Blackjack
//default (no-arg) constructor
Blackjack::Blackjack()
{
	std::cout << "default" << std::endl;
	char name[] = "Jane";
	Player person(name,STARTING_MONEY);
	m_players.push_back(person);
}

//Blackjack
//Constructor that deals with creating players
Blackjack::Blackjack(char *names[], int numPlayers)
{
	if(numPlayers > 0)
	{
		//Go through each person applying the changes
		for (int i = 0; i < numPlayers; i++)
		{
			Player person(names[i],STARTING_MONEY);
			m_players.push_back(person);
		}
	}
	else
	{
		Blackjack();
	}
}

//GetNumPlayers
//Returns amount of players not including dealer
int Blackjack::GetNumPlayers()
{
	return m_players.size();
}

//GetPlayerName
//Returns pointer to players name.
char *Blackjack::GetPlayerName(int player)
{
	return m_players[player].GetName();
}

//GetPlayerFunds
//Returns player funds
int Blackjack::GetPlayerFunds(int player)
{
	return m_players[player].GetFunds();
}

//SetPlayerFunds
//Sets a specific players' funds to given amount
void Blackjack::SetPlayerFunds(int player, int amt)
{
	m_players[player].SetFunds(amt);
}

//SetPlayerBet
//Sets player bet if it's valid, otherwise return false
bool Blackjack::SetPlayerBet(int player, int amt)
{
	//Check validity of bet
	if(m_players[player].ValidBet(amt))
	{
		//Set it
		m_players[player].SetBet(amt);
		return true;
	}
	else
	{
		return false;
	}
}

//NewDeal
//Deals entire new deck to players and dealer
void Blackjack::NewDeal()
{
	for (int i = 0; i < GetNumPlayers(); i++)
	{
		//Reset bust and hands for all players
		m_players[i].ResetGame();
	}

	//Reset dealer
	m_dealer.ResetGame();

	//Create deck and shuffle it
	m_deck = Deck();
	m_deck.Shuffle();

	//Deal 2 cards to all players
	for(int j = 0; j < 2; j++)
	{
		for (int i = 0; i < GetNumPlayers(); i++)
		{
			if(!(m_deck.CardsLeft() > 0))
			{
				std::cout << "NO CARDS LEFT!" << std::cout;
				exit(EXIT_FAILURE);
			}
			//Deal card to player
			m_players[i].GiveCard(m_deck.DealCard());
		}
		//Deal card to dealer
		m_dealer.GiveCard(m_deck.DealCard());
	}
}

//OutputPlayerHand
//Print out the players hand
void Blackjack::OutputPlayerHand(int player)
{
	m_players[player].OutputHand();
}

//OutputDealerHand
//Output dealer hand
void Blackjack::OutputDealerHand()
{
	//True for dealer flag
	m_dealer.OutputHand(true);
}

//HitPlayer
//Give player a card and checks if they bust
bool Blackjack::HitPlayer(int player)
{
	if(!(m_deck.CardsLeft() > 0))
	{
		std::cout << "NO CARDS LEFT!" << std::cout;
		exit(EXIT_FAILURE);
	}

	//Check if they're already busted
	if(m_players[player].GetHandValue() > BLACKJACK || m_players[player].IsBusted())
	{
		m_players[player].Busted();
		return true;
	}

	//Deal card
	Card dealtCard = m_deck.DealCard();

	//Print the card
	std::cout << std::endl;
	dealtCard.OutputCard();
	std::cout << std::endl;

	//Give the player the new card
	m_players[player].GiveCard(dealtCard);

	//Check to see if they busted from the new card
	if(m_players[player].GetHandValue() > BLACKJACK)
	{
		m_players[player].Busted();
		return true;
	}
	else
	{
		return false;
	}
}

//Dealer Play
//Dealers turn to choose whether to hit/stay
void Blackjack::DealerPlay()
{
	bool quit = false;
	do
	{
		if(!(m_deck.CardsLeft() > 0))
		{
			std::cout << "NO CARDS LEFT!" << std::cout;
			exit(EXIT_FAILURE);
		}

		std::cout << "Dealer's turn:" << std::endl;

		//Print dealers hand
		m_dealer.OutputHand(false);

		if(m_dealer.GetHandValue() < SOFT_STAY)
		{
			std::cout << "\nDealer's play: hit\n" << std::endl;

			//Get new card
			Card dealtCard = m_deck.DealCard();

			//Print that card
			dealtCard.OutputCard();
			std::cout << std::endl;

			//Give card to dealer
			m_dealer.GiveCard(dealtCard);

			if(m_dealer.GetHandValue() > BLACKJACK)
			{
				m_dealer.Busted();
			}
		}
		else
		{
			//If greater than or equal to 17, stay
			quit = true;
			std::cout << "\nDealer's play: stay\n" << std::endl;
		}
	} while(!quit);

	if(m_dealer.IsBusted())
	{
		std::cout << "Dealer has busted." << std::endl;
	}
	else 
	{
		std::cout << "Dealer has " << m_dealer.GetHandValue() << std::endl;
	}
}

//SettlePlayerBet
//Determine who wins the bet, dealer or player.
int Blackjack::SettlePlayerBet(int player)
{
	//Get some initial values for simplicity sake.
	int playerFunds = m_players[player].GetFunds();
	int playerBet = m_players[player].GetBet();
	char *playerName = m_players[player].GetName();

	if(m_players[player].IsBusted())
	{
		std::cout << playerName << " has busted--"
			<< "Dealer wins" << std::endl;

		//Subtract funds
		m_players[player].SetFunds(playerFunds - playerBet);
	}
	//If dealer busts, and player doesn't, player wins
	else if(!m_players[player].IsBusted() && m_dealer.IsBusted())
	{
		std::cout << playerName << " has ";
		m_players[player].GetFancyHandValue();
		std::cout << "--" << "Player wins" << std::endl;

		//Add funds
		m_players[player].SetFunds(playerFunds + playerBet);
	}
	//If player has greater hand value, player wins
	else if(m_players[player].GetHandValue() > m_dealer.GetHandValue())
	{
		std::cout << playerName << " has ";
		m_players[player].GetFancyHandValue();
		std::cout << "--" << "Player wins" << std::endl;

		//Add funds
		m_players[player].SetFunds(playerFunds + playerBet);
	}
	//If dealer has greater hand value, dealer wins
	else if(m_dealer.GetHandValue() > m_players[player].GetHandValue())
	{
		std::cout << playerName << " has ";
		m_players[player].GetFancyHandValue();
		std::cout << "--" << "Dealer wins" << std::endl;

		//Subtract funds
		m_players[player].SetFunds(playerFunds - playerBet);
	}
	//Tie
	else
	{
		if(m_dealer.GetHandSize() < m_players[player].GetHandSize())
		{
			std::cout << playerName << " has ";
			m_players[player].GetFancyHandValue();
			std::cout << "--" << "Dealer wins with less cards" << std::endl;

			//Subtract funds
			m_players[player].SetFunds(playerFunds - playerBet);
		}
		else if (m_dealer.GetHandSize() > m_players[player].GetHandSize())
		{
			std::cout << playerName << " has ";
			m_players[player].GetFancyHandValue();
			std::cout << "--" << "Player wins with less cards" << std::endl;

			//Add funds
			m_players[player].SetFunds(playerFunds + playerBet);
		}
		else
		{
			std::cout << playerName << " has ";
			m_players[player].GetFancyHandValue();
			std::cout << "--" << "tie" << std::endl;
		}
	}

	return 0;
}