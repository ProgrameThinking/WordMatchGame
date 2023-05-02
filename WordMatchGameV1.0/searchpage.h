#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>

namespace Ui {
class searchPage;
}

class searchPage : public QWidget
{
    Q_OBJECT

public:
    explicit searchPage(QWidget *parent = nullptr);
    ~searchPage();

private:
    Ui::searchPage *ui;
};

#endif // SEARCHPAGE_H
