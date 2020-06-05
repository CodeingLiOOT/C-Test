#pragma once
#include<string>

using namespace std;

#define DIMENSION 8

struct position
{
    int x;
    int y;
};

class ChessBoard
{
private:

public:
    int score;
    int kind[DIMENSION][DIMENSION];
    //string labelName[8][8];
    //position result[7];
    bool hasDeleted[8][8];
    int randKind();//随机生成宝石种类

    bool Init();//初始化棋盘界面;

    bool canDirectlyDeleteInit();//通过循环判断初始化棋盘是否存在可以直接消除的，如果有则消去，更新棋盘
    //bool canDirectlyDeleteSwap(int x, int y);//通过判断某点5*5十字是否存在可以直接消除的
                                            //如果可以消除，将要消除的宝石位置存入result数组中
    bool canDirectlyDeleteAll();
    //bool canDirectlyDeleteFall();

    bool canDelete();//判断棋盘是否存在可以消除的宝石

    bool isLogical(int x1, int y1, int x2, int y2);//判断交换操作是否合理（即两个宝石是否相邻）

    void fall();//消子操作后实现宝石下落和生成新宝石

    position* getTips();	//获得提示

    void play();
    int swap(int x1, int y1, int x2, int y2);//1表示不合理，2表示无效，3表示有效

    //void changeLabelPosition(int x1, int y1, int x2, int y2);//动画结束后修改label位置

    void printKind();
    void printDelete();

};



