#include <stdio.h>
#include "chess.h"
#include <stdbool.h>
/**
 *
 *���������ж�
 *
 **/
bool overLine(int **state, int row, int column);

/**
 *
 *���������ж�
 *���а����˻����ͼٻ������ж�
 *
 **/
bool threeLine(int **state, int row, int column);

/**
 *
 *���Ľ����ж�
 *���������ĺͻ��ĵ��ж�
 *
 **/
bool fourLine(int **state, int row, int column);

/**
 *
 *�ж������Ƿ�Ϊ����ģʽ
 *������Ϊ����ģʽ�򷵻�3(��������)��4(���Ľ���)��5(��������)
 *
 **/
int is_forbid(int **state, int row, int column);



