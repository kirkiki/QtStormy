#include "ConnectionPage.hpp"

ConnectionPage::ConnectionPage(QMainWindow* window) : QWidget()
{
    this->window = window;
    container = new QHBoxLayout();
    ipInputField = new QLineEdit();

}

void ConnectionPage::init(){
    ipInputField->setInputMask("000.000.000.000; ");
    ipInputField->setMaximumWidth(100);
    container->addWidget(ipInputField);
    //container->addWidget(seConnecter);
}
