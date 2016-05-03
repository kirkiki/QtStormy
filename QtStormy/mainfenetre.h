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
#include <QTabWidget>
#include <QHBoxLayout>


#include "coeur.h"

class mainfenetre: public QMainWindow
{
    Q_OBJECT

    public:
    mainfenetre();

public slots:
    void onTimeOut();
    void onConnexion();

private:
    QWidget *fenetre;

    QTabWidget *onglets;
    QWidget *page1;
    QWidget *page2;
    QWidget *page3;

    QGridLayout *grille;
    QProgressBar *core1;
    QProgressBar *core2;
    QProgressBar *core3;
    QProgressBar *core4;

    QHBoxLayout *box;
    QLineEdit *ipadd;
    QPushButton *seConnecter;





};

#endif // MAINFENETRE_H

