/********************************************************************************
** Form generated from reading UI file 'testerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTERPAGE_H
#define UI_TESTERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testerPage
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *expNum;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *rankNum;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *passLevel;
    QVBoxLayout *verticalLayout;
    QPushButton *searchButton;
    QPushButton *setProblemButton;
    QPushButton *exitButton;
    QLabel *label_2;

    void setupUi(QWidget *testerPage)
    {
        if (testerPage->objectName().isEmpty())
            testerPage->setObjectName(QString::fromUtf8("testerPage"));
        testerPage->resize(720, 480);
        layoutWidget = new QWidget(testerPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 120, 581, 321));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(20);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        username = new QLabel(layoutWidget);
        username->setObjectName(QString::fromUtf8("username"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        username->setFont(font1);

        horizontalLayout->addWidget(username);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        expNum = new QLabel(layoutWidget);
        expNum->setObjectName(QString::fromUtf8("expNum"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(16);
        expNum->setFont(font2);

        horizontalLayout_2->addWidget(expNum);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        rankNum = new QLabel(layoutWidget);
        rankNum->setObjectName(QString::fromUtf8("rankNum"));
        rankNum->setFont(font2);

        horizontalLayout_3->addWidget(rankNum);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        passLevel = new QLabel(layoutWidget);
        passLevel->setObjectName(QString::fromUtf8("passLevel"));
        passLevel->setFont(font2);

        horizontalLayout_4->addWidget(passLevel);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setFont(font);

        verticalLayout->addWidget(searchButton);

        setProblemButton = new QPushButton(layoutWidget);
        setProblemButton->setObjectName(QString::fromUtf8("setProblemButton"));
        setProblemButton->setFont(font);

        verticalLayout->addWidget(setProblemButton);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font);

        verticalLayout->addWidget(exitButton);


        horizontalLayout_5->addLayout(verticalLayout);

        label_2 = new QLabel(testerPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 30, 101, 72));
        label_2->setFont(font);

        retranslateUi(testerPage);

        QMetaObject::connectSlotsByName(testerPage);
    } // setupUi

    void retranslateUi(QWidget *testerPage)
    {
        testerPage->setWindowTitle(QCoreApplication::translate("testerPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("testerPage", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        username->setText(QCoreApplication::translate("testerPage", "1", nullptr));
        label_3->setText(QCoreApplication::translate("testerPage", "\347\273\217\351\252\214\345\200\274\357\274\232", nullptr));
        expNum->setText(QCoreApplication::translate("testerPage", "2", nullptr));
        label_4->setText(QCoreApplication::translate("testerPage", "\347\255\211\347\272\247\357\274\232", nullptr));
        rankNum->setText(QCoreApplication::translate("testerPage", "3", nullptr));
        label_5->setText(QCoreApplication::translate("testerPage", "\345\207\272\351\242\230\346\225\260\357\274\232", nullptr));
        passLevel->setText(QCoreApplication::translate("testerPage", "4", nullptr));
        searchButton->setText(QCoreApplication::translate("testerPage", "\346\237\245\350\257\242", nullptr));
        setProblemButton->setText(QCoreApplication::translate("testerPage", "\345\207\272\351\242\230", nullptr));
        exitButton->setText(QCoreApplication::translate("testerPage", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("testerPage", "\345\207\272\351\242\230\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testerPage: public Ui_testerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTERPAGE_H
