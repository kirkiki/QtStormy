#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>

#include "Api/UDPSocket.hpp"

#include "MainFenetre.hpp"
int main(int argc, char **argv)
{
    UDPSocket::init();
    QApplication app (argc, argv);

    mainfenetre fenetre;

    return app.exec();
    UDPSocket::end();
}
