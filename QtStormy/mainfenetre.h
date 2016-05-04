#ifndef MAINFENETRE_H
#define MAINFENETRE_H
#include <iostream>
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
#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>
#include <string>
#include <QDataStream>


#include "coeur.h"

class mainfenetre: public QMainWindow
{
    Q_OBJECT

    public:
    mainfenetre();

public slots:
    void onTimeOut();
    void onConnexion();
    void receive();

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

    QUdpSocket *sendSocket;
    QUdpSocket *receiveSocket;
    QHostAddress *add;
    QByteArray *datagram;
    std::string *s;

    std::uint32_t prctCoeur1;
    std::uint32_t prctCoeur2;
    std::uint32_t prctCoeur3;
    std::uint32_t prctCoeur4;






};

#endif // MAINFENETRE_H

