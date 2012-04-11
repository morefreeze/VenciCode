#include "Player.h"


Player::Player( string name, PutCardMode mode)
{
    playerName = name;
    Mode = mode;
    NeedDraw = 0;
    cards = list<Card*>();
}

void Player::DrawCard( Card* pc)
{
    if(pc == NULL)
        return ;
    //cards.sort(PCCmp);
    int offset = 0;
    list<Card*>::iterator tmpICard = cards.begin();
    for(list<Card*>::iterator iCard = cards.begin();
        iCard != cards.end(); ++iCard)
    {
        if(PCLess(*iCard, pc))
        {
            if(0 != offset)
                ++tmpICard;
            ++offset;
        }
        else
        {
            break;
        }
    }
    cards.insert(tmpICard, pc);
    NeedDraw--;
    emit DrawCardAnimationSign(pc, offset);
}

PlayerStatus Player::Status()
{
    if(status != UNKNOWN)
        return status;
    for(list<Card*>::iterator iCard = cards.begin();
        iCard != cards.end();++iCard)
    {
        const Card* c = *iCard;
        if(c->IsHide)
            return status = LIVING;
    }
    return status = DYING;
}

// reset status UNKNOWN to update
void Player::ResetMode()
{
    if(status != DYING)
        status = UNKNOWN;
}

Player::~Player()
{
    // it will delete at ~VenciGame
    //for(list<Card*>::iterator iCard = cards.begin();
    //    iCard != cards.end();++iCard)
    //    if(NULL != *iCard)
    //        delete *iCard;
    cards.clear();
}

list<Card*> & Player::GetCards()
{
    return cards;
}