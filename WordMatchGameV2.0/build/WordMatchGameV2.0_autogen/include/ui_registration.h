/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

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

class Ui_registration
{
public:
    QComboBox *typeCbx;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *unameText;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *pwdText;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *confirmButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;

    void setupUi(QWidget *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName(QString::fromUtf8("registration"));
        registration->resize(1080, 720);
        typeCbx = new QComboBox(registration);
        typeCbx->addItem(QString());
        typeCbx->addItem(QString());
        typeCbx->setObjectName(QString::fromUtf8("typeCbx"));
        typeCbx->setGeometry(QRect(408, 389, 381, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(20);
        typeCbx->setFont(font);
        label_3 = new QLabel(registration);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 390, 131, 35));
        label_3->setFont(font);
        layoutWidget = new QWidget(registration);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 208, 521, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        unameText = new QTextEdit(layoutWidget);
        unameText->setObjectName(QString::fromUtf8("unameText"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(20);
        unameText->setFont(font1);

        horizontalLayout->addWidget(unameText);

        layoutWidget1 = new QWidget(registration);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(270, 290, 521, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        pwdText = new QTextEdit(layoutWidget1);
        pwdText->setObjectName(QString::fromUtf8("pwdText"));
        pwdText->setFont(font1);

        horizontalLayout_2->addWidget(pwdText);

        layoutWidget2 = new QWidget(registration);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(270, 480, 521, 46));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        confirmButton = new QPushButton(layoutWidget2);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setFont(font);

        horizontalLayout_3->addWidget(confirmButton);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        exitButton = new QPushButton(layoutWidget2);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font);

        horizontalLayout_3->addWidget(exitButton);


        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QWidget *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Form", nullptr));
        typeCbx->setItemText(0, QCoreApplication::translate("registration", "\345\207\272\351\242\230\350\200\205", nullptr));
        typeCbx->setItemText(1, QCoreApplication::translate("registration", "\347\216\251\345\256\266", nullptr));

        label_3->setText(QCoreApplication::translate("registration", "\347\261\273    \345\236\213\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("registration", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("registration", "\345\257\206    \347\240\201\357\274\232", nullptr));
        confirmButton->setText(QCoreApplication::translate("registration", "\347\241\256\350\256\244", nullptr));
        exitButton->setText(QCoreApplication::translate("registration", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
