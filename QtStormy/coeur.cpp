//dzdzd                                                                                                                                                                                                                                                                                        
#include "coeur.h"

coeur::coeur(): QWidget()
{
    //m_pushbutton= new QPushButton("test",this);
    //connect(m_pushbutton,SIGNAL(clicked()),this,SLOT(Afficher()));
    cpu = new QProgressBar();
    cpu->setValue(value);
    cpu->setMinimum(0);
    cpu->setMaximum(100);


}

