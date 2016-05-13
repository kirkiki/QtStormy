#ifndef CONNECTIONPAGE_H
#define CONNECTIONPAGE_H

#include <QWidget>
#include <QObject>

class DataWidget;
class QWidget;
class QUdpSocket;
class QHBoxLayout;
class QLineEdit;
class QPushButton;
class QHostAddress;
class QTimer;
class mainfenetre;
class ConnectionWidget : public QWidget
{
    Q_OBJECT
public:
    ConnectionWidget(mainfenetre * master);

public slots:
    void onTimeAliveOver();
    void onReceive();
    void onConnexion();

private:
    mainfenetre * master;
    DataWidget * dataWidgets;



    QUdpSocket * receiveSocket;
    QHBoxLayout * container;
    QLineEdit* ipInputField;
    QPushButton * connectionButton;






    QHostAddress *add;
    QTimer *timerIsAlive;
};

#endif // CONNECTIONPAGE_H
