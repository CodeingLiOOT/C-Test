#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "thread.h"
#include <QTimer>
#include <QProgressDialog>
#include <QThread>
#include <QPalette>
#include <QPixmap>
#include <QWaitCondition>
#include <QMessageBox>
#include"QMouseEvent"
#include"qdebug.h"
#include <QTime>
#include <QTimer>
#include <QSqlDatabase>
#include<QSqlQuery>
#include<qsound.h>
#include"startpage.h"
#include <QString>
#include <stdlib.h>

using namespace std;

QString pathImg[8];
QSqlQuery q3;
QString name3;
int Highest3;
QString background;
int gem;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 700, 530 ));

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

    //connect(ui->bt1,SIGNAL(clicked()),this,SLOT(startClicked()));
    connect(ui->bt2,SIGNAL(clicked()),this,SLOT(pauseClicked()));
    connect(ui->bt3,SIGNAL(clicked()),this,SLOT(endClicked()));
    connect(ui->bt4,SIGNAL(clicked()),this,SLOT(continueClicked()));


    ui->bt4->setGeometry(1000,1000,200,200);
    ui->pushButton->setStyleSheet("border-image:url(:/new/prefix1/fdj.jpg);");
    ui->pushButton_2->setStyleSheet("border-image:url(:/new/prefix1/sx.jpg);");
    ui->pushButton_3->setStyleSheet("border-image:url(:/new/prefix1/zd.jpg);");




    //创建计时器
    timer   = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(change()));
    timer->start(1000);  // 开始计时

    thread.start(); //游戏开始

    this->ui->textBrowser->setText(QString::number(scores));
    //初始化label数组
    labelArray[0]=this->ui->label_0;
    labelArray[1]=this->ui->label_1;
    labelArray[2]=this->ui->label_2;
    labelArray[3]=this->ui->label_3;
    labelArray[4]=this->ui->label_4;
    labelArray[5]=this->ui->label_5;
    labelArray[6]=this->ui->label_6;
    labelArray[7]=this->ui->label_7;
    labelArray[8]=this->ui->label_8;
    labelArray[9]=this->ui->label_9;
    labelArray[10]=this->ui->label_10;
    labelArray[11]=this->ui->label_11;
    labelArray[12]=this->ui->label_12;
    labelArray[13]=this->ui->label_13;
    labelArray[14]=this->ui->label_14;
    labelArray[15]=this->ui->label_15;
    labelArray[16]=this->ui->label_16;
    labelArray[17]=this->ui->label_17;
    labelArray[18]=this->ui->label_18;
    labelArray[19]=this->ui->label_19;
    labelArray[20]=this->ui->label_20;
    labelArray[21]=this->ui->label_21;
    labelArray[22]=this->ui->label_22;
    labelArray[23]=this->ui->label_23;
    labelArray[24]=this->ui->label_24;
    labelArray[25]=this->ui->label_25;
    labelArray[26]=this->ui->label_26;
    labelArray[27]=this->ui->label_27;
    labelArray[28]=this->ui->label_28;
    labelArray[29]=this->ui->label_29;
    labelArray[30]=this->ui->label_30;
    labelArray[31]=this->ui->label_31;
    labelArray[32]=this->ui->label_32;
    labelArray[33]=this->ui->label_33;
    labelArray[34]=this->ui->label_34;
    labelArray[35]=this->ui->label_35;
    labelArray[36]=this->ui->label_36;
    labelArray[37]=this->ui->label_37;
    labelArray[38]=this->ui->label_38;
    labelArray[39]=this->ui->label_39;
    labelArray[40]=this->ui->label_40;
    labelArray[41]=this->ui->label_41;
    labelArray[42]=this->ui->label_42;
    labelArray[43]=this->ui->label_43;
    labelArray[44]=this->ui->label_44;
    labelArray[45]=this->ui->label_45;
    labelArray[46]=this->ui->label_46;
    labelArray[47]=this->ui->label_47;
    labelArray[48]=this->ui->label_48;
    labelArray[49]=this->ui->label_49;
    labelArray[50]=this->ui->label_50;
    labelArray[51]=this->ui->label_51;
    labelArray[52]=this->ui->label_52;
    labelArray[53]=this->ui->label_53;
    labelArray[54]=this->ui->label_54;
    labelArray[55]=this->ui->label_55;
    labelArray[56]=this->ui->label_56;
    labelArray[57]=this->ui->label_57;
    labelArray[58]=this->ui->label_58;
    labelArray[59]=this->ui->label_59;
    labelArray[60]=this->ui->label_60;
    labelArray[61]=this->ui->label_61;
    labelArray[62]=this->ui->label_62;
    labelArray[63]=this->ui->label_63;

    //为label数组安装事件过滤器
    for(int i=0;i<64;i++)
        labelArray[i]->installEventFilter(this);
    this->installEventFilter(this);

