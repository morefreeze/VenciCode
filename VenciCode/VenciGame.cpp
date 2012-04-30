#include "VenciGame.h"

const int VenciGame::INITCARDNUM[5] = {0};

// GameInfo public


// private method
void VenciGame::InitDeck(unsigned int colorNum,unsigned int digitNum)
{
    for(int i = 0;i < colorNum; ++i)
    {
        vector<Card*> tmpDeck;
        for(int j = 0;j <= digitNum;++j)
            tmpDeck.push_back(new Card((CardColor)i, j));
        tmpDeck.push_back(new Card((CardColor)i, Card::GANG));

        deck.push_back(tmpDeck);
    }
}

bool VenciGame::GameOver()
{
    int livingNum = 0;
    for(int i = 0;i < players.size();++i)
    {
        if(LIVING == players[i]->Status())
            ++livingNum;
    }
    return (livingNum == 1);
}

// public method
VenciGame::VenciGame()
{
    invalidPlayer = new Player("<Invalid Player>", AUTO);
    CurPlayerIdx = 0;
    OwnPlayerIdx = CurPlayerIdx;
    srand(time(NULL));
}

VenciGame::~VenciGame()
{
    delete invalidPlayer;
    for (int i = 0;i < players.size();++i)
    {
        delete players[i];
    }
    players.clear();

    for (int i = 0;i < deck.size();++i)
    {
        for (int j = 0;j < deck[i].size();++j)
        {
            delete deck[i][j];
        }
        deck[i].clear();
    }
    deck.clear();

    delete pGameInfo;
}
void VenciGame::Start(GameInfo* pGI)
{
    pGameInfo = pGI;
    InitDeck(pGameInfo->ColorNum,pGameInfo->DigitNum);
    int playerNum = pGI->PlayerNum;
    for(int i = 0;i < playerNum;++i)
    {
        Player *player = new Player(""+i,AUTO);
        player->NeedDraw = INITCARDNUM[playerNum];
        //for(int j = 0;j < INITCARDNUM[playerNum];++j)
        //    player->AddCard(DrawCard());
        players.push_back(player);
    }
}


void VenciGame::Run()
{
    while(!GameOver())
    {
        while (DYING == players[CurPlayerIdx]->Status())
        {
            CurPlayerIdx = (CurPlayerIdx + 1) % players.size();
        } 
        for(int i = 0;i < players.size(); ++i)
            players[i]->ResetMode();
        Player& curPlayer = *players[CurPlayerIdx];
        
    }
}


GameInfo & VenciGame::GetGameInfo()
{
    return *pGameInfo;
}
Player & VenciGame::GetPlayer( int idx )
{
    if(0 <= idx && idx < players.size())
        return *players[idx];
    return *invalidPlayer;
}

Player & VenciGame::GetOwnPlayer()
{
    if(OwnPlayerIdx < players.size())
        return *players[OwnPlayerIdx];
    return *invalidPlayer;
}

Player & VenciGame::GetCurPlayer()
{
    if(CurPlayerIdx < players.size())
        return *players[CurPlayerIdx];
    return *invalidPlayer;
}

int VenciGame::GetCardNum( CardColor color)
{
    if(color < deck.size())
        return deck[color].size();
    return 0;
}

QString VenciGame::GetCardNumStr( CardColor color)
{
    return QString("%1").arg(GetCardNum(color));
}

//public slots
// swap the card drew and last card, then pop_back
// let current player draw this card
void VenciGame::DrawCard( CardColor color)
{
    if(deck.size() == 0)
        return ;
    int idx = rand() % deck[color].size();
    swap(deck[color][idx], deck[color].back() );
    Card* res = deck[color].back();
    deck[color].pop_back();

    Player &curPlayer = GetCurPlayer();
    curPlayer.DrawCard(res);
}

// public slots end