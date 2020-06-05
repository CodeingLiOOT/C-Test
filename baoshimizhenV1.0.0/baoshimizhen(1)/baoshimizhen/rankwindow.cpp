#include "rankwindow.h"
#include "ui_rankwindow.h"
#include"login.h"


RankWindow::RankWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RankWindow)
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

    this->setAttribute(Qt::WA_DeleteOnClose, 0);
    QSqlDatabase db=QSqlDatabase::database("dataBase");
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("dataBase");
    if (!db.open()) {
            printf("can not connect");
        }
    QSqlQuery query(db);
    query.exec();

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model = new QSqlTableModel(this,db);
    ui->tableView->setShowGrid(true);
    model->setTable("player");
    model->select();

    model->setSort(2, Qt::DescendingOrder);  //降序排列
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(1); // 隐藏
    ui->tableView->show();
}

RankWindow::~RankWindow()
{
    delete ui;
}
void RankWindow::on_pushButton_clicked(){
    emit sendsignal();
    this->close();
}
