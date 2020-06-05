#include "chessboard.h"
#include <cmath>
#include <time.h>
#include <iostream>


bool ChessBoard::isLogical(int x1, int y1, int x2, int y2)	//移动是否合法
{
    return (abs(x1 - x2) == 1 && y1 == y2) || (abs(y1 - y2) == 1 && x1 == x2);
}

int ChessBoard::randKind()
{
    static int cnt = 0;
    if (cnt == 0)
    {
        srand(time(NULL));
    }
    cnt++;
    return rand() % 7 +1;	//随机生成1-6的数字
}

bool ChessBoard::canDirectlyDeleteInit()	//初始化棋盘是否有可以直接删除的
{
    bool flag = false;
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION - 2; j++)
        {
            if (kind[i][j] == kind[i][j + 1] && kind[i][j + 1] == kind[i][j + 2])	//连续三个相等则重置这三个棋子
            {
                kind[i][j] = randKind();
                kind[i][j + 1] = randKind();
                kind[i][j + 2] = randKind();
                flag = true;
            }
        }
    }

    for (int j = 0; j < DIMENSION; j++)
    {
        for (int i = 0; i < DIMENSION - 2; i++)
        {
            if (kind[i][j] == kind[i + 1][j] && kind[i + 1][j] == kind[i + 2][j])
            {
                kind[i][j] = randKind();
                kind[i + 1][j] = randKind();
                kind[i + 2][j] = randKind();
                flag = true;
            }
        }

    }

    return flag;

}

bool ChessBoard::Init()//初始化棋盘界面;
{

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            kind[i][j] = randKind();	//随机生成棋子
            hasDeleted[i][j] = false;
        }
    }

    //printKind();

    bool flag = true;
    while (flag)
    {
        flag = canDirectlyDeleteInit();	//搜索并修改，直到没有直接消的
    }

    //printKind();

    flag = canDelete();	//判断是否可以通过移动删除

    return flag;
}

