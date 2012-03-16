#include "Deck.h"

Deck::Deck(unsigned int ColorNum,unsigned int DigitNum)
{
    for(int i = 0;i < ColorNum; ++i)
    {
        for(int j = 1;j < DigitNum+1;++j)
            cards.push_back(Card((CardColor)i, j));
        cards.push_back(Card((CardColor)i, Card::GANG));
    }
    srand(time(NULL));
}

Card& Deck::GetRandomCard()
{
    int idx = rand() % cards.size();
    swap(cards[idx], cards.back() );
    Card* res = new Card(cards.back());
    cards.pop_back();
    return *res;
    //Card res = 
}