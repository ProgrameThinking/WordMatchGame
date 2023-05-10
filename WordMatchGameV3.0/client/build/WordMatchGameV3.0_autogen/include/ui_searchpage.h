/********************************************************************************
** Form generated from reading UI file 'searchpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHPAGE_H
#define UI_SEARCHPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchPage
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *playerButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *testerbutton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *numButton;
    QPushButton *rankButton;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *selectCbx;
    QLineEdit *infoEdit;
    QPushButton *searchButton;
    QPushButton *exitButton;

    void setupUi(QWidget *searchPage)
    {
        if (searchPage->objectName().isEmpty())
            searchPage->setObjectName(QString::fromUtf8("searchPage"));
        searchPage->resize(675, 478);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(22);
        searchPage->setFont(font);
        layoutWidget = new QWidget(searchPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 32, 581, 406));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        playerButton = new QPushButton(layoutWidget);
        playerButton->setObjectName(QString::fromUtf8("playerButton"));

        horizontalLayout_2->addWidget(playerButton);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        testerbutton = new QPushButton(layoutWidget);
        testerbutton->setObjectName(QString::fromUtf8("testerbutton"));

        horizontalLayout_2->addWidget(testerbutton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(16);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        numButton = new QPushButton(layoutWidget);
        numButton->setObjectName(QString::fromUtf8("numButton"));
        numButton->setFont(font1);

        horizontalLayout->addWidget(numButton);

        rankButton = new QPushButton(layoutWidget);
        rankButton->setObjectName(QString::fromUtf8("rankButton"));
        rankButton->setFont(font1);

        horizontalLayout->addWidget(rankButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        tableWidget = new QTableWidget(layoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        tableWidget->setFont(font2);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        selectCbx = new QComboBox(layoutWidget);
        selectCbx->addItem(QString());
        selectCbx->addItem(QString());
        selectCbx->addItem(QString());
        selectCbx->setObjectName(QString::fromUtf8("selectCbx"));

        horizontalLayout_3->addWidget(selectCbx);

        infoEdit = new QLineEdit(layoutWidget);
        infoEdit->setObjectName(QString::fromUtf8("infoEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(22);
        infoEdit->setFont(font3);

        horizontalLayout_3->addWidget(infoEdit);

        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout_3->addWidget(searchButton);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout_3->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(searchPage);

        QMetaObject::connectSlotsByName(searchPage);
    } // setupUi

    void retranslateUi(QWidget *searchPage)
    {
        searchPage->setWindowTitle(QCoreApplication::translate("searchPage", "Form", nullptr));
        playerButton->setText(QCoreApplication::translate("searchPage", "\347\216\251    \345\256\266", nullptr));
        testerbutton->setText(QCoreApplication::translate("searchPage", "\345\207\272\351\242\230\350\200\205", nullptr));
        label->setText(QCoreApplication::translate("searchPage", "\346\216\222\345\272\217\350\247\204\345\210\231\357\274\232", nullptr));
        numButton->setText(QCoreApplication::translate("searchPage", "\351\200\232\345\205\263/\345\207\272\351\242\230\346\225\260", nullptr));
        rankButton->setText(QCoreApplication::translate("searchPage", "\347\255\211\347\272\247", nullptr));
        selectCbx->setItemText(0, QCoreApplication::translate("searchPage", "\347\224\250\346\210\267\345\220\215", nullptr));
        selectCbx->setItemText(1, QCoreApplication::translate("searchPage", "\347\255\211\347\272\247", nullptr));
        selectCbx->setItemText(2, QCoreApplication::translate("searchPage", "\351\200\232\345\205\263/\345\207\272\351\242\230\346\225\260", nullptr));

        searchButton->setText(QCoreApplication::translate("searchPage", "\346\237\245\350\257\242", nullptr));
        exitButton->setText(QCoreApplication::translate("searchPage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchPage: public Ui_searchPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHPAGE_H
