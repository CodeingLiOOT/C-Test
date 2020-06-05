#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

}

HelpDialog::~HelpDialog()
{
    delete ui;
}
void HelpDialog::setText(int flag){
    if(flag==0){
        QString text=QString::fromLocal8Bit("游戏规则：\n1.互换\n"
                     "玩家选中相邻（横，竖）的两个宝石位置发生互换，如果互换成功则消去宝石，否则取消位置互换\n"
                     "2.消去\n玩家选择两个宝石进行位置互换，互换后如果横排或竖排的有3个或3个以上的相同宝石"
                     "，则消去这里的相同宝石，如果互换后没有可以消去的宝石，则选中的两个宝石换回原来的位置，"
                     "消去后的空格有上面的宝石掉下来补齐。\n"
                     "3.连锁\n玩家小区保释后，上面的宝石掉下来补充空格。如果这是游戏池中有连续摆放（横，竖）"
                     "的3个或3个以上相同的宝石，则可以消去这些宝石，这就是一次连锁。空格被新的宝石填充，又可以"
                     "进行下一次连锁。\n"
                     "4.模式\n一共有两个模式，竞速模式有时间限制，休闲模式没有。\n"
                     "5.道具\n道具包含三种，其中提示道具将标出两个可消棋子；更新道具将重置整个棋盘；炸弹道具将随机消去2-8行中的某一行所有宝石。");
        ui->textBrowser->setText(text);

    }
    else{
        QString text=QString::fromLocal8Bit("游戏版本：v1.0.0\n开发人员：\n"
                     "周子涵，李俊泽，刘佳敏，赵良辰，王迪\n"
                     "\n版权所有，侵权必究。");
        ui->textBrowser->setText(text);
    }

}
