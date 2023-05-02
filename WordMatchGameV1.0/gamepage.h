#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>

namespace Ui {
class gamePage;
}

class gamePage : public QWidget
{
    Q_OBJECT

public:
    explicit gamePage(QWidget *parent = nullptr);
    ~gamePage();

private:
    Ui::gamePage *ui;
};

#endif // GAMEPAGE_H