//    oper=new Operation();  //初始化Operation对象
//    oper->Create();

    c=new ChessBoard();
    while(true)
    {
        if(c->Init())
        {
            break;
        }
    }



    for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (c->kind[i][j] >0 && c->kind[i][j] <8 )
                    {
                        qDebug() <<c->kind[i][j] << " ";

                    }
                    else
                    {
                        qDebug() << "error!" << " ";
                    }
                }
                qDebug() << endl;
            }
            qDebug() << endl;
}



void MainWindow::InitLabel()
{
    for(int i=0;i<DIMENSION;i++){
        for(int j=0;j<DIMENSION;j++){
            QImage image;
            image.load(pathImg[c->kind[i][j]]);
            QPixmap pix=QPixmap::fromImage(image);
            QPixmap fitpixmap=pix.scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            labelArray[i*DIMENSION+j]->setPixmap(fitpixmap);
            labelArray[i*DIMENSION+j]->setAlignment(Qt::AlignCenter);
        }
    }
}

bool MainWindow::eventFilter(QObject *obj,QEvent *e){      //事件过滤器  并拦截鼠标点击label事件
    if (obj->metaObject()->className() == QStringLiteral("QLabel")&&e->type()==QEvent::MouseButtonPress){
        QMouseEvent *mouseEvent = (QMouseEvent *)e;        //鼠标事件，获取点击坐标
        if(click_flag==0){          //一个宝石都没有选
            QPoint p=this->ui->widget->mapFromGlobal(mouseEvent->globalPos()); //获得label相对于窗口的坐标
            qDebug()<<p.x()<<p.y();
            prePoint={p.x()/55,p.y()/55};

            click_flag=1;
            preLabel = qobject_cast<QLabel*>(obj);  //第一次点击的图片对象
            if(select==1){
                QSound* sound = new QSound("select.wav");      //选择宝石的音效
                sound->play();
            }
            preImage = preLabel->pixmap()->toImage();      //记录第一次点击label的图片
            qobject_cast<QLabel*>(obj)->setFrameShape (QFrame::Box); //设置点击边框
            qobject_cast<QLabel*>(obj)->setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(255, 170, 0);");
        }

        else if(click_flag==1){     //已经选择了一个宝石
            click_flag=0;

            QPoint p=this->ui->widget->mapFromGlobal(mouseEvent->globalPos());
            postPoint={p.x()/55,p.y()/55};

            postLabel= qobject_cast<QLabel*>(obj);
            if(select==1){
                QSound* sound = new QSound("select.wav");                  //选择宝石的音效
                sound->play();
            }
            string str1=preLabel->objectName().toStdString();          //获取两次点击的label名称
            string str2=postLabel->objectName().toStdString();

            postImage=postLabel->pixmap()->toImage();

            preLabel->setFrameShape (QFrame::Box);                     //经过两次点击，消去边框
            preLabel->setStyleSheet("border-width: 0px;border-style: solid;border-color: rgb(255, 170, 0);");

            postLabel->setFrameShape (QFrame::Box);                     //经过两次点击，消去边框
            postLabel->setStyleSheet("border-width: 0px;border-style: solid;border-color: rgb(255, 170, 0);");

            for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (c->kind[i][j] >0 && c->kind[i][j] <8 )
                            {
                                qDebug() <<c->kind[i][j] << " ";

                            }
                            else
                            {
                                qDebug() << "error!" << " ";
                            }
                        }
                        qDebug() << endl;
                    }
                    qDebug() << endl;
            int signal=c->swap(prePoint.y(),prePoint.x(),postPoint.y(),postPoint.x());
            QEventLoop eventloop;
            if(signal!=1){
                //左右相邻或上下相邻则可以进行交换
                //交换label上的图片

                QPixmap fix2 =  (QPixmap::fromImage(preImage)).scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                qobject_cast<QLabel*>(obj)->setPixmap(fix2);
                qobject_cast<QLabel*>(obj)->setAlignment(Qt::AlignCenter);

                QPixmap fix1 = (QPixmap::fromImage(postImage)).scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                preLabel->setPixmap(fix1);
                preLabel->setAlignment(Qt::AlignCenter);

                if(2==signal)
                {

                    QTimer::singleShot(500, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    if(no==1){
                        QSound* sound = new QSound("no2.wav");          //消除失败宝石的音效
                        sound->play();
                    }

                    QPixmap fitpixmap1 = (QPixmap::fromImage(preImage)).scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                    QPixmap fitpixmap2 = (QPixmap::fromImage(postImage)).scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                    preLabel->setPixmap(fitpixmap1);
                    postLabel->setPixmap(fitpixmap2);
                    for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    if (c->kind[i][j] >0 && c->kind[i][j] <8 )
                                    {
                                        qDebug() <<c->kind[i][j] << " ";

                                    }
                                    else
                                    {
                                        qDebug() << "error!" << " ";
                                    }
                                }
                                qDebug() << endl;
                            }
                            qDebug() << endl;
                }
                else if(3==signal)
                {
                    QTimer::singleShot(500,&eventloop,SLOT(quit()));
                    eventloop.exec();
                    Dispeling();
                    scores=c->score;
                    this->ui->textBrowser->setText(QString::number(scores));
                    for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    if (c->kind[i][j] >0 && c->kind[i][j] <8 )
                                    {
                                        qDebug() <<c->kind[i][j] << " ";

                                    }
                                    else
                                    {
                                        qDebug() << "error!" << " ";
                                    }
                                }
                                qDebug() << endl;
                            }
                            qDebug() << endl;
                }
            }
            if(!c->canDelete())
            {
                while(true)
                {
                    if(c->Init())
                    {
                        break;
                    }
                }
                InitLabel();
            }
        }
    }
    return false;
}

