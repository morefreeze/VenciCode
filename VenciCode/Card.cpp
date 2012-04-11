#include "Card.h"

Card::Card(CardColor color, int n)
{
    cardColor = color;
    num = n;
    IsHide = true;
}

bool Card::operator<( const Card& rhs) const
{
    return num * COLORMAX + cardColor
        < rhs.num * COLORMAX + rhs.cardColor;
}

QString Card::GetNumStr()
{
    if(num == Card::GANG)
        return "-";
    else if(num == Card::DECK)
        return "";
    return QString("%1").arg(num);
}
// extern cmp function
bool PCLess (Card* lhs, Card* rhs)
{
    return (*lhs) < (*rhs);
}