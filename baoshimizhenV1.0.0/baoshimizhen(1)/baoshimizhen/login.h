#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<qmediaplayer.h>
#include<qmediaplaylist.h>
#include<QSqlTableModel>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString name;
    QString password;
    QString password1;
    QMediaPlayer* myPlayer;
    QMediaPlaylist* playlist;
    QString path;
    QSqlTableModel *model;
    void music();
private:
    Ui::Login *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void reshow();
    void setBGM(QString);
    void setValue(int);
    void setBackVisible(int);
signals:
    void sendMusicInit(int,int,int,int,int,int,int);
};

#endif // LOGIN_H
