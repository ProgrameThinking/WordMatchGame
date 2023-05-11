/********************************************************************************
** Form generated from reading UI file 'battlepage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEPAGE_H
#define UI_BATTLEPAGE_H

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

class Ui_battlePage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLabel *player1;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *player2;
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

    void setupUi(QWidget *battlePage)
    {
        if (battlePage->objectName().isEmpty())
            battlePage->setObjectName(QString::fromUtf8("battlePage"));
        battlePage->resize(664, 497);
        verticalLayout = new QVBoxLayout(battlePage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(battlePage);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(22);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(battlePage);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_10 = new QHBoxLayout(widget);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(18);
        label_9->setFont(font1);

        horizontalLayout_10->addWidget(label_9);

        player1 = new QLabel(widget);
        player1->setObjectName(QString::fromUtf8("player1"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(18);
        player1->setFont(font2);

        horizontalLayout_10->addWidget(player1);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        horizontalLayout_10->addWidget(label_13);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        horizontalLayout_10->addWidget(label_11);

        player2 = new QLabel(widget);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setFont(font2);

        horizontalLayout_10->addWidget(player2);


        verticalLayout->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(battlePage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font3.setPointSize(20);
        label_7->setFont(font3);

        horizontalLayout_8->addWidget(label_7);

        timeLimitBar = new QProgressBar(battlePage);
        timeLimitBar->setObjectName(QString::fromUtf8("timeLimitBar"));
        timeLimitBar->setValue(24);

        horizontalLayout_8->addWidget(timeLimitBar);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(battlePage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);

        horizontalLayout_7->addWidget(label_2);

        wordShowLabel = new QLabel(battlePage);
        wordShowLabel->setObjectName(QString::fromUtf8("wordShowLabel"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(16);
        wordShowLabel->setFont(font4);

        horizontalLayout_7->addWidget(wordShowLabel);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(battlePage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font3);

        horizontalLayout_6->addWidget(label_6);

        answerEdit = new QLineEdit(battlePage);
        answerEdit->setObjectName(QString::fromUtf8("answerEdit"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Times New Roman"));
        font5.setPointSize(20);
        answerEdit->setFont(font5);

        horizontalLayout_6->addWidget(answerEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        submitButton = new QPushButton(battlePage);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setFont(font3);

        horizontalLayout_5->addWidget(submitButton);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        exitButton = new QPushButton(battlePage);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font3);

        horizontalLayout_5->addWidget(exitButton);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(battlePage);

        QMetaObject::connectSlotsByName(battlePage);
    } // setupUi

    void retranslateUi(QWidget *battlePage)
    {
        battlePage->setWindowTitle(QCoreApplication::translate("battlePage", "Form", nullptr));
        label->setText(QCoreApplication::translate("battlePage", "\345\257\271\346\210\230\346\250\241\345\274\217", nullptr));
        label_9->setText(QCoreApplication::translate("battlePage", "\347\216\251\345\256\266    ", nullptr));
        player1->setText(QCoreApplication::translate("battlePage", "\347\216\251\345\256\266    ", nullptr));
        label_13->setText(QCoreApplication::translate("battlePage", "VS", nullptr));
        label_11->setText(QCoreApplication::translate("battlePage", "\347\216\251\345\256\266    ", nullptr));
        player2->setText(QCoreApplication::translate("battlePage", "\347\216\251\345\256\266    ", nullptr));
        label_7->setText(QCoreApplication::translate("battlePage", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("battlePage", "\345\215\225\350\257\215\346\230\276\347\244\272\357\274\232", nullptr));
        wordShowLabel->setText(QCoreApplication::translate("battlePage", "1", nullptr));
        label_6->setText(QCoreApplication::translate("battlePage", "\347\255\224\351\242\230\345\214\272\357\274\232", nullptr));
        submitButton->setText(QCoreApplication::translate("battlePage", "\346\217\220\344\272\244", nullptr));
        exitButton->setText(QCoreApplication::translate("battlePage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class battlePage: public Ui_battlePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEPAGE_H
