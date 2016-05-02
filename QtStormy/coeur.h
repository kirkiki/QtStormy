#ifndef COEUR_H
#define COEUR_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QProgressBar>
#include <time.h>

class coeur: public QWidget
{
    Q_OBJECT
    public:
    coeur(int m_value){
        value=m_value;
    }
    coeur();

    private:
    QProgressBar *cpu;
    int value;
};
#endif // COEUR_H
