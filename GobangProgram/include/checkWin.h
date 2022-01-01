#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

/**
 *
 *判断游戏是否结束
 *其中分为禁手判断、胜负判断、和棋判断
 *将数值返回z
 *
 **/
int judge(int **state, int order, int row, int column);        //判断游戏是否结束

/**
 *
 *判断玩家每下一步棋后的是否形成五子连珠
 *
 **/
int judge_victory(int **state, int row, int column);   		   //判断是否出现五子连珠(胜利)

/**
 *
 *判断棋盘是否满了,满了即为和棋
 *
 **/
int judge_full(int **state);                           		   //判断棋盘是否已满


