#include "startpage.h"
#include "ui_startpage.h"
#include"rankwindow.h"
#include "mainwindow1.h"
#include"menu.h"
#include"login.h"
#include<qsound.h>
#include <QPalette>
#include <QPixmap>
#include<qmessagebox.h>
#include"helpdialog.h"

QSqlQuery q2;
QString name2;
int Highest2;

StartPage::StartPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
    this->resize( QSize( 700, 500 ));
    back=1;
    select=1;
    elim=1;
    no=1;
    end=1;
    count=1;
    background=":/new/prefix1/background.bmp";
    gem=1;
    setStyleSheet(
                       //正常状态样式
                       "QPushButton{"
                       "background-color:rgba(238,210,238);"//背景色（也可以设置图片）
                       "border-style:outset;"                  //边框样式（inset/outset）
                       "border-width:2px;"                     //边框宽度像素
                       "border-radius:50px;"                   //边框圆角半径像素
                       "border-color:rgba(255,255,255);"    //边框颜色
                       "font:30px 华文琥珀;"                       //字体，字体大小
                       "color:rgba(255,255,224);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover{"
                       "background-color:rgba(255,250,238);"
                       "border-color:rgba(255,255,255);"
                       "}");

    ui->pushButton_rate->setStyleSheet( "border-image:url(:/new/prefix1/clock.png);");
    ui->pushButton_relex->setStyleSheet("border-image:url(:/new/prefix1/relax.png);"
                                        "color:rgba(139,54,38)");
    ui->pushButton_menu->setStyleSheet("color:rgba(139,28,98)");
    ui->pushButton_rank->setStyleSheet("color:rgba(139,28,98)");



    QPixmap pixmap(background);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
}
StartPage::~StartPage()
{
    delete ui;
}
void StartPage::on_pushButton_rate_clicked(){//竞速
    this->hide();//主界面关闭
    MainWindow* rate=new MainWindow;
    connect(rate,SIGNAL(sendsignal()),this,SLOT(reshow()));
    rate->setMusic(select,elim,no,end,count);
    rate->setPic(background,gem);
    rate->show();//竞速界面显示
    rate->GetQuery(q2,Highest2,name2);

}
void StartPage::on_pushButton_relex_clicked(){//休闲
    this->hide();
    MainWindow1* relax=new MainWindow1;
    connect(relax,SIGNAL(sendsignal()),this,SLOT(reshow()));
    relax->setMusic(select,elim,no);
    relax->setPic(background,gem);
    relax->show();//休闲界面显示

}
void StartPage::on_pushButton_menu_clicked(){
    if(menuSound){
        QSound* sound = new QSound("menuPop.wav");//弹出菜单的音效
            sound->play();
    }
        this->hide();//主界面关闭
        Menu* menu = new Menu;
        connect(menu,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数    videodlg->show();//子界面出现
        connect(menu, SIGNAL(sendPath(QString)), this, SLOT(setBGM(QString)));	//菜单返回的用户自定义背景音乐路径
        connect(menu, SIGNAL(sendValueBack(int)), this, SLOT(setValue(int)));	//菜单界面返回的背景音乐音量
        connect(menu, SIGNAL(sendBackVisible(int)), this, SLOT(setBackVisible(int)));	//菜单界面返回的是否需要背景音乐
        //87行的connect从menu收到用户的选择，setmusic函数是startpage的slot函数，定义在本文件115行
        connect(menu, SIGNAL(sendMusic(int,int,int,int,int,int)), this, SLOT(setMusic(int,int,int,int,int,int)));	//菜单界面返回的是否需要背景音乐
        connect(menu, SIGNAL(sendPic(QString,int)), this, SLOT(setPic(QString,int)));
        menu->setMusicInit(back,select,elim,no,end,menuSound,count);
        menu->setPicInit(background,gem);
        menu->show();//菜单界面显示
}
void StartPage::on_pushButton_rank_clicked(){
    this->hide();
    RankWindow *rank=new RankWindow;
    connect(rank,SIGNAL(sendsignal()),this,SLOT(reshow()));
    rank->show();
}
void StartPage::reshow(){
    this->show();
}
void StartPage::setBGM(QString p){
   sendPath(p);
}
void StartPage::setValue(int value){
   sendValueBack(value);
}

void StartPage::setPic(QString back,int gem){
    this->background=back;
    this->gem=gem;
    QPixmap pixmap(background);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
}
void StartPage::setBackVisible(int f){
   back=f;
   sendBackVisible(f);
}
void StartPage::GetHigh(QSqlQuery query,int highestScore,QString name){
    q2 = query;
    Highest2 = highestScore;
    name2 = name;
}
void StartPage::setMusic(int select,int elim,int no,int end,int menu,int count){

    menuSound=menu;
    this->select=select;
    this->elim=elim;
    this->no=no;
    this->end=end;
    this->count=count;
}

void StartPage::on_actionhelp_2_triggered(){
   HelpDialog *helpd=new HelpDialog;
   helpd->setText(0);
   helpd->show();
}

void StartPage::on_actionabout_triggered(){
    HelpDialog *helpd=new HelpDialog;
    helpd->setText(1);
    helpd->show();
}
