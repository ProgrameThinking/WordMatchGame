#ifndef TESTERPAGE_H
#define TESTERPAGE_H

#include <QWidget>

namespace Ui {
class testerPage;
}

class testerPage : public QWidget
{
    Q_OBJECT

public:
    explicit testerPage(QWidget *parent = nullptr);
    ~testerPage();

private:
    Ui::testerPage *ui;
};

#endif // TESTERPAGE_H
