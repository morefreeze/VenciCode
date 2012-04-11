#ifndef Card_h__
#define Card_h__

#include "common.h"

enum CardColor{
    BLACK = 0,
    WHITE = 1,
    COLORMAX
};
class Card{
private:
    CardColor cardColor;
    int num;
public:
    static const int GANG = 0xff;
    static const int DECK = 0xffff;
    Card(CardColor color, int num);
    bool IsHide;
    bool operator<(const Card&) const;
    int GetNum(){ return num; }
    QString GetNumStr();
    CardColor GetColor(){ return cardColor; }
    //Card& operator=(const Card&);
};

// it cannot overload operator< about pointer, so...
bool PCLess (Card* lhs, Card* rhs);

#endif // Card_h__

