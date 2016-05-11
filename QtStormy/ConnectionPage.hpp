#ifndef CONNECTIONPAGE_H
#define CONNECTIONPAGE_H

#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QHBoxLayout>

class ConnectionPage : public QWidget
{
public:
    ConnectionPage(QMainWindow * window);
    void init();

private:
    QMainWindow * window;
    QLineEdit* ipInputField;
    QHBoxLayout * container;
};

#endif // CONNECTIONPAGE_H