void MainWindow::Dispeling(){


    for(int i = 0; i < DIMENSION; i++)
    {
        for (int j = 7; j >= 0; j--)
        {
            if (c->hasDeleted[j][i] == true)
            {
                QImage image;
                image.load(pathImg[0]);
                QPixmap pix=QPixmap::fromImage(image);
                QPixmap fitpixmap=pix.scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                if(elim==1){
                    QSound* sound = new QSound("xiaochu.wav");                  //消除宝石的音效
                    sound->play();
                }

                labelArray[j*DIMENSION+i]->setPixmap(fitpixmap);
                labelArray[j*DIMENSION+i]->setAlignment(Qt::AlignCenter);
            }
        }
    }
    QEventLoop eventloop;
    QTimer::singleShot(300,&eventloop,SLOT(quit()));
    eventloop.exec();

        int cnt[8];
        //落子
        for (int i = 0; i < DIMENSION; i++)
        {
            cnt[i] = 0;
            int cur = 7;
            for (int j = 7; j >= 0; j--)
            {
                if (c->hasDeleted[j][i] == false)
                {
                    c->kind[cur][i] = c->kind[j][i];
                    //交换图片
                    QImage image;
                    image.load(pathImg[c->kind[cur][i]]);
                    QPixmap pix=QPixmap::fromImage(image);
                    QPixmap fitpixmap=pix.scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                    labelArray[cur*DIMENSION+i]->setPixmap(fitpixmap);
                    labelArray[cur*DIMENSION+i]->setAlignment(Qt::AlignCenter);
                    cur--;
                }
                else
                {
                    cnt[i]++;
                    continue;
                }
            }
            //生成新子
            if (cnt[i] != 0)
            {
                for (int k = cnt[i]; k > 0; k--)
                {
                    c->kind[k - 1][i] = c->randKind();
                    QImage image;
                    image.load(pathImg[c->kind[k-1][i]]);
                    QPixmap pix=QPixmap::fromImage(image);
                    QPixmap fitpixmap=pix.scaled(55,55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                    labelArray[(k-1)*DIMENSION+i]->setPixmap(fitpixmap);
                    labelArray[(k-1)*DIMENSION+i]->setAlignment(Qt::AlignCenter);
                    this->ui->textBrowser->setText(QString::number(scores));
                }
            }


        }
        for (int i = 0; i < DIMENSION; i++)
        {
            for (int j = 0; j < DIMENSION; j++)
            {
                c->hasDeleted[i][j] = false;
            }
        }



    //方块下落完毕后，再次检测是否存在又可消去的宝石，存在则持续消去直至不存在
    if(c->canDirectlyDeleteAll()){
        QEventLoop eventloop;
        QTimer::singleShot(500, &eventloop, SLOT(quit()));
        eventloop.exec();
        Dispeling();


    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete c;
}
void MainWindow::change(){
    ui->progressBar->setValue(100-thread.data);
    bool flag=false,f=true;
    if((100-thread.data)>=60){
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color: rgb(100, 255, 100) }");
    }else if((100-thread.data)<60 && (100-thread.data)>=20){
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color: rgb(255, 250, 100) }");
    }else if((100-thread.data)<20&&(100-thread.data)>=10){
         ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color: rgb(255, 50, 50) }");
    }
    else if((100-thread.data)<10&&count==1){
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color: rgb(255, 50, 50) }");
        QSound sound("countdown10.wav");
        sound.play();
        //if(f){flag=true;f=false;}
    }
    if(flag){
        QSound sound("countdown10.wav");
        sound.play();
    }
    if((100-thread.data)==0){

        thread.exit();
        timer->stop();

        if(Highest3<scores){
            q3.prepare("update player set highest=? where userName=?");
            q3.addBindValue(scores);
            q3.addBindValue(name3);
            q3.exec();

        }

        QMessageBox::about(NULL, " ",QString::fromLocal8Bit("时间到！"));
        emit sendsignal();//发射信号表示要返回到主界面
        this->close();
    }
}
void MainWindow::GetQuery(QSqlQuery query,int highestScore,QString name){  //更改最高分

    q3 = query;
    Highest3 = highestScore;
    name3 = name;

}
void MainWindow::pauseClicked(){  //暂停游戏
    thread.terminate();

    QPixmap pix;
    //pix.load("F:\\homework\\baoshimizhen\\continue.bmp");
    pix.load(":/new/prefix1/continue.bmp");
    ui->bt4->setIcon(pix);
    ui->bt4->setIconSize(QSize(pix.width()/3,pix.height()/3));
    ui->bt4->setGeometry(100,100,pix.width()/3,pix.height()/3);
    //暂停状态其他按钮不可按
    //ui->bt1->setDisabled(true);
    ui->bt2->setDisabled(true);
    ui->bt3->setDisabled(true);
    ui->bt2->setText(QString::fromLocal8Bit("继续游戏"));
}
void MainWindow::endClicked(){ //结束游戏
    thread.terminate();
    if(Highest3<scores){
        q3.prepare("update player set highest=? where userName=?");
        q3.addBindValue(scores);
        q3.addBindValue(name3);
        q3.exec();

    }

    emit sendsignal();//发射信号表示要返回到主界面
    this->close();
}
void MainWindow::continueClicked(){ //继续游戏
    thread.start();

    ui->bt4->setGeometry(1000,1000,200,200);

    //ui->bt1->setEnabled(true);
    ui->bt2->setEnabled(true);
    ui->bt3->setEnabled(true);
    ui->bt2->setText(QString::fromLocal8Bit("暂停游戏"));
}


