#ifndef Deck_h__
#define Deck_h__

#include "Card.h"
#include <ctime>
#include <vector>
using namespace std;

class Deck{
private:
    vector<Card> cards;
public:
    Deck(unsigned int ColorNum,unsigned int DigitNum);
    Card& GetRandomCard();
};
#endif // Deck_h__