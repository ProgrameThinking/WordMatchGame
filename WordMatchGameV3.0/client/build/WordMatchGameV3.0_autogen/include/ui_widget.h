/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTextEdit *unameText;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextEdit *pwdText;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *registrationButton;
    QLabel *label_4;
    QComboBox *typeCbx;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1080, 720);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 130, 511, 42));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 230, 641, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(20);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        unameText = new QTextEdit(layoutWidget);
        unameText->setObjectName(QString::fromUtf8("unameText"));
        unameText->setBaseSize(QSize(5, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(20);
        unameText->setFont(font2);

        horizontalLayout->addWidget(unameText);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(200, 320, 641, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        pwdText = new QTextEdit(layoutWidget1);
        pwdText->setObjectName(QString::fromUtf8("pwdText"));
        pwdText->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pwdText->sizePolicy().hasHeightForWidth());
        pwdText->setSizePolicy(sizePolicy1);
        pwdText->setFont(font2);

        horizontalLayout_2->addWidget(pwdText);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(200, 540, 641, 46));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        loginButton = new QPushButton(layoutWidget2);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setFont(font1);

        horizontalLayout_3->addWidget(loginButton);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        registrationButton = new QPushButton(layoutWidget2);
        registrationButton->setObjectName(QString::fromUtf8("registrationButton"));
        registrationButton->setFont(font1);

        horizontalLayout_3->addWidget(registrationButton);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(202, 431, 131, 35));
        label_4->setFont(font1);
        typeCbx = new QComboBox(Widget);
        typeCbx->addItem(QString());
        typeCbx->addItem(QString());
        typeCbx->setObjectName(QString::fromUtf8("typeCbx"));
        typeCbx->setGeometry(QRect(340, 430, 511, 40));
        typeCbx->setFont(font1);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label->raise();
        label_4->raise();
        typeCbx->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Welcome", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\215\225\350\257\215\346\266\210\351\231\244\346\270\270\346\210\217", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\257\206    \347\240\201\357\274\232", nullptr));
        loginButton->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        registrationButton->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\347\261\273    \345\236\213\357\274\232", nullptr));
        typeCbx->setItemText(0, QCoreApplication::translate("Widget", "\345\207\272\351\242\230\350\200\205", nullptr));
        typeCbx->setItemText(1, QCoreApplication::translate("Widget", "\347\216\251\345\256\266", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
