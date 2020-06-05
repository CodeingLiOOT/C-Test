/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QCheckBox *checkBox_bgm;
    QCheckBox *checkBox_select;
    QCheckBox *checkBox_elim;
    QSlider *horizontalSlider;
    QPushButton *pushButton_bgm;
    QPushButton *pushButton_return;
    QCheckBox *checkBox_no;
    QCheckBox *checkBox_count;
    QCheckBox *checkBox_menu;
    QCheckBox *checkBox_back1;
    QCheckBox *checkBox_back2;
    QPushButton *pushButton_back;
    QCheckBox *checkBox_gem1;
    QCheckBox *checkBox_gem2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(800, 600);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        checkBox_bgm = new QCheckBox(centralwidget);
        checkBox_bgm->setObjectName(QString::fromUtf8("checkBox_bgm"));
        checkBox_bgm->setGeometry(QRect(160, 80, 121, 41));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 128));
        brush1.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        checkBox_bgm->setPalette(palette);
        checkBox_select = new QCheckBox(centralwidget);
        checkBox_select->setObjectName(QString::fromUtf8("checkBox_select"));
        checkBox_select->setGeometry(QRect(160, 150, 111, 41));
        checkBox_elim = new QCheckBox(centralwidget);
        checkBox_elim->setObjectName(QString::fromUtf8("checkBox_elim"));
        checkBox_elim->setGeometry(QRect(320, 150, 111, 41));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(300, 90, 261, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_bgm = new QPushButton(centralwidget);
        pushButton_bgm->setObjectName(QString::fromUtf8("pushButton_bgm"));
        pushButton_bgm->setGeometry(QRect(600, 80, 81, 31));
        pushButton_return = new QPushButton(centralwidget);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(30, 20, 81, 31));
        checkBox_no = new QCheckBox(centralwidget);
        checkBox_no->setObjectName(QString::fromUtf8("checkBox_no"));
        checkBox_no->setGeometry(QRect(500, 150, 181, 41));
        checkBox_count = new QCheckBox(centralwidget);
        checkBox_count->setObjectName(QString::fromUtf8("checkBox_count"));
        checkBox_count->setGeometry(QRect(420, 220, 161, 41));
        checkBox_menu = new QCheckBox(centralwidget);
        checkBox_menu->setObjectName(QString::fromUtf8("checkBox_menu"));
        checkBox_menu->setGeometry(QRect(220, 220, 161, 41));
        checkBox_back1 = new QCheckBox(centralwidget);
        checkBox_back1->setObjectName(QString::fromUtf8("checkBox_back1"));
        checkBox_back1->setGeometry(QRect(160, 330, 71, 21));
        checkBox_back2 = new QCheckBox(centralwidget);
        checkBox_back2->setObjectName(QString::fromUtf8("checkBox_back2"));
        checkBox_back2->setGeometry(QRect(300, 330, 71, 21));
        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(430, 290, 75, 31));
        checkBox_gem1 = new QCheckBox(centralwidget);
        checkBox_gem1->setObjectName(QString::fromUtf8("checkBox_gem1"));
        checkBox_gem1->setGeometry(QRect(160, 440, 71, 21));
        checkBox_gem2 = new QCheckBox(centralwidget);
        checkBox_gem2->setObjectName(QString::fromUtf8("checkBox_gem2"));
        checkBox_gem2->setGeometry(QRect(290, 440, 71, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 380, 54, 51));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/1.png);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 390, 41, 41));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/a.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 270, 81, 51));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/background.bmp);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(290, 270, 81, 51));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/background2.jpg);"));
        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "MainWindow", nullptr));
        checkBox_bgm->setText(QApplication::translate("Menu", "\350\203\214\346\231\257\351\237\263\344\271\220", nullptr));
        checkBox_select->setText(QApplication::translate("Menu", "\351\200\211\346\213\251\351\237\263\346\225\210", nullptr));
        checkBox_elim->setText(QApplication::translate("Menu", "\346\266\210\351\231\244\351\237\263\346\225\210", nullptr));
        pushButton_bgm->setText(QApplication::translate("Menu", "\350\207\252\345\256\232\344\271\211", nullptr));
        pushButton_return->setText(QApplication::translate("Menu", "\350\277\224\345\233\236", nullptr));
        checkBox_no->setText(QApplication::translate("Menu", "\346\266\210\351\231\244\345\244\261\350\264\245\351\237\263\346\225\210", nullptr));
        checkBox_count->setText(QApplication::translate("Menu", "\345\200\222\350\256\241\346\227\266\351\237\263\346\225\210", nullptr));
        checkBox_menu->setText(QApplication::translate("Menu", "\345\274\271\345\207\272\350\217\234\345\215\225\351\237\263\346\225\210", nullptr));
        checkBox_back1->setText(QApplication::translate("Menu", "\350\203\214\346\231\257\344\270\200", nullptr));
        checkBox_back2->setText(QApplication::translate("Menu", "\350\203\214\346\231\257\344\272\214", nullptr));
        pushButton_back->setText(QApplication::translate("Menu", "\350\207\252\345\256\232\344\271\211", nullptr));
        checkBox_gem1->setText(QApplication::translate("Menu", "\345\256\235\347\237\263\344\270\200", nullptr));
        checkBox_gem2->setText(QApplication::translate("Menu", "\345\256\235\347\237\263\344\272\214", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
