#ifndef Card_h__
#define Card_h__

enum CardColor{
    Black = 0,
    White = 1
};
class Card{
private:
    CardColor cardColor;
    int num;
public:
    static const int GANG = 100;
    Card(CardColor, int);
    //Card& operator=(const Card&);
};

#endif // Card_h__

