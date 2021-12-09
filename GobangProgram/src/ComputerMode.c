#include "ComputerMode.h"

void ComputerMode(int **state, int row, int column)
{
    // 统计玩家或者电脑连成的子
    int personNum = 0; // 玩家连成子的个数
    int botNum = 0; // AI连成子的个数
    int emptyNum = 0; // 各方向空白位的个数
    int goodadress[row][column];
    int r,col;
    int i,j;
    int maxscore=0;
    int x=0,y=0;
    int mp=0;
    int a[10];
    int b[10];
// 清空评分数组
    for( i=0; i<row; i++)
    {
        for( j=0; j<column; j++)
        {
            goodadress[i][j]=0;
        }
    }
    // 计分（此处是完全遍历，其实可以用bfs或者dfs加减枝降低复杂度，通过调整权重值，调整AI智能程度以及攻守风格）
    for ( r=0; r< row; r++)

    {

        for ( col = 0; col < column; col++)
        {
            // 空白点就算
            if (r >= 0 && col >= 0 &&
                    state[r][col] == 0)
            {
                // 遍历周围八个方向
                for ( y = -1; y <= 1; y++)



                    for ( x = -1; x <= 1; x++)
                    {
                        // 重置
                        personNum = 0;
                        botNum = 0;
                        emptyNum = 0;

                        // 原坐标不算
                        if (!(y == 0 && x == 0))
                        {
                            // 每个方向延伸4个子

                            // 对玩家白子评分（正反两个方向）
                            for ( i = 1; i <= 4; i++)
                            {
                                if (r + i * y > 0 && r + i * y < row &&
                                        col + i * x > 0 && col + i * x < column &&
                                        state[r + i * y][col + i * x] == 1) // 玩家的子
                                {
                                    personNum++;
                                }
                                else if (r + i * y > 0 && r + i * y < row &&
                                         col + i * x > 0 && col + i * x < column &&
                                         state[r + i * y][col + i * x] == 0) // 空白位
                                {
                                    emptyNum++;
                                    break;
                                }
                                else
                                    // 出边界

                                    break;
                            }

                            for ( i = 1; i <= 4; i++)
                            {
                                if (r - i * y > 0 && r - i * y < row &&
                                        col - i * x > 0 && col - i * x < column &&
                                        state[r - i * y][col - i * x] == 1) // 玩家的子
                                {
                                    personNum++;
                                }
                                else if (r - i * y > 0 && r - i * y < row &&
                                         col - i * x > 0 && col - i * x < column &&
                                         state[r - i * y][col - i * x] == 0) // 空白位
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // 出边界
                                    break;
                            }


                            if (personNum == 1)                      // 杀二
                                goodadress[r][col] += 10;
                            else if (personNum == 2)                 // 杀三
                            {
                                if (emptyNum == 1)
                                    goodadress[r][col] += 30;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 40;
                            }
                            else if (personNum == 3)                 // 杀四
                            {
                                // 量变空位不一样，优先级不一样
                                if (emptyNum == 1)
                                    goodadress[r][col] += 60;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 110;
                            }
                            else if (personNum == 4)                 // 杀五
                                goodadress[r][col] += 10100;

                            // 进行一次清空
                            emptyNum = 0;

                            // 对AI黑子评分
                            for ( i = 1; i <= 4; i++)
                            {
                                if (r + i * y > 0 && r + i * y < row &&
                                        col + i * x > 0 && col + i * x < column &&
                                        state[r + i * y][col + i * x] == 1) // 玩家的子
                                {
                                    botNum++;
                                }
                                else if (r + i * y > 0 && r + i * y < row &&
                                         col + i * x > 0 && col + i * x < column &&
                                         state[r +i * y][col + i * x] == 0) // 空白位
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // 出边界
                                    break;
                            }

                            for ( i = 1; i <= 4; i++)
                            {
                                if (r - i * y > 0 && r - i * y < row &&
                                        col - i * x > 0 && col - i * x < column &&
                                        state[r - i * y][col - i * x] == -1) // AI的子
                                {
                                    botNum++;
                                }
                                else if (r - i * y > 0 && r - i * y < row &&
                                         col - i * x > 0 && col - i * x < column &&
                                         state[r - i * y][col - i * x] == 0) // 空白位
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // 出边界
                                    break;
                            }

                            if (botNum == 0)                      // 普通下子
                                goodadress[r][col] += 5;
                            else if (botNum == 1)                 // 活二
                                goodadress[r][col] += 10;
                            else if (botNum == 2)
                            {
                                if (emptyNum == 1)                // 死三
                                    goodadress[r][col] += 25;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 50;  // 活三
                            }
                            else if (botNum == 3)
                            {
                                if (emptyNum == 1)                // 死四
                                    goodadress[r][col] += 55;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 100; // 活四
                            }
                            else if (botNum >= 4)
                                goodadress[r][col] += 10000;   // 活五

                        }
                    }

            }
        }
    }


// 从评分中找出最大分数的位置

    for ( r=0; r<row; r++)
    {

        for ( col=0; col<column; col++)
        {
            // 前提是这个坐标是空的
            if (state[r][col] == 0)
            {
                if (goodadress[r][col]>=maxscore)          // 找最大的数和坐标
                {

                    maxscore = goodadress[r][col];

                    x=r;
                    y=col;
                    // mp=mp+1;

                }

            }
        }

    }
    // 随机落子，如果有多个点的话
    // srand((unsigned)time(0));
    //  int last=rand()%mp;

    state[x][y]=2;

}
