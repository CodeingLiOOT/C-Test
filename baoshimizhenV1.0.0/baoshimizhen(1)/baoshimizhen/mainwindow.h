#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include<QSqlQuery>
#include <QTimer>
#include "thread.h"
#include"chessboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void InitLabel();
    bool eventFilter(QObject *obj,QEvent * event);      //事件过滤器  并拦截鼠标点击label事件
    void Dispeling();
    void GetQuery(QSqlQuery query,int highestScore,QString name);
    void setPic(QString,int);

protected:
    QLabel *labelArray[64];
    ChessBoard* c;
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    myThread thread;
    QPoint prePoint,postPoint;  //移交换时，鼠标点击和松开的坐标
    int click_flag=0;                //鼠标点击次数标志
    int scores=0;
    QLabel *preLabel, *postLabel;    //两次点击的label对象
    QImage preImage,postImage;
    int select,elim,no,end,count;

    int fdj=2,sx=1,zd=1;


private slots: //槽函数
    void change();
    void pauseClicked();
    void endClicked();
    void continueClicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public slots:
    void setMusic(int,int,int,int,int);

signals:
    void sendsignal();
};

#endif // MAINWINDOW_H
