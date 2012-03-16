#ifndef VENCICODE_H
#define VENCICODE_H

#include <QtGui/QMainWindow>
#include "ui_vencicode.h"

class VenciCode : public QMainWindow
{
    Q_OBJECT

public:
    VenciCode(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~VenciCode();

private:
    Ui::VenciCodeClass ui;

    
};

#endif // VENCICODE_H
