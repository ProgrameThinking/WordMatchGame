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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchPage
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *playerButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *testerbutton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *numButton;
    QPushButton *rankButton;
    QSpacerItem *verticalSpacer_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *selectCbx;
    QLineEdit *infoEdit;
    QPushButton *searchButton;
    QPushButton *exitButton;

    void setupUi(QWidget *searchPage)
    {
        if (searchPage->objectName().isEmpty())
            searchPage->setObjectName(QString::fromUtf8("searchPage"));
        searchPage->resize(720, 480);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(22);
        searchPage->setFont(font);
        widget = new QWidget(searchPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 601, 426));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        playerButton = new QPushButton(widget);
        playerButton->setObjectName(QString::fromUtf8("playerButton"));

        horizontalLayout->addWidget(playerButton);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        testerbutton = new QPushButton(widget);
        testerbutton->setObjectName(QString::fromUtf8("testerbutton"));

        horizontalLayout->addWidget(testerbutton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(16);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        numButton = new QPushButton(widget);
        numButton->setObjectName(QString::fromUtf8("numButton"));
        numButton->setFont(font1);

        horizontalLayout_3->addWidget(numButton);

        rankButton = new QPushButton(widget);
        rankButton->setObjectName(QString::fromUtf8("rankButton"));
        rankButton->setFont(font1);

        horizontalLayout_3->addWidget(rankButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        tableView->setFont(font2);

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        selectCbx = new QComboBox(widget);
        selectCbx->addItem(QString());
        selectCbx->addItem(QString());
        selectCbx->addItem(QString());
        selectCbx->setObjectName(QString::fromUtf8("selectCbx"));

        horizontalLayout_2->addWidget(selectCbx);

        infoEdit = new QLineEdit(widget);
        infoEdit->setObjectName(QString::fromUtf8("infoEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(22);
        infoEdit->setFont(font3);

        horizontalLayout_2->addWidget(infoEdit);

        searchButton = new QPushButton(widget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout_2->addWidget(searchButton);

        exitButton = new QPushButton(widget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout_2->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout_2);


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
