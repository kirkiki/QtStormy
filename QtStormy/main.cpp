#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>

#include "MainFenetre.hpp"
int main(int argc, char **argv)
{
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2,2), &wsa);
    if(err < 0){
        puts("WSAStartup failed");
        exit(EXIT_FAILURE);
    }
#endif
    QApplication app (argc, argv);

    mainfenetre fenetre;

    return app.exec();
}
