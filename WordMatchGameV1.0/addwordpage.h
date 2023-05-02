#ifndef ADDWORDPAGE_H
#define ADDWORDPAGE_H

#include <QWidget>

namespace Ui {
class addWordPage;
}

class addWordPage : public QWidget
{
    Q_OBJECT

public:
    explicit addWordPage(QWidget *parent = nullptr);
    ~addWordPage();

private:
    Ui::addWordPage *ui;
};

#endif // ADDWORDPAGE_H
