#pragma once

#include "Card.h"

#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int CARDS_PER_DECK = 52;

class CardDeck
{
public:
	CardDeck();
	void Shuffle();
	card DealCard();
	void PrintDeck() const;
private:
	card *Deck;
	int currentCard;
};

void CardDeck::PrintDeck() const
{
	cout << left;
	for (int i = 0; i < CARDS_PER_DECK; i++)
	{
		cout << setw(19) << Deck[i].print();
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
}

CardDeck::CardDeck()
{
	string Faces[] = { "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };
	string Suits[] = { "Clubs","Diamonds","Hearts","Spades" };
	Deck = new card[CARDS_PER_DECK];
	currentCard = 0;
	for (int count = 0; count < CARDS_PER_DECK; count++)
		Deck[count] = card(Faces[count % 13], Suits[count / 13]);
}

void CardDeck::Shuffle()
{
	currentCard = 0;
	for (int first = 0; first < CARDS_PER_DECK; first++)
	{
		int second = (rand() + time(0)) % CARDS_PER_DECK;
		card temp = Deck[first];
		Deck[first] = Deck[second];
		Deck[second] = temp;
	}
}

card CardDeck::DealCard()
{
	if (currentCard > CARDS_PER_DECK)
		Shuffle();
	if (currentCard < CARDS_PER_DECK)
		return(Deck[currentCard++]);
	return(Deck[0]);
}