void MainWindow::on_pushButton_clicked()    //提示
{
    if(fdj>0)
    {
        position* temp=new position[2];
        temp=c->getTips();

        this->ui->textBrowser->setText(QString::number(scores));
        labelArray[temp[0].x*DIMENSION+temp[0].y]->setFrameShape (QFrame::Box); //设置点击边框
        labelArray[temp[0].x*DIMENSION+temp[0].y]->setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(255, 170, 0);");
        labelArray[temp[1].x*DIMENSION+temp[1].y]->setFrameShape (QFrame::Box); //设置点击边框
        labelArray[temp[1].x*DIMENSION+temp[1].y]->setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(255, 170, 0);");
        if(select==1){
            QSound* sound = new QSound("select.wav");      //选择宝石的音效
            sound->play();
        }
        fdj--;
        ui->label_fdj->setText(QString::fromLocal8Bit("剩余：")+QString::number(fdj));
    }

}
void MainWindow::setMusic(int select,int elim,int no,int end,int count){
    //同样，可以在mainwindow.h里用QString backPic存背景图，int flag表示第几套主题
    //然后就是在设置图片背景的地方根据backPic和flag进行定义
    this->select=select;
    this->elim=elim;
    this->no=no;
    this->end=end;
    this->count=count;

}
void MainWindow::setPic(QString back,int gem1){
    background=back;
    gem=gem1;
    QPixmap pixmap(background);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
if(gem==1){
    pathImg[0]=":/new/prefix1/0.png";
    pathImg[1]=":/new/prefix1/1.png";
    pathImg[2]=":/new/prefix1/2.png";
    pathImg[3]=":/new/prefix1/3.png";
    pathImg[4]=":/new/prefix1/4.png";
    pathImg[5]=":/new/prefix1/5.png";
    pathImg[6]=":/new/prefix1/6.png";
    pathImg[7]=":/new/prefix1/7.png";

}else if(gem==2){
    //QString pathImg1[7]={":/new/prefix1/1.png",":/new/prefix1/2.png",":/new/prefix1/3.png",":/new/prefix1/4.png",":/new/prefix1/5.png",":/new/prefix1/6.png",":/new/prefix1/7.png"};
    pathImg[0]=":/new/prefix1/0.png";
    pathImg[1]=":/new/prefix1/a.png";
    pathImg[2]=":/new/prefix1/b.png";
    pathImg[3]=":/new/prefix1/c.png";
    pathImg[4]=":/new/prefix1/d.png";
    pathImg[5]=":/new/prefix1/e.png";
    pathImg[6]=":/new/prefix1/f.png";
    pathImg[7]=":/new/prefix1/g.png";
}
    InitLabel();
}

void MainWindow::on_pushButton_2_clicked()  //更新
{
    if(sx>0)
    {
        while(true)
        {
            if(c->Init())
            {
                break;
            }
        }
        InitLabel();

        if(no==1){
            QSound* sound = new QSound("no2.wav");          //消除失败宝石的音效
            sound->play();
        }
        sx--;
        ui->label_sx->setText(QString::fromLocal8Bit("剩余：")+QString::number(sx));
    }

}

void MainWindow::on_pushButton_3_clicked()  //炸弹
{
    if(zd>0)
    {
        srand(time(NULL));
        int row=rand()%7+1;

        for(int i=0;i<DIMENSION;i++)
        {
            c->hasDeleted[row][i]=true;
            if(elim==1){
                QSound* sound = new QSound("xiaochu.wav");                  //消除宝石的音效
                sound->play();
            }
        }
        c->score+=8;
        scores=c->score;
        this->ui->textBrowser->setText(QString::number(scores));

        zd--;
        ui->label_zd->setText(QString::fromLocal8Bit("剩余：")+QString::number(zd));
        Dispeling();
        scores=c->score;
        this->ui->textBrowser->setText(QString::number(scores));
    }
}
