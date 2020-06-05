/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartPage
{
public:
    QAction *actionhelp;
    QAction *actionabout;
    QAction *actionhelp_2;
    QWidget *centralwidget;
    QPushButton *pushButton_rate;
    QPushButton *pushButton_relex;
    QPushButton *pushButton_menu;
    QPushButton *pushButton_rank;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartPage)
    {
        if (StartPage->objectName().isEmpty())
            StartPage->setObjectName(QString::fromUtf8("StartPage"));
        StartPage->resize(800, 600);
        actionhelp = new QAction(StartPage);
        actionhelp->setObjectName(QString::fromUtf8("actionhelp"));
        actionabout = new QAction(StartPage);
        actionabout->setObjectName(QString::fromUtf8("actionabout"));
        actionhelp_2 = new QAction(StartPage);
        actionhelp_2->setObjectName(QString::fromUtf8("actionhelp_2"));
        centralwidget = new QWidget(StartPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_rate = new QPushButton(centralwidget);
        pushButton_rate->setObjectName(QString::fromUtf8("pushButton_rate"));
        pushButton_rate->setGeometry(QRect(130, 30, 221, 221));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(11);
        pushButton_rate->setFont(font);
        pushButton_rate->setStyleSheet(QString::fromUtf8(""));
        pushButton_rate->setFlat(false);
        pushButton_relex = new QPushButton(centralwidget);
        pushButton_relex->setObjectName(QString::fromUtf8("pushButton_relex"));
        pushButton_relex->setGeometry(QRect(440, 220, 221, 221));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(10);
        pushButton_relex->setFont(font1);
        pushButton_relex->setStyleSheet(QString::fromUtf8(""));
        pushButton_menu = new QPushButton(centralwidget);
        pushButton_menu->setObjectName(QString::fromUtf8("pushButton_menu"));
        pushButton_menu->setGeometry(QRect(40, 400, 121, 51));
        pushButton_rank = new QPushButton(centralwidget);
        pushButton_rank->setObjectName(QString::fromUtf8("pushButton_rank"));
        pushButton_rank->setGeometry(QRect(40, 310, 121, 51));
        StartPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        StartPage->setMenuBar(menubar);
        statusbar = new QStatusBar(StartPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartPage->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionabout);
        menu->addAction(actionhelp_2);

        retranslateUi(StartPage);

        QMetaObject::connectSlotsByName(StartPage);
    } // setupUi

    void retranslateUi(QMainWindow *StartPage)
    {
        StartPage->setWindowTitle(QApplication::translate("StartPage", "MainWindow", nullptr));
        actionhelp->setText(QApplication::translate("StartPage", "help", nullptr));
        actionabout->setText(QApplication::translate("StartPage", "\345\205\263\344\272\216", nullptr));
        actionhelp_2->setText(QApplication::translate("StartPage", "\345\270\256\345\212\251", nullptr));
        pushButton_rate->setText(QApplication::translate("StartPage", "\347\253\236\351\200\237\346\250\241\345\274\217", nullptr));
        pushButton_relex->setText(QApplication::translate("StartPage", "\344\274\221\351\227\262\346\250\241\345\274\217", nullptr));
        pushButton_menu->setText(QApplication::translate("StartPage", "menu", nullptr));
        pushButton_rank->setText(QApplication::translate("StartPage", "\346\216\222\350\241\214\346\246\234", nullptr));
        menu->setTitle(QApplication::translate("StartPage", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartPage: public Ui_StartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
