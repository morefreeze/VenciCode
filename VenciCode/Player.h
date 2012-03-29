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

class Player{
private:
    string playerName;
    list<Card*> cards;
    PlayerStatus status;
    
public:
    PutCardMode Mode;
    Player(string name, PutCardMode);
    void AddCard(Card*);
    PlayerStatus Status();
    void Reset();
};
#endif // Player_h__