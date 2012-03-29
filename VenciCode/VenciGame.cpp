#include "VenciGame.h"

const int VenciGame::INITCARDNUM[5] = {0};

// GameInfo public


// private method
void VenciGame::InitDeck(unsigned int colorNum,unsigned int digitNum)
{
    for(int i = 0;i < colorNum; ++i)
    {
        for(int j = 1;j < digitNum+1;++j)
            deck.push_back(new Card((CardColor)i, j));
        deck.push_back(new Card((CardColor)i, Card::GANG));
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
    curPlayerIdx = 0;
    srand(time(NULL));
}

VenciGame::~VenciGame()
{

}
void VenciGame::Start(GameInfo* pGI)
{
    pGameInfo = pGI;
    InitDeck(pGameInfo->ColorNum,pGameInfo->DigitNum);
    int playerNum = pGI->PlayerNum;
    for(int i = 0;i < playerNum;++i)
    {
        Player *player = new Player(""+i,AUTO);
        for(int j = 0;j < INITCARDNUM[playerNum];++j)
            player->AddCard(DrawCard());
        players.push_back(player);
    }
}

Card* VenciGame::DrawCard()
{
    if(deck.size() == 0)
        return NULL;
    int idx = rand() % deck.size();
    swap(deck[idx], deck.back() );
    Card* res = deck.back();
    deck.pop_back();
    return res;
}

void VenciGame::Run()
{
    while(!GameOver())
    {
        while (DYING == players[curPlayerIdx]->Status())
        {
            curPlayerIdx = (curPlayerIdx + 1) % players.size();
        } 
        for(int i = 0;i < players.size(); ++i)
            players[i]->Reset();
        Player& curPlayer = *players[curPlayerIdx];
        curPlayer.AddCard(DrawCard());
        
    }
}