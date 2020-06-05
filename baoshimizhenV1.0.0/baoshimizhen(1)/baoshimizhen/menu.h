#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    QString path;
    QString path1;
    int back,select,elim,no,end,menu,count;
    QString background;
    int gem;
private:
    Ui::Menu *ui;
public slots:
    void setMusicInit(int,int,int,int,int,int,int);
    void setPicInit(QString,int);

private slots:
    void on_pushButton_return_clicked();
    void on_pushButton_bgm_clicked();
    void on_pushButton_back_clicked();
    void setValue(int);
    void setBackVisible();
    void setBack1invis();
    void setBack2invis();
    void setJew1invis();
    void setJew2invis();
signals:
    void sendsignal();
    void sendPath(QString);
    void sendValueBack(int);
    void sendBackVisible(int);
    void sendMusic(int select,int elim,int no,int end,int menu,int count);
    void sendPic(QString,int);
};

#endif // MENU_H