bool ChessBoard::canDelete()	//判断是否可以通过移动消除
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION - 3; j++)
        {
            if (kind[i][j] == kind[i][j + 1] && kind[i][j] != kind[i][j + 2])
            {
                if (i == 0 && (kind[i][j] == kind[i][j + 3] || kind[i][j] == kind[i + 1][j + 2]))
                {
                    return true;
                }
                if (i == 7 && (kind[i][j] == kind[i][j + 3] || kind[i][j] == kind[i - 1][j + 2]))
                {
                    return true;
                }
                if (i > 0 && i < 7 && (kind[i][j] == kind[i][j + 3] || kind[i][j] == kind[i - 1][j + 2] || kind[i][j] == kind[i + 1][j + 2]))
                {
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = DIMENSION - 1; j >= 3; j--)
        {
            if (kind[i][j] == kind[i][j - 1] && kind[i][j] != kind[i][j - 2])
            {
                if (i == 0 && (kind[i][j] == kind[i][j - 3] || kind[i][j] == kind[i + 1][j - 2]))
                {
                    return true;
                }
                if (i == 7 && (kind[i][j] == kind[i][j - 3] || kind[i][j] == kind[i - 1][j - 2]))
                {
                    return true;
                }
                if (i > 0 && i < 7 && (kind[i][j] == kind[i][j - 3] || kind[i][j] == kind[i - 1][j - 2] || kind[i][j] == kind[i + 1][j - 2]))
                {
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 1; j < DIMENSION - 1; j++)
        {
            if (kind[i][j - 1] == kind[i][j + 1] && kind[i][j] != kind[i][j - 1])
            {
                if (i == 0 && kind[i][j - 1] == kind[i + 1][j])
                {
                    return true;
                }
                if (i == 7 && kind[i][j - 1] == kind[i - 1][j])
                {
                    return true;
                }
                if (i > 0 && i < 7 && (kind[i][j - 1] == kind[i + 1][j] || kind[i][j - 1] == kind[i - 1][j]))
                {
                    return true;
                }
            }
        }
    }

    for (int j = 0; j < DIMENSION; j++)
    {
        for (int i = 0; i < DIMENSION - 3; i++)
        {
            if (kind[i][j] == kind[i + 1][j] && kind[i + 2][j] != kind[i][j])
            {
                if (j == 0 && (kind[i][j] == kind[i + 3][j] || kind[i][j] == kind[i + 2][j + 1]))
                {
                    return true;
                }
                if (j == 7 && (kind[i][j] == kind[i + 3][j] || kind[i][j] == kind[i + 2][j - 1]))
                {
                    return true;
                }
                if (j > 0 && j < 7 && (kind[i][j] == kind[i + 3][j] || kind[i][j] == kind[i + 2][j - 1] || kind[i][j] == kind[i + 2][j + 1]))
                {
                    return true;
                }
            }
        }
    }

    for (int j = 0; j < DIMENSION; j++)
    {
        for (int i = DIMENSION - 1; i >= 3; i--)
        {
            if (kind[i][j] == kind[i - 1][j] && kind[i][j] != kind[i - 2][j])
            {
                if (j == 0 && (kind[i][j] == kind[i - 3][j] || kind[i][j] == kind[i - 2][j + 1]))
                {
                    return true;
                }
                if (j == 7 && (kind[i][j] == kind[i - 3][j] || kind[i][j] == kind[i - 2][j - 1]))
                {
                    return true;
                }
                if (j > 0 && j < 7 && (kind[i][j] == kind[i - 3][j] || kind[i][j] == kind[i - 2][j - 1] || kind[i][j] == kind[i - 2][j + 1]))
                {
                    return true;
                }
            }
        }
    }

    for (int j = 0; j < DIMENSION; j++)
    {
        for (int i = 1; i < DIMENSION - 1; i++)
        {
            if (kind[i - 1][j] == kind[i + 1][j] && kind[i][j] != kind[i - 1][j])
            {
                if (j == 0 && kind[i - 1][j] == kind[i][j + 1])
                {
                    return true;
                }
                if (j == 7 && kind[i - 1][j] == kind[i][j - 1])
                {
                    return true;
                }
                if (j > 0 && j < 7 && (kind[i - 1][j] == kind[i][j + 1] || kind[i - 1][j] == kind[i][j - 1]))
                {
                    return true;
                }
            }
        }
    }
}

position* ChessBoard::getTips()		//获得tips
{
    position* tips = new position[2];
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION - 3; j++)
        {
            if (kind[i][j] == kind[i][j + 1] && kind[i][j] != kind[i][j + 2])
            {
                if (i == 0)
                {
                    if (kind[i][j] == kind[i][j + 3])
                    {
                        tips[0].x = i;
                        tips[0].y = j + 2;
                        tips[1].x = i;
                        tips[1].y = j + 3;
                        return tips;
                    }
                    else if(kind[i][j] == kind[i + 1][j + 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j + 2;
                        tips[1].x = i + 1;
                        tips[1].y = j + 2;
                        return tips;
                    }
                }
                if (i == 7)
                {
                    if (kind[i][j] == kind[i][j + 3])
                    {
                        tips[0].x = i;
                        tips[0].y = j + 2;
                        tips[1].x = i;
                        tips[1].y = j + 3;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i - 1][j + 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j + 2;
                        tips[1].x = i - 1;
                        tips[1].y = j + 2;
                        return tips;
                    }
                }
                if (i > 0 && i < 7)
                {
                    if (kind[i][j] == kind[i][j + 3])
                    {
                        tips[0].x = i;
                        tips[0].y = j + 2;
                        tips[1].x = i;
                        tips[1].y = j + 3;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i + 1][j + 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j + 2;
                        tips[1].x = i + 1;
                        tips[1].y = j + 2;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i - 1][j + 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j + 2;
                        tips[1].x = i - 1;
                        tips[1].y = j + 2;
                        return tips;
                    }
                }
            }
        }
    }

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = DIMENSION - 1; j >= 3; j--)
        {
            if (kind[i][j] == kind[i][j - 1] && kind[i][j] != kind[i][j - 2])
            {
                if (i == 0)
                {
                    if (kind[i][j] == kind[i][j - 3])
                    {
                        tips[0].x = i;
                        tips[0].y = j - 2;
                        tips[1].x = i;
                        tips[1].y = j - 3;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i + 1][j - 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j - 2;
                        tips[1].x = i + 1;
                        tips[1].y = j - 2;
                        return tips;
                    }
                }
                if (i == 7)
                {
                    if (kind[i][j] == kind[i][j - 3])
                    {
                        tips[0].x = i;
                        tips[0].y = j - 2;
                        tips[1].x = i;
                        tips[1].y = j - 3;
                        return tips;
                    }
                    else if(kind[i][j] == kind[i - 1][j - 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j - 2;
                        tips[1].x = i - 1;
                        tips[1].y = j - 2;
                        return tips;
                    }
                }
                if (i > 0 && i < 7)
                {
                    if (kind[i][j] == kind[i][j - 3])
                    {
                        tips[0].x = i;
                        tips[0].y = j - 2;
                        tips[1].x = i;
                        tips[1].y = j - 3;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i + 1][j - 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j - 2;
                        tips[1].x = i + 1;
                        tips[1].y = j - 2;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i - 1][j - 2])
                    {
                        tips[0].x = i;
                        tips[0].y = j - 2;
                        tips[1].x = i - 1;
                        tips[1].y = j - 2;
                        return tips;
                    }
                }
            }
        }
    }

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 1; j < DIMENSION - 1; j++)
        {
            if (kind[i][j - 1] == kind[i][j + 1] && kind[i][j] != kind[i][j - 1])
            {
                if (i == 0 && kind[i][j - 1] == kind[i + 1][j])
                {
                    tips[0].x = i;
                    tips[0].y = j;
                    tips[1].x = i + 1;
                    tips[1].y = j;
                    return tips;
                }
                if (i == 7 && kind[i][j - 1] == kind[i - 1][j])
                {
                    tips[0].x = i;
                    tips[0].y = j;
                    tips[1].x = i - 1;
                    tips[1].y = j;
                    return tips;
                }
                if (i > 0 && i < 7)
                {
                    if (kind[i][j - 1] == kind[i + 1][j])
                    {
                        tips[0].x = i;
                        tips[0].y = j;
                        tips[1].x = i + 1;
                        tips[1].y = j;
                        return tips;
                    }
                    if (kind[i][j - 1] == kind[i - 1][j])
                    {
                        tips[0].x = i;
                        tips[0].y = j;
                        tips[1].x = i - 1;
                        tips[1].y = j;
                        return tips;
                    }
                }
            }
        }
    }

    for (int j = 0; j < DIMENSION; j++)
    {
        for (int i = 0; i < DIMENSION - 3; i++)
        {
            if (kind[i][j] == kind[i + 1][j] && kind[i + 2][j] != kind[i][j])
            {
                if (j == 0)
                {
                    if (kind[i][j] == kind[i + 3][j])
                    {
                        tips[0].x = i + 2;
                        tips[0].y = j;
                        tips[1].x = i + 3;
                        tips[1].y = j;
                        return tips;
                    }
                    else if(kind[i][j] == kind[i + 2][j + 1])
                    {
                        tips[0].x = i + 2;
                        tips[0].y = j;
                        tips[1].x = i + 2;
                        tips[1].y = j + 1;
                        return tips;
                    }
                }
                if (j == 7)
                {
                    if (kind[i][j] == kind[i + 3][j])
                    {
                        tips[0].x = i + 2;
                        tips[0].y = j;
                        tips[1].x = i + 3;
                        tips[1].y = j;
                        return tips;
                    }
                    else if(kind[i][j] == kind[i + 2][j - 1])
                    {
                        tips[0].x = i + 2;
                        tips[0].y = j;
                        tips[1].x = i + 2;
                        tips[1].y = j - 1;
                        return tips;
                    }
                }
                if (j > 0 && j < 7)
                {
                    if (kind[i][j] == kind[i + 3][j])
                    {
                        tips[0].x = i + 2;
                        tips[0].y = j;
                        tips[1].x = i + 3;
                        tips[1].y = j;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i + 2][j + 1])
                    {
                        tips[0].x = i + 2;
                        tips[0].y = j;
                        tips[1].x = i + 2;
                        tips[1].y = j + 1;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i + 2][j - 1])
                    {
                        tips[0].x = i + 2;
                        tips[0].y = j;
                        tips[1].x = i + 2;
                        tips[1].y = j - 1;
                        return tips;
                    }
                }
            }
        }
    }

    for (int j = 0; j < DIMENSION; j++)
    {
        for (int i = DIMENSION - 1; i >= 3; i--)
        {
            if (kind[i][j] == kind[i - 1][j] && kind[i][j] != kind[i - 2][j])
            {
                if (j == 0)
                {
                    if (kind[i][j] == kind[i - 3][j])
                    {
                        tips[0].x = i - 2;
                        tips[0].y = j;
                        tips[1].x = i - 3;
                        tips[1].y = j;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i - 2][j + 1])
                    {
                        tips[0].x = i - 2;
                        tips[0].y = j;
                        tips[1].x = i - 2;
                        tips[1].y = j + 1;
                        return tips;
                    }
                }
                if (j == 7)
                {
                    if (kind[i][j] == kind[i - 3][j])
                    {
                        tips[0].x = i - 2;
                        tips[0].y = j;
                        tips[1].x = i - 3;
                        tips[1].y = j;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i - 2][j - 1])
                    {
                        tips[0].x = i - 2;
                        tips[0].y = j;
                        tips[1].x = i - 2;
                        tips[1].y = j - 1;
                        return tips;
                    }
                }
                if (j > 0 && j < 7)
                {
                    if (kind[i][j] == kind[i - 3][j])
                    {
                        tips[0].x = i - 2;
                        tips[0].y = j;
                        tips[1].x = i - 3;
                        tips[1].y = j;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i - 2][j + 1])
                    {
                        tips[0].x = i - 2;
                        tips[0].y = j;
                        tips[1].x = i - 2;
                        tips[1].y = j + 1;
                        return tips;
                    }
                    else if (kind[i][j] == kind[i - 2][j - 1])
                    {
                        tips[0].x = i - 2;
                        tips[0].y = j;
                        tips[1].x = i - 2;
                        tips[1].y = j - 1;
                        return tips;
                    }
                }
            }
        }
    }

    for (int j = 0; j < DIMENSION; j++)
    {
        for (int i = 1; i < DIMENSION - 1; i++)
        {
            if (kind[i - 1][j] == kind[i + 1][j] && kind[i][j] != kind[i - 1][j])
            {
                if (j == 0 && kind[i - 1][j] == kind[i][j + 1])
                {
                    tips[0].x = i;
                    tips[0].y = j;
                    tips[1].x = i;
                    tips[1].y = j + 1;
                    return tips;
                }
                if (j == 7 && kind[i - 1][j] == kind[i][j - 1])
                {
                    tips[0].x = i;
                    tips[0].y = j;
                    tips[1].x = i;
                    tips[1].y = j - 1;
                    return tips;
                }
                if (j > 0 && j < 7)
                {
                    if (kind[i - 1][j] == kind[i][j + 1])
                    {
                        tips[0].x = i;
                        tips[0].y = j;
                        tips[1].x = i;
                        tips[1].y = j + 1;
                        return tips;
                    }
                    if (kind[i - 1][j] == kind[i][j - 1])
                    {
                        tips[0].x = i;
                        tips[0].y = j;
                        tips[1].x = i;
                        tips[1].y = j - 1;
                        return tips;
                    }
                }
            }
        }
    }
}

