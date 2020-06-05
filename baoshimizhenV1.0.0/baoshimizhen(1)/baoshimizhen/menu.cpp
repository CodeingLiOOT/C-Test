#include "menu.h"
#include "ui_menu.h"
#include"qfiledialog.h"
#include"startpage.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->resize(QSize(700,500));
    setStyleSheet(
                       //正常状态样式
                       "QPushButton{"
                       "background-color:rgba(238,210,238);"//背景色（也可以设置图片）
                       "border-style:outset;"                  //边框样式（inset/outset）
                       "border-width:2px;"                     //边框宽度像素
                       "border-radius:50px;"                   //边框圆角半径像素
                       "border-color:rgba(255,255,255);"    //边框颜色
                       "font:16px 华文隶书;"                       //字体，字体大小
                       "color:rgba(0,0,139);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover{"
                       "background-color:rgba(255,250,238);"
                       "border-color:rgba(255,255,255);"
                       "}");
    this->setAttribute(Qt::WA_DeleteOnClose, 0);
    //QPixmap pixmap("F:\\homework\\baoshimizhen\\background.bmp");
    QPixmap pixmap(":/new/prefix1/background.bmp");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);

    ui->checkBox_bgm->setStyleSheet("color:yellow");
    ui->checkBox_elim->setStyleSheet("color:yellow");
    ui->checkBox_select->setStyleSheet("color:yellow");
    ui->checkBox_no->setStyleSheet("color:yellow");
    ui->checkBox_count->setStyleSheet("color:yellow");
    ui->checkBox_menu->setStyleSheet("color:yellow");
    //ui->checkBox_end->setStyleSheet("color:yellow");
    ui->checkBox_back1->setStyleSheet("color:yellow");
    ui->checkBox_back2->setStyleSheet("color:yellow");
    ui->checkBox_gem1->setStyleSheet("color:yellow");
    ui->checkBox_gem2->setStyleSheet("color:yellow");

    //StartPage *startpage=new StartPage;
    //connect(startpage, SIGNAL(sendMusicInit(int,int,int,int,int,int,int)), this, SLOT(initCheckBox(int,int,int,int,int,int,int)));

    ui->horizontalSlider->setMaximum(100);	//调整音量的滑动组件
        ui->horizontalSlider->setMinimum(0);
        ui->horizontalSlider->setSingleStep(5);
        ui->horizontalSlider->setValue(60);
        connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));//用户做了滑动
        connect(ui->checkBox_bgm, SIGNAL(clicked(bool)), this, SLOT(setBackVisible()));	//用户点击了checkBox组件
        connect(ui->checkBox_back1, SIGNAL(clicked(bool)), this, SLOT(setBack2invis()));
        connect(ui->checkBox_back2, SIGNAL(clicked(bool)), this, SLOT(setBack1invis()));
        connect(ui->checkBox_gem1, SIGNAL(clicked(bool)), this, SLOT(setJew2invis()));
        connect(ui->checkBox_gem2, SIGNAL(clicked(bool)), this, SLOT(setJew1invis()));
        back=1;select=1;elim=1;no=1;end=1;menu=1;count=1;
    background=":/new/prefix1/background.bmp";
    //gem[]={":/new/prefix1/0.png",":/new/prefix1/1.png",":/new/prefix1/2.png",":/new/prefix1/3.png",":/new/prefix1/4.png",":/new/prefix1/5.png",":/new/prefix1/6.png",":/new/prefix1/7.png"};
    gem=1;

}

