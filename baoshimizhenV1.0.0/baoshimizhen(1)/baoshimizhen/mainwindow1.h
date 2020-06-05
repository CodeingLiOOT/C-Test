#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include <QLabel>
#include <QMainWindow>
#include <QTimer>
#include"chessboard.h"

namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = 0);
    ~MainWindow1();
    void InitLabel();
    bool eventFilter(QObject *obj,QEvent * event);      //事件过滤器  并拦截鼠标点击label事件
    void Dispeling();
    void setPic(QString,int);
    QString pathImg[8];
    QString background;
    int gem;
protected:
    QLabel *labelArray[64];
    ChessBoard* c;

private:
    Ui::MainWindow1 *ui;
    QTimer *timer;
    QPoint prePoint,postPoint;  //移交换时，鼠标点击和松开的坐标
    int click_flag=0;                //鼠标点击次数标志
    int scores=0;
    QLabel *preLabel, *postLabel;    //两次点击的label对象
    QImage preImage,postImage;
    int select,elim,no;

private slots: //槽函数

    void endClicked();
public slots:
    void setMusic(int,int,int);


signals:
    void sendsignal();
};

#endif // MAINWINDOW1_H
