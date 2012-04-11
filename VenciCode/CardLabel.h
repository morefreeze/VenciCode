#include <QtGui/QMainWindow>
#include <QApplication>
#include <QtGui/QLabel>
#include <QEvent>
#include <QPainter>
#include "common.h"
#include "Card.h"


class CardLabel: public QLabel
{
    Q_OBJECT
public:
    CardLabel(Card* pc,int offset, QRect rect);
    static void DrawNumber(QPixmap*, QString);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Card* pCard;
signals:
    void DrawCardSign(CardColor);
};
