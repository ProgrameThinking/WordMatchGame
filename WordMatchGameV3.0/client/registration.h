#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class registration;
}

class registration : public QWidget
{
    Q_OBJECT

public:
    explicit registration(QTcpSocket* m_tcp,QWidget *parent = nullptr);
    ~registration();

private:
    Ui::registration *ui;
    QTcpSocket* tcp;
    void userRegister();
    void transPage();
};

#endif // REGISTRATION_H
