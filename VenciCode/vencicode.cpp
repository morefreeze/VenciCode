#include "vencicode.h"


DeckClickable::DeckClickable(QObject *obj)
{

}

bool DeckClickable::eventFilter(QObject *obj, QEvent *event)
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
    
    pVenciGame = new VenciGame();
    pGameInfo = new GameInfo(2,13,2);
    pVenciGame->Start(pGameInfo);
    QPixmap *tmpPixmap;
    tmpPixmap = const_cast<QPixmap*>(ui.BlackDeck->pixmap());
    DrawNumber(tmpPixmap, ""+BLACK);
        //QString("%1").arg(pVenciGame->GetCardNum(BLACK)));
    tmpPixmap = const_cast<QPixmap*>(ui.WhiteDeck->pixmap());
    DrawNumber(tmpPixmap, ""+WHITE);
        //QString("%1").arg(pVenciGame->GetCardNum(WHITE)));

    DeckClickable *tmpClickable;
    tmpClickable = new DeckClickable(this);
    ui.BlackDeck->installEventFilter(tmpClickable);
    connect(tmpClickable, SIGNAL(DrawCardSign()),
        pVenciGame, SLOT(DrawCard()) );

}



VenciCode::~VenciCode()
{
    delete pGameInfo;
    delete pVenciGame;
}

QLabel* VenciCode::MakeCardLabel( QString str, CardColor color)
{
    QString resourcePath;
    if(color == (CardColor)BLACK)
        resourcePath = QString::fromUtf8(":/VenciCode/Resources/Cards/black_bg.png");
    else
        resourcePath = QString::fromUtf8(":/VenciCode/Resources/Cards/white_bg.png");
    QPixmap *cardImage = new QPixmap(resourcePath);
    DrawNumber(cardImage, str);
    QLabel* res = new QLabel(this);
    res->setPixmap(*cardImage);
    return res;
}

void VenciCode::DrawNumber( QPixmap *cardImage, QString str)
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