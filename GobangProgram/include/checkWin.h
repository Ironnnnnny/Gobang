#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

/**
 *
 *�ж���Ϸ�Ƿ����
 *���з�Ϊ�����жϡ�ʤ���жϡ������ж�
 *����ֵ����z
 *
 **/
int judge(int **state, int order, int row, int column);        //�ж���Ϸ�Ƿ����

/**
 *
 *�ж����ÿ��һ�������Ƿ��γ���������
 *
 **/
int judge_victory(int **state, int row, int column);   		   //�ж��Ƿ������������(ʤ��)

/**
 *
 *�ж������Ƿ�����,���˼�Ϊ����
 *
 **/
int judge_full(int **state);                           		   //�ж������Ƿ�����


