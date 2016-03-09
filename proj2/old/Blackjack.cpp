/*****************************************
** File:    Blackjack.cpp
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/21/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
**		This file holds all the logic for the blackjack game,
**	creation and gameplay is handled by this class.
**
http://www.csee.umbc.edu/courses/undergraduate/202/spring14/projects/project2/
http://www.csee.umbc.edu/courses/undergraduate/202/spring14/projects/coding-standards.shtml
***********************************************/
#include "Blackjack.h"

/****************************************************************
 * Name: Blackjack
 *   default (no-arg) constructor
 * Preconditions: none.
 * Postconditions:
 *   Sets up a game with one player: "Jane", starting with $100
 ****************************************************************/
Blackjack::Blackjack()
{
	const int DEFAULT_STARTING_FUNDS = 100;
	totalCardsDealt = 2;
	const char *name = "Jane";

	Player person(*name,DEFAULT_STARTING_FUNDS);
	m_players.push_back(person);
}

/****************************************************************
 * Name: Blackjack
 *   Standard constructor
 * Preconditions:
 *   names -- an array of names specifying the players
 *   numPlayers -- the length of the array "names"
 * Postconditions:
 *   Sets up a game with the specified collection of players
 *   Each player is given a default $100 in funds
 ****************************************************************/
Blackjack::Blackjack(char *names[], int numPlayers)
{
	const int DEFAULT_STARTING_FUNDS = 100;
	totalCardsDealt = 2;

	for (int i = 0; i < numPlayers; i++)
	{
		Player person(*names[i],DEFAULT_STARTING_FUNDS);
		m_players.push_back(person);
	}
}

/****************************************************************
 * GetNumPlayers:
 * Preconditions: none.
 * Postconditions:
 *   Returns: the number of players registered for the game
 ****************************************************************/
int Blackjack::GetNumPlayers()
{
	return m_players.size();
}

/****************************************************************
 * GetPlayerName:
 * Preconditions:
 *   player -- the index of the requested player
 * Postconditions:
 *   Returns: the given player's name
 ****************************************************************/
char *Blackjack::GetPlayerName(int player)
{
	return m_players[player-1].GetName();
}

/****************************************************************
 * GetPlayerFunds
 *   Return the given player's pool of available funds
 * Preconditions:
 *   player -- the index of the requested player
 * Postconditions:
 *   Returns: The amount of funds the player currently has remaining
 ****************************************************************/
int Blackjack::GetPlayerFunds(int player)
{
	return m_players[player].GetMoney();
}

/****************************************************************
 * SetPlayerFunds:
 *   Initialize a players funds for betting
 * Preconditions:
 *   player -- the index of the requested player
 *   amt -- the amount of money player's funds should be set to
 * Postconditions:
 *   Sets the given player's pool of funds available for betting
 ****************************************************************/
void Blackjack::SetPlayerFunds(int player, int amt)
{
	m_players[player].SetMoney(amt);
}

/****************************************************************
 * SetPlayerBet:
 *   Set how much the player wants to bet in current round.
 * Preconditions:
 *   player -- the index of the requested player
 *   amt -- the amount of money player wants to bet;
 *     must be compared against available funds, and rejected
 *     if funds are insufficient.
 * Postconditions:
 *   amount of bet is recorded for the player
 *   Returns: true if bet is valid; false if insufficient funds.
 ****************************************************************/
bool Blackjack::SetPlayerBet(int player, int amt)
{
	return m_players[player].ValidBet(amt);
}

/****************************************************************
 * NewDeal:
 *   Deals out cards in preparation for new round
 * Preconditions: none.
 * Postconditions:
 *   Creates a fresh Deck, shuffles it, and deals out 2 cards
 *   to each player and the dealer, going around the circle
 *   one card at a time (like most card games).
 ****************************************************************/
void Blackjack::NewDeal()
{
	Deck newDeck;

	newDeck.Shuffle();

	for (int j = 0; j < totalCardsDealt; j++)
	{
		for (int i = 0; i < GetNumPlayers(); i++)
		{
			m_players[i].GiveCard(newDeck.DealCard());
		}
	}
}

/****************************************************************
 * OutputPlayerHand:
 *   Displays a player's hand.
 * Preconditions: none.
 *   player -- the index of the requested player
 * Postconditions:
 *   Output the requested player's hand to cout, as a comma-separated
 *   list of cards.  So, it should display something like:
 *   "Ace of Spades, 3 of Diamonds, 5 or Hearts"
 *   Note: just display cards; no label at start, no endl at end.
 ****************************************************************/
void Blackjack::OutputPlayerHand(int player)
{
	m_players[player].OutPutHand();
}

/****************************************************************
 * OutputDealerHand:
 *   Displays dealer's hand.
 * Preconditions: none.
 * Postconditions:
 *   Output the dealer's hand to cout, hiding the hole card (the
 *   second card).  So, it should display something like:
 *   "Ace of Spades, [hidden card]"
 *   Note: just display cards; no label at start, no endl at end.
 ****************************************************************/
/*
 * Parameters: none.
 */
void Blackjack::OutputDealerHand()
{

}

/****************************************************************
 * HitPlayer:
 *   Deal the player another card.
 * Preconditions:
 *   player -- the index of the requested player
 *   Player must not have gone bust earlier; this is a precondition
 *   you are required to check for!
 * Postconditions:
 *   Prints out the new card that was dealt to the player.
 *   Returns: true if player is busted due to new card; false otherwise.
 *   (HINT: it would probably be helpful to record that the player went
 *    bust in some object.)
 ****************************************************************/
bool Blackjack::HitPlayer(int player)
{

}

/****************************************************************
 * DealerPlay
 *   Loop, continuously dealing cards to the Dealer's hand until she stops
 *   because she has 17 or higher.  Output each card that the dealer is
 *   dealt, and display the resulting hand each round, just like main()
 *   does for the players (must do that in here because main() only sees
 *   final result).
 * Preconditions: none.
 * Postconditions:
 *   Dealer might have gone bust, or might have blackjack (in which
 *   case no cards were taken.)
 ****************************************************************/
void Blackjack::DealerPlay()
{

}

/****************************************************************
 * SettlePlayerbet:
 *   At end of round, settle bet for given player:
 *   Compare player's hand to dealer's hand, decide who wins,
 *   then settle bet accordingly by updating the player's funds
 *   based on their bet, outputting results.
 *   Should also zero out the bet in preparation for the next round.
 * Preconditions:
 *   player -- the index of the requested player
 * Postconditions:
 *   Updates the player's funds, by adding or subtracting bet.
 *   Print out player's card total (number, "busted", or "blackjack"),
 *     and the winner ("Joe wins" or "Dealer wins" or "tie").
 *     Examples:
 *       "Joe has busted--Dealer wins", or
 *       "Sally has 21--Sally wins", or
 *     or "Sally has blackjack--tie" if dealer also had blackjack.
 *   Clears the bet amount.
 *   Returns: 0  (return value not really used yet)
 ****************************************************************/
int Blackjack::SettlePlayerBet(int player)
{

}