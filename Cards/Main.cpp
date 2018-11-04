#include <iostream>
#include <string>

#include "CardDeck.h"

using namespace std;

int main()
{
	CardDeck Deck;
	card currentCard;
	cout << "---------------------------Sorted Deck---------------------------\n\n";
	Deck.PrintDeck();
	cout << "\n\n--------------------------Shuffled Deck--------------------------\n\n";
	Deck.Shuffle();
	Deck.PrintDeck();
	cout << endl << endl;

	system("pause");
	return 0;
}