#ifndef Player_h__
#define Player_h__

#include "Card.h"
#include "common.h"

enum PlayerStatus{
    UNKNOWN = 0,
    DYING = 1,
    LIVING = 2
};
enum PutCardMode{
    AUTO = 0,
    MANUAL = 1
};

class Player:public QObject{
    Q_OBJECT

private:
    string playerName;
    list<Card*> cards;
    PlayerStatus status;
    
public:
    int NeedDraw;
    PutCardMode Mode;

    Player(string name, PutCardMode);
    ~Player();
    void AddCard(Card*);
    PlayerStatus Status();
    void Reset();
signals:
    void AddCardAnimation(int offset);
};
#endif // Player_h__