Menu::~Menu()
{
    delete ui;
}
void Menu::on_pushButton_return_clicked(){      //点击返回按钮之后，把我们的设置都先传到startpage
    int select,elim,no,end,menu,count;
    QString background;
    int gem;
    //void sendMusic(int select,int elim,int no,int end,int menu,int count);
    if(ui->checkBox_select->isChecked()){ select=1;}
    else{select=0;}
    if(ui->checkBox_elim->isChecked()){ elim=1;}
    else{elim=0;}
    if(ui->checkBox_no->isChecked()){ no=1;}
    else{no=0;}
    //if(ui->checkBox_end->isChecked()){ end=1;}
    //else{end=0;}
    if(ui->checkBox_menu->isChecked()){ menu=1;}
    else{menu=0;}
    if(ui->checkBox_count->isChecked()){ count=1;}
    else{count=0;}
    if(ui->checkBox_back1->isChecked()){
        background=":/new/prefix1/background.bmp";
    }
    else if(ui->checkBox_back2->isChecked()){
        background=":/new/prefix1/background2.jpg";
    }
    else{
        background=path1;
    }
    if(ui->checkBox_gem1->isChecked()){
        gem=1;}
    else if(ui->checkBox_gem2->isChecked()){
        gem=2;}
    emit sendMusic(select,elim,no,end,menu,count);  //这是传是否要音效的信号
    emit sendPic(background,gem);
    emit sendsignal();//发射信号表示要返回到主界面
    this->close();
}
void Menu::on_pushButton_bgm_clicked(){
   // path = QFileDialog::getOpenFileName(this, tr("选择一首歌曲"), "/", "*.mp3");
    path = QFileDialog::getOpenFileName(this);
        if (path != "") {
            emit sendPath(path);//发射信号，传递用户选择的音乐（后面同理）
        }
}
void Menu::on_pushButton_back_clicked(){
   // path = QFileDialog::getOpenFileName(this, tr("选择一首歌曲"), "/", "*.mp3");
    path1 = QFileDialog::getOpenFileName(this);

}
void Menu::setValue(int value) {
    emit sendValueBack(value);
}

void Menu::setBackVisible() {
    if (ui->checkBox_bgm->isChecked()) {
        emit sendBackVisible(1);
    }
    else {
        emit sendBackVisible(0);
    }
}
void Menu::setBack1invis() {
    ui->checkBox_back1->setCheckState(Qt::CheckState::Unchecked);
}
void Menu::setBack2invis() {
    ui->checkBox_back2->setCheckState(Qt::CheckState::Unchecked);
}
void Menu::setJew1invis() {
    ui->checkBox_gem1->setCheckState(Qt::CheckState::Unchecked);
}
void Menu::setJew2invis() {
    ui->checkBox_gem2->setCheckState(Qt::CheckState::Unchecked);
}
void Menu::setMusicInit(int back,int select,int elim,int no,int end,int menu,int count){
    if(back==1){ui->checkBox_bgm->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_bgm->setCheckState(Qt::CheckState::Unchecked);}
    if(select){ui->checkBox_select->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_select->setCheckState(Qt::CheckState::Unchecked);}
    if(elim){ui->checkBox_elim->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_elim->setCheckState(Qt::CheckState::Unchecked);}
    if(no){ui->checkBox_no->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_no->setCheckState(Qt::CheckState::Unchecked);}
    //if(end){ui->checkBox_end->setCheckState(Qt::CheckState::Checked);}
    //else{ui->checkBox_end->setCheckState(Qt::CheckState::Unchecked);}
    if(menu){ui->checkBox_menu->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_menu->setCheckState(Qt::CheckState::Unchecked);}
    if(count){ui->checkBox_count->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_count->setCheckState(Qt::CheckState::Unchecked);}

}
void Menu::setPicInit(QString background,int gem){
    if(background==":/new/prefix1/background.bmp"){ui->checkBox_back1->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_back1->setCheckState(Qt::CheckState::Unchecked);}
    if(background==":/new/prefix1/background2.jpg"){ui->checkBox_back2->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_back2->setCheckState(Qt::CheckState::Unchecked);}
    if(gem==1){ui->checkBox_gem1->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_gem1->setCheckState(Qt::CheckState::Unchecked);}
    if(gem==2){ui->checkBox_gem2->setCheckState(Qt::CheckState::Checked);}
    else{ui->checkBox_gem2->setCheckState(Qt::CheckState::Unchecked);}
    this->background=background;
    this->gem=gem;
}
