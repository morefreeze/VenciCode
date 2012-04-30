#ifndef VENCICODE_H
#define VENCICODE_H

#include <QtGui/QMainWindow>
#include "ui_vencicode.h"
#include "VenciGame.h"
#include "CardLabel.h"



class VenciCode : public QMainWindow
{
    Q_OBJECT

public:
    VenciCode(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~VenciCode();
protected:
    VenciGame *pVenciGame;
    GameInfo *pGameInfo;
    QParallelAnimationGroup drawAnimationGroup;

private:
    static const QRect InitDeckRect[(int)COLORMAX];
    Ui::VenciCodeClass ui;
    vector< CardLabel* > cardDecks;
    vector< list<CardLabel*> > cardPlayers;
public slots:
    void DrawCardAnimation(Card*, int);
};

#endif // VENCICODE_H
