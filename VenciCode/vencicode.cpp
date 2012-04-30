#include "vencicode.h"

const QRect VenciCode::InitDeckRect[] = {QRect(10,10,64,100),QRect(10,130,64,100)};

VenciCode::VenciCode(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

    pVenciGame = new VenciGame();
    pGameInfo = new GameInfo(2,11,2);
    pVenciGame->Start(pGameInfo);
    for (int i = 0;i < pGameInfo->PlayerNum;++i)
    {
        cardPlayers.push_back(list<CardLabel*>());
    }

    // add deck label manual
    CardLabel *pCardDeck = NULL;
    for(int i = 0;i < COLORMAX;++i)
    {
        pCardDeck = new CardLabel(new Card((CardColor)i,Card::DECK),
            0, 
            InitDeckRect[i]);
        pCardDeck->setParent(ui.DeckArea);
        connect(pCardDeck, SIGNAL(DrawCardSign(CardColor)),
            pVenciGame, SLOT(DrawCard(CardColor)));
        cardDecks.push_back(pCardDeck);
    }

    connect(&pVenciGame->GetCurPlayer(), SIGNAL(DrawCardAnimationSign(Card*, int)),
        this, SLOT(DrawCardAnimation(Card*,int)));

    
    //QPixmap *tmpPixmap;
    //tmpPixmap = const_cast<QPixmap*>(ui.BlackDeck->pixmap());
    //CardLabel::DrawNumber(tmpPixmap, pVenciGame->GetCardNumStr(BLACK));
    //    //QString("%1").arg(pVenciGame->GetCardNum(BLACK)));
    //tmpPixmap = const_cast<QPixmap*>(ui.WhiteDeck->pixmap());
    //CardLabel::DrawNumber(tmpPixmap, pVenciGame->GetCardNumStr(WHITE));
    //    //QString("%1").arg(pVenciGame->GetCardNum(WHITE)));

}



VenciCode::~VenciCode()
{
    delete pVenciGame;
}


//public slots
void VenciCode::DrawCardAnimation( Card* pc, int offset )
{
    drawAnimationGroup.clear();

    CardLabel* pNewCard = new CardLabel(pc, offset, InitDeckRect[pc->GetColor()]);
    if(pVenciGame->OwnPlayerIdx == pVenciGame->CurPlayerIdx)
        pNewCard->setParent(ui.OwerArea);
    else pNewCard->setParent(ui.OpponentArea);
    
    list<Card*> &curCards = pVenciGame->GetCurPlayer().GetCards();
    list<Card*>::iterator iCurCard = curCards.begin();
    list<CardLabel*>::iterator pCurCardLabel = 
        cardPlayers[pVenciGame->CurPlayerIdx].begin();
    list<CardLabel*>::iterator pCurCardLabelEnd = 
        cardPlayers[pVenciGame->CurPlayerIdx].end();
    list<CardLabel*>::iterator pLastCardLabel =
        cardPlayers[pVenciGame->CurPlayerIdx].begin();
    QPropertyAnimation *moveRightAnimation = NULL;

    for (int i = 0;pCurCardLabel != pCurCardLabelEnd && i < curCards.size(); ++i,++iCurCard,++pCurCardLabel)
    {
        if(i >= offset)
        {
            moveRightAnimation = new QPropertyAnimation(*pCurCardLabel,"geometry");
            moveRightAnimation->setDuration(500);
            QRect rect = (*pCurCardLabel)->geometry();
            moveRightAnimation->setStartValue(rect);
            rect.moveLeft(rect.x() + 60);
            moveRightAnimation->setEndValue(rect);
            drawAnimationGroup.addAnimation(moveRightAnimation);
        }
        else if(i > 0) pLastCardLabel++;
        (*pCurCardLabel)->show();
    }
    QPropertyAnimation *insertAnimation = new QPropertyAnimation(pNewCard, "geometry");
    insertAnimation->setDuration(500);
    QRect rect = pNewCard->geometry();
    rect.setX(64*offset + 10);
    rect.setY(10+100);
    insertAnimation->setStartValue(rect);
    rect.moveTo(QPoint( (64*offset + 74), (10) ) );
    insertAnimation->setEndValue(rect);
    drawAnimationGroup.addAnimation(insertAnimation);
    pNewCard->show();
        
    drawAnimationGroup.start();
    //while(drawAnimationGroup.state() == QAbstractAnimation::Running);
    


    cardPlayers[pVenciGame->CurPlayerIdx].insert(
        pLastCardLabel, pNewCard);
        

}



//public slots end