bool ChessBoard::canDirectlyDeleteAll()
{
    bool flag = false;
    //遍历每行是否有可以消除的
    for (int i = 0; i < DIMENSION; i++)
    {
        int cnt = 1;
        int cur = kind[i][0];
        for (int j = 1; j < DIMENSION; j++)
        {
            if (kind[i][j] == cur && j != 7)
            {
                cnt++;
            }
            else
            {
                if (j == 7 && kind[i][j] == cur)
                {
                    cnt++;
                    if (cnt > 2)
                    {
                        for (int k = cnt; k > 0; k--)
                        {
                            hasDeleted[i][j - k + 1] = true;

                            //kind[i][j - k + 1] = 0;
                        }
                        score+=cnt;
                        flag = true;
                    }
                    break;
                }
                else if (cnt > 2)
                {
                    for (int k = cnt; k > 0; k--)
                    {
                        hasDeleted[i][j - k] = true;

                        //kind[i][j - k] = 0;
                    }
                    score+=cnt;
                    flag = true;
                }
                cur = kind[i][j];
                cnt = 1;
            }
        }
    }
    //遍历每列是否有可以消除的
    for (int i = 0; i < DIMENSION; i++)
    {
        int cnt = 1;
        int cur = kind[0][i];
        for (int j = 1; j < DIMENSION; j++)
        {
            if (kind[j][i] == cur && j != 7)
            {
                cnt++;
            }
            else
            {
                if (j == 7 && kind[j][i] == cur)
                {
                    cnt++;
                    if (cnt > 2)
                    {
                        for (int k = cnt; k > 0; k--)
                        {
                            hasDeleted[j - k + 1][i] = true;



                            //kind[j - k + 1][i] = 0;
                        }
                        score+=cnt;
                        flag = true;

                    }
                    break;
                }
                else if (cnt > 2)
                {
                    for (int k = cnt; k > 0; k--)
                    {
                        hasDeleted[j - k][i] = true;

                        //kind[j - k][i] = 0;
                    }
                    score+=cnt;
                    flag = true;
                }
                cur = kind[j][i];
                cnt = 1;
            }
        }
    }
    return flag;
}

