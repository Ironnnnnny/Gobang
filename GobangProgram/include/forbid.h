#include <stdio.h>
#include "chess.h"
#include <stdbool.h>
/**
 *
 *长连禁手判断
 *
 **/
bool overLine(int **state, int row, int column);

/**
 *
 *三三禁手判断
 *其中包括了活三和假活三的判断
 *
 **/
bool threeLine(int **state, int row, int column);

/**
 *
 *四四禁手判断
 *包括了死四和活四的判断
 *
 **/
bool fourLine(int **state, int row, int column);

/**
 *
 *判断棋子是否为禁手模式
 *若棋子为禁手模式则返回3(三三禁手)、4(四四禁手)、5(长连禁手)
 *
 **/
int is_forbid(int **state, int row, int column);



