#include "Player.h"


Player::Player( string name, PutCardMode mode)
{
    playerName = name;
    Mode = mode;
    cards = list<Card*>();
}

void Player::AddCard( Card* pc)
{
    if(pc == NULL)
        return ;
    cards.push_back(pc);
    cards.sort(PCCmp);
}

PlayerStatus Player::Status()
{
    if(status != UNKNOWN)
        return status;
    for(list<Card*>::iterator iCard = cards.begin();
        iCard != cards.end();++iCard)
    {
        const Card* c = *iCard;
        if(c->isHide)
            return status = LIVING;
    }
    return status = DYING;
}

// reset status UNKNOWN to update
void Player::Reset()
{
    if(status != DYING)
        status = UNKNOWN;
}