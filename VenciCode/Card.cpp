#include "Card.h"

Card::Card(CardColor cc, int n)
{
    cardColor = cc;
    num = n;
    isHide = true;
}

bool Card::operator<( const Card& rhs) const
{
    return num * COLORMAX + cardColor
        < rhs.num * COLORMAX + rhs.cardColor;
}

// extern cmp function
bool PCCmp (Card* lhs, Card* rhs)
{
    return (*lhs) < (*rhs);
}