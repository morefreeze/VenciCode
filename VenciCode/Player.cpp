#include "Player.h"


Player::Player( string name, PutCardMode mode)
{
    playerName = name;
    Mode = mode;
    NeedDraw = 0;
    cards = list<Card*>();
}

void Player::AddCard( Card* pc)
{
    if(pc == NULL)
        return ;
    cards.push_back(pc);
    //cards.sort(PCCmp);
    int cnt = 0;
    for(list<Card*>::reverse_iterator iCard = cards.rbegin();
        iCard != cards.rend(); ++iCard)
    {
        if(PCLess(pc, *iCard))
        {
            swap(pc,*iCard);
            pc = *iCard;
        }
        else
            ++cnt;
    }
    emit AddCardAnimation(cnt);
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

Player::~Player()
{
    for(list<Card*>::iterator iCard = cards.begin();
        iCard != cards.end();++iCard)
        delete *iCard;
}