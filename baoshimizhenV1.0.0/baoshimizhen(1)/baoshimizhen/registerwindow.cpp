#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QPalette>
#include <QPixmap>
#include <QSqlQuery>
#include<QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWindow)
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

    this->setAttribute(Qt::WA_DeleteOnClose, 1);
    QPixmap pixmap(":/new/prefix1/background.bmp");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    ui->label->setStyleSheet("color:white");
    ui->label_2->setStyleSheet("color:white");
    ui->label_3->setStyleSheet("color:white");
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
void RegisterWindow::on_pushButton_clicked(){
    QString pw;
    QString name=ui->lineEdit_name->text();
    QString pw1=ui->lineEdit_pw1->text();
    QString pw2=ui->lineEdit_pw2->text();
    QSqlDatabase db=QSqlDatabase::database("dataBase");
    QSqlQuery query(db);
    QString str = QString("select *from player where userName = '%1'").arg(name);
    query.exec(str);
    while (query.next()){
        pw = query.value(1).toString();
    }
    if(pw1.compare(pw2)!=0){
        QMessageBox::about(NULL, "注意", "两次密码不一致!");
    }
    else if(pw!=NULL){
         QMessageBox::about(NULL, "警告", "用户名已存在!");
    }
    else{
        int highest=0;
        str = QString("insert into player(userName, pw, highest) values('%1', '%2', '%3')").arg(name).arg(pw1).arg(highest);
        query.exec(str);
        QMessageBox::about(NULL, "哈哈", "注册成功!");
        sendsignal();
        this->close();
    }
}
void RegisterWindow::on_pushButton_2_clicked(){
    emit sendsignal();//发射信号表示要返回到主界面
    this->close();
}