void ChessBoard::fall()
{
    int cnt[8];
    //落子
    for (int i = 0; i < DIMENSION; i++)
    {
        cnt[i] = 0;
        int cur = 7;
        for (int j = 7; j >= 0; j--)
        {
            if (hasDeleted[j][i] == false)
            {
                kind[cur][i] = kind[j][i];
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
                kind[k - 1][i] = randKind();
            }
        }


    }
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            hasDeleted[i][j] = false;
        }
    }
}

void ChessBoard::printDelete()
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            cout << hasDeleted[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ChessBoard::printKind()
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            if (kind[i][j] > 0 && kind[i][j] < 7)
            {
                cout << kind[i][j] << " ";

            }
            else
            {
                cout << "error!" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int ChessBoard::swap(int x1, int y1, int x2, int y2)
{

    if (!isLogical(x1, y1, x2, y2))
    {
        return 1;
    }
    int temp = kind[x1][y1];
    kind[x1][y1] = kind[x2][y2];
    kind[x2][y2] = temp;
    if (!canDirectlyDeleteAll())
    {
        int temp = kind[x1][y1];
        kind[x1][y1] = kind[x2][y2];
        kind[x2][y2] = temp;
        return 2;
    }

    return 3;
}

void ChessBoard::play()
{
    while (true)
    {
        if (Init())
        {
            break;
        }
    }
    cout << "current kind : " << endl;
    printKind();
    int x1, y1, x2, y2;
    while (true)
    {
        cout << "input position : " << endl;
        cin >> x1 >> y1 >> x2 >> y2;
        int flag = swap(x1, y1, x2, y2);
        if (flag == 3)
        {
            do
            {
                cout << "delete boll martix: " << endl;
                printDelete();
                fall();
                /***********
                落子动画
                ***********/
                cout << "current kind : " << endl;
                printKind();

            } while (canDirectlyDeleteAll());
            if (!canDelete())
            {
                while (true)
                {
                    if (Init())
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "current kind : " << endl;
            printKind();
        }
    }
}
