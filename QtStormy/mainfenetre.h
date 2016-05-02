#ifndef MAINFENETRE_H
#define MAINFENETRE_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QMainWindow>
#include <QProgressBar>
#include <QTimer>
#include <QIntValidator>

#include "coeur.h"

class mainfenetre: public QMainWindow
{
    Q_OBJECT

    public:
    mainfenetre();

public slots:
    void onTimeOut();

private:
    QProgressBar *core1;
    QProgressBar *core2;
    QProgressBar *core3;
    QProgressBar *core4;

    QGridLayout *grille;
    QWidget *qw;


};

#endif // MAINFENETRE_H

