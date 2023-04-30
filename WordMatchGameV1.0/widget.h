/*
 * @Author: SakurakojiSaika
 * @Date: 2023-04-30 22:15:50
 * @LastEditTime: 2023-04-30 22:43:00
 * @Description: 
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
