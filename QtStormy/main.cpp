#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>

#include "mainfenetre.h"
int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 mainfenetre fenetre;



/*
 QWidget fenetre;

     QProgressBar *core1 = new QProgressBar();
     QProgressBar *core2 = new QProgressBar();
     QProgressBar *core3 = new QProgressBar();
     QProgressBar *core4 = new QProgressBar();

     core1->setMinimum(0);
     core2->setMinimum(0);
     core3->setMinimum(0);
     core4->setMinimum(0);

     core1->setMaximum(99);
     core2->setMaximum(99);
     core3->setMaximum(99);
     core4->setMaximum(99);

     core1->setValue(20);
     core2->setValue(45);
     core3->setValue(90);
     core4->setValue(80);

     QLineEdit *ssh=new QLineEdit;

     QGridLayout *layout = new QGridLayout;
     layout->addWidget(ssh,3,0,1,3);
     layout->addWidget(core1, 0, 5);
     layout->addWidget(core2, 1, 5);
     layout->addWidget(core3, 2, 5);
     layout->addWidget(core4, 3, 5);




     fenetre.setLayout(layout);
     */

     //fenetre.show();


     return app.exec();
}
