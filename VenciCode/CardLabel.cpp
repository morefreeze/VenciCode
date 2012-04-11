#include "CardLabel.h"


CardLabel::CardLabel( Card* pc, int offset, QRect rect)
{
    QString resourcePath;
    if(pc->GetColor() == BLACK)
    {
        resourcePath = QString::fromUtf8(":/VenciCode/Resources/Cards/black_bg.png");
    }
    else if(pc->GetColor() == WHITE)
    {
        resourcePath = QString::fromUtf8(":/VenciCode/Resources/Cards/white_bg.png");
    }
    QPixmap *cardImage = new QPixmap(resourcePath);
    DrawNumber(cardImage, pc->GetNumStr());
    setPixmap(*cardImage);
    setGeometry(rect);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setSizePolicy(sizePolicy);
    pCard = pc;
    this->installEventFilter(this);
}

bool CardLabel::eventFilter( QObject *obj, QEvent *event )
{
    if (event->type() == QEvent::MouseButtonPress) {
        switch(pCard->GetNum())
        {
        // click a deck
        case Card::DECK:
            emit DrawCardSign(pCard->GetColor());
            break;
        // the rest are player card
        default:

            break;
        }
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}

void CardLabel::DrawNumber( QPixmap *cardImage, QString str)
{
    QPainter q;
    QRect rect(8,18,48,48);
    q.begin(cardImage);
    QRgb bgColor = cardImage->copy(20,20,1,1).toImage().pixel(0,0);
    q.setPen(QColor(~bgColor));
    QFont font = QApplication::font();
    font.setPixelSize( rect.height() );
    q.setFont( font );
    q.drawText(rect,Qt::AlignCenter,str);
    q.end();
}
