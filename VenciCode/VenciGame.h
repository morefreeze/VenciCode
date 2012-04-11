#ifndef VenciGame_h__
#define VenciGame_h__

#include "Card.h"
#include "Player.h"
#include "common.h"

class GameInfo{
private:
public:
    unsigned int ColorNum;
    unsigned int DigitNum;
    unsigned int PlayerNum;
    GameInfo::GameInfo(int colorNum,int digitNum,int playerNum)
    {
        ColorNum = colorNum;
        DigitNum = digitNum;
        PlayerNum = playerNum;
    }

};

class VenciGame:public QObject{
    Q_OBJECT

private:
    static const int INITCARDNUM[5];
    GameInfo *pGameInfo;
    vector< vector<Card*> > deck;
    vector<Player*> players;
    Player *invalidPlayer;

    // method
    void InitDeck(unsigned int,unsigned int DigitNum);
    bool GameOver();
public:
    int CurPlayerIdx;
    int OwnPlayerIdx;
    VenciGame();
    ~VenciGame();
    void Start(GameInfo*);
    void Run();
    GameInfo &GetGameInfo();
    Player &GetPlayer(int idx);
    Player &GetOwnPlayer();
    Player &GetCurPlayer();
    int GetCardNum(CardColor);
    QString GetCardNumStr(CardColor);
public slots:
    void DrawCard(CardColor);

};
#endif // VenciGame_h__