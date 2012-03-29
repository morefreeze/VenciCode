#ifndef VENCICODE_H
#define VENCICODE_H

#include <QtGui/QMainWindow>
#include <QPainter>
#include "ui_vencicode.h"
#include "VenciGame.h"


class Clickable : public QObject
{
    Q_OBJECT
public:
    Clickable(QObject *obj);
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
    VenciGame *vg;
    GameInfo *gi;
private:
    Ui::VenciCodeClass ui;
    vector< list<QLabel*> > cardLabels;
    QLabel* MakeCardLabel(QString, CardColor);

};

#endif // VENCICODE_H
