#include "login.h"
#include "ui_login.h"
#include"startpage.h"
#include"registerwindow.h"
#include"menu.h"
#include<QFile>
#include <QPalette>
#include <QPixmap>
#include <QSqlQuery>
#include<QMessageBox>

QString name1;
int highestScore;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->resize( QSize( 700, 500 ));
    setStyleSheet(
                       //正常状态样式
                       "QPushButton{"
                       "background-color:rgba(238,210,238);"//背景色（也可以设置图片）
                       "border-style:outset;"                  //边框样式（inset/outset）
                       "border-width:1px;"                     //边框宽度像素
                       "border-radius:10px;"                   //边框圆角半径像素
                       "border-color:rgba(255,255,255);"    //边框颜色
                       "font:16px 华文隶书;"                       //字体，字体大小
                       "color:rgba(0,0,139);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover{"
                       "background-color:rgba(255,250,238);"
                       "border-color:rgba(255,250,250);"
                       "color:rgba(139,71,38);"
                       "}");

    QPixmap pixmap(":/new/prefix1/background.bmp");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    ui->label->setStyleSheet("color:white");
    ui->label_2->setStyleSheet("color:white");

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","dataBase");
    db.setDatabaseName(".//qtDb.db");  // 设置数据库的名字
    if(!db.open()) { //判断数据库是否打开
        //printf("无法建立数据库连接");
    }
    QSqlQuery query(db);
    query.exec("create table player(userName varchar(20) primary key,pw varchar(20), highest int)");
    model = new QSqlTableModel(this);
    model->setTable("player");
    model->select();
    music();
}

Login::~Login()
{
    delete ui;
}
void Login::music(){
    myPlayer = new QMediaPlayer;
    QUrl q("back.mp3");
    playlist = new QMediaPlaylist;
    playlist->addMedia(q);
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//循环播放
    myPlayer->setPlaylist(playlist);
    myPlayer->setVolume(60);
    myPlayer->play();
}
void Login::on_pushButton_clicked(){  //登陆
    name=ui->lineEdit_2->text();
    password=ui->lineEdit->text();
    QSqlDatabase db=QSqlDatabase::database("dataBase");
    QSqlQuery query(db);
    QString str = QString("select *from player where userName = '%1'").arg(name);
    query.exec(str);
    while (query.next()){
        name1 = query.value(0).toString();
        password1 = query.value(1).toString();
        highestScore =  query.value(2).toInt();
    }
    if(password1 == NULL) {  //该账号不存在
        QMessageBox::about(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(" 该用户不存在 !"));
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
    else{  //账户存在
        if(password1.compare(password) == 0){ // 密码对了
            this->hide();//主界面关闭
            StartPage *start=new StartPage;
            connect(start,SIGNAL(sendsignal()),this,SLOT(reshow()));
            connect(start, SIGNAL(sendPath(QString)), this, SLOT(setBGM(QString)));	//菜单返回的用户自定义背景音乐路径
            connect(start, SIGNAL(sendValueBack(int)), this, SLOT(setValue(int)));	//菜单界面返回的背景音乐音量
            connect(start, SIGNAL(sendBackVisible(int)), this, SLOT(setBackVisible(int)));
            start->show();//开始界面
            emit sendMusicInit(1,1,1,1,1,1,1);
            start->GetHigh(query,highestScore,name1);
        }
        else{   //密码输入错误
            QMessageBox::about(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(" 密码错误 !"));
            ui->lineEdit->setText("");
        }
    }

}
void Login::on_pushButton_2_clicked(){
    this->hide();//主界面关闭
    RegisterWindow *regis=new RegisterWindow;
    connect(regis,SIGNAL(sendsignal()),this,SLOT(reshow()));
    regis->show();//注册界面
}
void Login::reshow(){
    this->show();
}
void Login::setBGM(QString p){
    playlist->addMedia(QUrl(p));
        playlist->setCurrentIndex(1);
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        myPlayer->play();
}
void Login::setValue(int value){

        myPlayer->setVolume(value);

}
void Login::setBackVisible(int f){
    if (f == 0) {
            myPlayer->pause();
        }
        else {
            myPlayer->play();
        }
}
