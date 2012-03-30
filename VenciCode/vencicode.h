#ifndef VENCICODE_H
#define VENCICODE_H

#include <QtGui/QMainWindow>
#include <QPainter>
#include "ui_vencicode.h"
#include "VenciGame.h"


class DeckClickable : public QObject
{
    Q_OBJECT
public:
    DeckClickable(QObject *obj);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
signals:
    void DrawCardSign();
};


class VenciCode : public QMainWindow
{
    Q_OBJECT

public:
    VenciCode(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~VenciCode();
protected:
    VenciGame *pVenciGame;
    GameInfo *pGameInfo;
private:
    Ui::VenciCodeClass ui;
    vector<DeckClickable*> deckClickable;
    vector< list<QLabel*> > cardLabels;
    QLabel* MakeCardLabel(QString, CardColor);
    void DrawNumber(QPixmap*, QString);

};

#endif // VENCICODE_H
