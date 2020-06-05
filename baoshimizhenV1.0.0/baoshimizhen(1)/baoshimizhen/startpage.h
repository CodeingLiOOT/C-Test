#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QMainWindow>
#include<qmediaplayer.h>
#include<qmediaplaylist.h>
#include <QSqlQuery>
#include"mainwindow.h"
#include"menu.h"

namespace Ui {
class StartPage;
}

class StartPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = 0);
    ~StartPage();

    int High;
    int menuSound;
    void GetHigh(QSqlQuery query, int highestScore, QString name);
    int back,select,elim,no,end,count;
    QString background;
    int gem;

private:
    Ui::StartPage *ui;
private slots:
    void on_pushButton_rate_clicked();
    void on_pushButton_relex_clicked();
    void on_pushButton_menu_clicked();
    void on_pushButton_rank_clicked();
    void reshow();
    void setBGM(QString);
    void setValue(int);
    void setBackVisible(int);
    void setMusic(int,int,int,int,int,int);
    void setPic(QString,int);
    void on_actionhelp_2_triggered();
    void on_actionabout_triggered();

signals:
    void sendsignal();
    void sendPath(QString);
    void sendValueBack(int);
    void sendBackVisible(int);
    void sendMusicInit(int select,int elim,int no,int end,int count);
    void sendPicInit(QString,int);

};

#endif // STARTPAGE_H
