#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>

#include "MainFenetre.hpp"
int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    mainfenetre fenetre;

    return app.exec();
}
