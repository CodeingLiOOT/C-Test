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
                       //����״̬��ʽ
                       "QPushButton{"
                       "background-color:rgba(238,210,238);"//����ɫ��Ҳ��������ͼƬ��
                       "border-style:outset;"                  //�߿���ʽ��inset/outset��
                       "border-width:1px;"                     //�߿�������
                       "border-radius:10px;"                   //�߿�Բ�ǰ뾶����
                       "border-color:rgba(255,255,255);"    //�߿���ɫ
                       "font:16px ��������;"                       //���壬�����С
                       "color:rgba(0,0,139);"                //������ɫ
                       "padding:6px;"                          //���
                       "}"

                       //�����ͣ��ʽ
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
    db.setDatabaseName(".//qtDb.db");  // �������ݿ������
    if(!db.open()) { //�ж����ݿ��Ƿ��
        //printf("�޷��������ݿ�����");
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
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//ѭ������
    myPlayer->setPlaylist(playlist);
    myPlayer->setVolume(60);
    myPlayer->play();
}
void Login::on_pushButton_clicked(){  //��½
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
    if(password1 == NULL) {  //���˺Ų�����
        QMessageBox::about(NULL, QString::fromLocal8Bit("����"), QString::fromLocal8Bit(" ���û������� !"));
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
    else{  //�˻�����
        if(password1.compare(password) == 0){ // �������
            this->hide();//������ر�
            StartPage *start=new StartPage;
            connect(start,SIGNAL(sendsignal()),this,SLOT(reshow()));
            connect(start, SIGNAL(sendPath(QString)), this, SLOT(setBGM(QString)));	//�˵����ص��û��Զ��屳������·��
            connect(start, SIGNAL(sendValueBack(int)), this, SLOT(setValue(int)));	//�˵����淵�صı�����������
            connect(start, SIGNAL(sendBackVisible(int)), this, SLOT(setBackVisible(int)));
            start->show();//��ʼ����
            emit sendMusicInit(1,1,1,1,1,1,1);
            start->GetHigh(query,highestScore,name1);
        }
        else{   //�����������
            QMessageBox::about(NULL, QString::fromLocal8Bit("����"), QString::fromLocal8Bit(" ������� !"));
            ui->lineEdit->setText("");
        }
    }

}
void Login::on_pushButton_2_clicked(){
    this->hide();//������ر�
    RegisterWindow *regis=new RegisterWindow;
    connect(regis,SIGNAL(sendsignal()),this,SLOT(reshow()));
    regis->show();//ע�����
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
