/********************************************************************************
** Form generated from reading UI file 'addwordpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWORDPAGE_H
#define UI_ADDWORDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addWordPage
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *username;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *expNum;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *rankNum;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *passLevel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *answerEdit;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *submitButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;

    void setupUi(QWidget *addWordPage)
    {
        if (addWordPage->objectName().isEmpty())
            addWordPage->setObjectName(QString::fromUtf8("addWordPage"));
        addWordPage->resize(720, 480);
        widget = new QWidget(addWordPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 80, 271, 312));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(20);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        username = new QLabel(widget);
        username->setObjectName(QString::fromUtf8("username"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        username->setFont(font1);

        horizontalLayout->addWidget(username);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        expNum = new QLabel(widget);
        expNum->setObjectName(QString::fromUtf8("expNum"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(16);
        expNum->setFont(font2);

        horizontalLayout_2->addWidget(expNum);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        rankNum = new QLabel(widget);
        rankNum->setObjectName(QString::fromUtf8("rankNum"));
        rankNum->setFont(font2);

        horizontalLayout_3->addWidget(rankNum);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        passLevel = new QLabel(widget);
        passLevel->setObjectName(QString::fromUtf8("passLevel"));
        passLevel->setFont(font2);

        horizontalLayout_4->addWidget(passLevel);


        verticalLayout->addLayout(horizontalLayout_4);

        widget1 = new QWidget(addWordPage);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(351, 172, 321, 145));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        horizontalLayout_6->addWidget(label_6);

        answerEdit = new QLineEdit(widget1);
        answerEdit->setObjectName(QString::fromUtf8("answerEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(20);
        answerEdit->setFont(font3);

        horizontalLayout_6->addWidget(answerEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        submitButton = new QPushButton(widget1);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setFont(font);

        horizontalLayout_5->addWidget(submitButton);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        exitButton = new QPushButton(widget1);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font);

        horizontalLayout_5->addWidget(exitButton);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(addWordPage);

        QMetaObject::connectSlotsByName(addWordPage);
    } // setupUi

    void retranslateUi(QWidget *addWordPage)
    {
        addWordPage->setWindowTitle(QCoreApplication::translate("addWordPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("addWordPage", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        username->setText(QCoreApplication::translate("addWordPage", "1", nullptr));
        label_3->setText(QCoreApplication::translate("addWordPage", "\347\273\217\351\252\214\345\200\274\357\274\232", nullptr));
        expNum->setText(QCoreApplication::translate("addWordPage", "2", nullptr));
        label_4->setText(QCoreApplication::translate("addWordPage", "\347\255\211\347\272\247\357\274\232", nullptr));
        rankNum->setText(QCoreApplication::translate("addWordPage", "3", nullptr));
        label_5->setText(QCoreApplication::translate("addWordPage", "\345\207\272\351\242\230\346\225\260\357\274\232", nullptr));
        passLevel->setText(QCoreApplication::translate("addWordPage", "4", nullptr));
        label_6->setText(QCoreApplication::translate("addWordPage", "\345\215\225\350\257\215\346\267\273\345\212\240\357\274\232", nullptr));
        submitButton->setText(QCoreApplication::translate("addWordPage", "\346\217\220\344\272\244", nullptr));
        exitButton->setText(QCoreApplication::translate("addWordPage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addWordPage: public Ui_addWordPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWORDPAGE_H
