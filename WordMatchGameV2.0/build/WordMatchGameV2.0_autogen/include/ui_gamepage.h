/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamePage
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QProgressBar *timeLimitBar;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *wordShowLabel;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *answerEdit;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *submitButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLabel *ranklevel;
    QSpacerItem *verticalSpacer_7;
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

    void setupUi(QWidget *gamePage)
    {
        if (gamePage->objectName().isEmpty())
            gamePage->setObjectName(QString::fromUtf8("gamePage"));
        gamePage->resize(720, 480);
        layoutWidget = new QWidget(gamePage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 80, 361, 327));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(20);
        label_7->setFont(font);

        horizontalLayout_8->addWidget(label_7);

        timeLimitBar = new QProgressBar(layoutWidget);
        timeLimitBar->setObjectName(QString::fromUtf8("timeLimitBar"));
        timeLimitBar->setValue(24);

        horizontalLayout_8->addWidget(timeLimitBar);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_7->addWidget(label_2);

        wordShowLabel = new QLabel(layoutWidget);
        wordShowLabel->setObjectName(QString::fromUtf8("wordShowLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        wordShowLabel->setFont(font1);

        horizontalLayout_7->addWidget(wordShowLabel);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        answerEdit = new QLineEdit(layoutWidget);
        answerEdit->setObjectName(QString::fromUtf8("answerEdit"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(20);
        answerEdit->setFont(font2);

        horizontalLayout_6->addWidget(answerEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        submitButton = new QPushButton(layoutWidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setFont(font);

        horizontalLayout_5->addWidget(submitButton);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font);

        horizontalLayout_5->addWidget(exitButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        layoutWidget1 = new QWidget(gamePage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 30, 224, 405));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_9->addWidget(label_8);

        ranklevel = new QLabel(layoutWidget1);
        ranklevel->setObjectName(QString::fromUtf8("ranklevel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font3.setPointSize(16);
        ranklevel->setFont(font3);

        horizontalLayout_9->addWidget(ranklevel);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        username = new QLabel(layoutWidget1);
        username->setObjectName(QString::fromUtf8("username"));
        username->setFont(font1);

        horizontalLayout->addWidget(username);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        expNum = new QLabel(layoutWidget1);
        expNum->setObjectName(QString::fromUtf8("expNum"));
        expNum->setFont(font3);

        horizontalLayout_2->addWidget(expNum);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        rankNum = new QLabel(layoutWidget1);
        rankNum->setObjectName(QString::fromUtf8("rankNum"));
        rankNum->setFont(font3);

        horizontalLayout_3->addWidget(rankNum);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        passLevel = new QLabel(layoutWidget1);
        passLevel->setObjectName(QString::fromUtf8("passLevel"));
        passLevel->setFont(font3);

        horizontalLayout_4->addWidget(passLevel);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(gamePage);

        QMetaObject::connectSlotsByName(gamePage);
    } // setupUi

    void retranslateUi(QWidget *gamePage)
    {
        gamePage->setWindowTitle(QCoreApplication::translate("gamePage", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("gamePage", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("gamePage", "\345\215\225\350\257\215\346\230\276\347\244\272\357\274\232", nullptr));
        wordShowLabel->setText(QCoreApplication::translate("gamePage", "1", nullptr));
        label_6->setText(QCoreApplication::translate("gamePage", "\347\255\224\351\242\230\345\214\272\357\274\232", nullptr));
        submitButton->setText(QCoreApplication::translate("gamePage", "\346\217\220\344\272\244", nullptr));
        exitButton->setText(QCoreApplication::translate("gamePage", "\351\200\200\345\207\272", nullptr));
        label_8->setText(QCoreApplication::translate("gamePage", "\345\205\263\345\215\241\351\232\276\345\272\246\357\274\232", nullptr));
        ranklevel->setText(QCoreApplication::translate("gamePage", "3", nullptr));
        label->setText(QCoreApplication::translate("gamePage", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        username->setText(QCoreApplication::translate("gamePage", "1", nullptr));
        label_3->setText(QCoreApplication::translate("gamePage", "\347\273\217\351\252\214\345\200\274\357\274\232", nullptr));
        expNum->setText(QCoreApplication::translate("gamePage", "2", nullptr));
        label_4->setText(QCoreApplication::translate("gamePage", "\347\255\211\347\272\247\357\274\232", nullptr));
        rankNum->setText(QCoreApplication::translate("gamePage", "3", nullptr));
        label_5->setText(QCoreApplication::translate("gamePage", "\345\267\262\351\227\257\345\205\263\345\215\241\346\225\260\357\274\232", nullptr));
        passLevel->setText(QCoreApplication::translate("gamePage", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamePage: public Ui_gamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
