/********************************************************************************
** Form generated from reading UI file 'battleselectpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLESELECTPAGE_H
#define UI_BATTLESELECTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_battleSelectPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *tableWidget;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *confirmButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *battleSelectPage)
    {
        if (battleSelectPage->objectName().isEmpty())
            battleSelectPage->setObjectName(QString::fromUtf8("battleSelectPage"));
        battleSelectPage->resize(652, 524);
        verticalLayout_2 = new QVBoxLayout(battleSelectPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(battleSelectPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(22);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(battleSelectPage);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(185, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(16);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(185, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);

        tableWidget = new QTableWidget(battleSelectPage);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        widget_3 = new QWidget(battleSelectPage);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        confirmButton = new QPushButton(widget_3);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(18);
        confirmButton->setFont(font2);

        horizontalLayout_3->addWidget(confirmButton);

        horizontalSpacer_6 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        exitButton = new QPushButton(widget_3);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font2);

        horizontalLayout_3->addWidget(exitButton);

        horizontalSpacer_7 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addWidget(widget_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(battleSelectPage);

        QMetaObject::connectSlotsByName(battleSelectPage);
    } // setupUi

    void retranslateUi(QWidget *battleSelectPage)
    {
        battleSelectPage->setWindowTitle(QCoreApplication::translate("battleSelectPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("battleSelectPage", "\345\257\271\346\210\230\346\250\241\345\274\217", nullptr));
        label_2->setText(QCoreApplication::translate("battleSelectPage", "\350\257\267\346\214\221\351\200\211\344\275\240\347\232\204\345\257\271\346\211\213\357\274\232", nullptr));
        confirmButton->setText(QCoreApplication::translate("battleSelectPage", "\347\241\256\350\256\244", nullptr));
        exitButton->setText(QCoreApplication::translate("battleSelectPage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class battleSelectPage: public Ui_battleSelectPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLESELECTPAGE_H
