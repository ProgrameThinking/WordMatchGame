#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class registration;
}

class registration : public QWidget
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private:
    Ui::registration *ui;
};

#endif // REGISTRATION_H
