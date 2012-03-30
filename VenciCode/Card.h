#ifndef Card_h__
#define Card_h__

enum CardColor{
    BLACK = 0,
    WHITE = 1,
    COLORMAX = 16
};
class Card{
private:
    CardColor cardColor;
    int num;
public:
    static const int GANG = 0xff;
    Card(CardColor, int);
    bool isHide;
    bool operator<(const Card&) const;
    //Card& operator=(const Card&);
};

// it cannot overload operator< about pointer, so...
bool PCLess (Card* lhs, Card* rhs);

#endif // Card_h__

