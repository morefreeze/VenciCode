#include "vencicode.h"


Clickable::Clickable(QObject *obj)
{

}

bool Clickable::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        emit DrawCardSign();
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}


VenciCode::VenciCode(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

}



VenciCode::~VenciCode()
{

}

QLabel* VenciCode::MakeCardLabel( QString str, CardColor color)
{
    QPixmap *cardImage = new QPixmap(QString::fromUtf8(":/VenciCode/Resources/Cards/black_bg.png"));
    QPainter q;
    QRect rect(8,32,64,64);
    q.begin(cardImage);
    q.setPen(QColor(255,255,255));
    QFont font = QApplication::font();
    font.setPixelSize( rect.height() );
    q.setFont( font );
    q.drawText(rect,Qt::AlignCenter,str);
    q.end();
    QLabel* res = new QLabel(this);
    res->setPixmap(*cardImage);
    return res;
}