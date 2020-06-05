/********************************************************************************
** Form generated from reading UI file 'rankwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKWINDOW_H
#define UI_RANKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RankWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RankWindow)
    {
        if (RankWindow->objectName().isEmpty())
            RankWindow->setObjectName(QString::fromUtf8("RankWindow"));
        RankWindow->resize(800, 600);
        centralwidget = new QWidget(RankWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(559, 430, 91, 41));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(110, 50, 481, 361));
        tableView->setStyleSheet(QString::fromUtf8("background-color:rgb(247, 234, 255);\n"
"font:;\n"
"font: 75 11pt \"Aharoni\";"));
        RankWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RankWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        RankWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RankWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RankWindow->setStatusBar(statusbar);

        retranslateUi(RankWindow);

        QMetaObject::connectSlotsByName(RankWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RankWindow)
    {
        RankWindow->setWindowTitle(QApplication::translate("RankWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("RankWindow", "return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankWindow: public Ui_RankWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKWINDOW_H
