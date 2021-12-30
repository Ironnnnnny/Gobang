#include "checkWin.h"
#include "chess.h"
#include <stdio.h>
#include <stdlib.h>

extern int order;
extern int z;
//int begin0 = 0;
//int end0 = 0;
//int i,j;
//int begin1 = 0;
//int end1 = 0;
//int three_sum = 0;
//int four_sum = 0;
//int long_sum = 0;
//int len = 0;




int checkWin(int **state,int row,int column, int flag)
{

//    check_row(state,row,column,flag);
//    check_column(state,row,column,flag);
//    check_diagonal(state,row,column,flag);
//    check_dis_diagonal(state,row,column,flag);

    int begin0 = 0;
    int end0 = 0;
    int i,j;
    int begin1 = 0;
    int end1 = 0;
    int three_sum = 0;
    int four_sum = 0;
    int long_sum = 0;
    int len = 0;


    //�ж����Ƿ���������
    if((column - 4) >=0)
        begin0 = (column - 4);
    else
        begin0 = 1;
    if((column + 4) >=N )
        end0 = N ;
    else
        end0 = (column + 4);

    //����
    for (i = row, j = begin0; j + 4 <= end0; j++)
    {
        if(order == 1)
        {
            if((state[i][j]==flag&&state[i][j+1]==flag&&state[i][j+2]==flag)||(state[i][j]==flag&&state[i][j+2]==flag&&state[i][j+3]==flag))
                three_sum+=1;

            else if (state[i][j]==flag&&state[i][j+1]==flag&&state[i][j+2]==flag&&state[i][j+3]==flag)
                four_sum+=1;

            else if (state[i][j] == flag&&state[i][j + 1] == flag&&state[i][j + 2] == flag&&state[i][j + 3] == flag&&state[i][j + 4] == flag&&state[i][j + 5]==flag)
                long_sum+=1;

            else if (state[i][j] == flag&&state[i][j + 1] == flag&&state[i][j + 2] == flag&&state[i][j + 3] == flag&&state[i][j + 4] == flag&&state[i][j - 1]==flag)
                long_sum+=1;

        }


        if (state[i][j] == flag&&state[i][j + 1] == flag&&
                state[i][j + 2] == flag&&state[i][j + 3] == flag&&
                state[i][j + 4] == flag)
            z=1;
    }
    //�ж����Ƿ���������
    if((row - 4) >= 0 )
        begin0 = (row - 4) ;
    else
        begin0 = 1;
    if((row + 4) >= N )
        end0 = N ;
    else
        end0 = (row + 4);

    for (int j = column, i = begin0; i + 4 <= end0; i++)
    {
        if(order==1)
        {
            if((state[i][j]==flag&&state[i+1][j]==flag&&state[i+2][j]==flag)||(state[i][j]==flag&&state[i+2][j]==flag&&state[i+3][j]==flag))
                three_sum+=1;

            else if(state[i][j]==flag&&state[i+1][j]==flag&&state[i+2][j]==flag&&state[i+3][j]==flag)
                four_sum+=1;

            else if (state[i][j] == flag&&state[i + 1][j] == flag&&state[i + 2][j] == flag&&state[i + 3][j] == flag&&state[i + 4][j] == flag&&state[i + 5][j]==flag )
                long_sum+=1;

            else if (state[i][j] == flag&&state[i + 1][j] == flag&&state[i + 2][j] == flag&&state[i + 3][j] == flag&&state[i + 4][j] == flag&&state[i -1][j]==flag )
                long_sum+=1;
        }

        if (state[i][j] == flag&&state[i + 1][j] == flag&&
                state[i + 2][j] == flag&&state[i + 3][j] == flag&&
                state[i + 4][j] == flag)
            z=1;
    }
    //�ж����Խ����Ƿ���������
    if(row > column )
        len = column - 1 ;
    else
        len = row - 1;
    if (len > 4)
        len = 4;
    begin0 = row - len-1;       //���������ʼλ��
    begin1 = column - len-1;      //���������ʼλ��

    if(row > column )
        len = (N - row) ;
    else
        len = (N - column);
    if (len>4)
        len = 4;
    end0 = row + len-1;       //������Ľ���λ��
    end1 = column + len-1;      //������Ľ���λ��

    for (int i = begin0, j = begin1; (i + 4 <= end0) && (j + 4 <= end1); ++i, ++j)
    {
        if(order==1)
        {
            if((state[i][j] == flag&&state[i + 1][j + 1] == flag&&state[i + 2][j + 2] == flag)||(state[i][j] == flag&&state[i + 2][j + 2] == flag&&state[i + 3][j + 3] == flag))
                three_sum+=1;

            else if(state[i][j] == flag&&state[i + 1][j + 1] == flag&&state[i + 2][j + 2] == flag&&state[i + 3][j + 3] == flag)
                four_sum+=1;

            else if (state[i][j] == flag&&state[i + 1][j + 1] == flag&&state[i + 2][j + 2] == flag&&state[i + 3][j + 3] == flag&&state[i + 4][j + 4] == flag&&state[i + 5][j + 5]==flag )
                long_sum+=1;

            else if (state[i][j] == flag&&state[i + 1][j + 1] == flag&&state[i + 2][j + 2] == flag&&state[i + 3][j + 3] == flag&&state[i + 4][j + 4] == flag&&state[i - 1][j - 1]==flag )
                long_sum+=1;



        }

        if (state[i][j] == flag&&state[i + 1][j + 1] == flag&&
                state[i + 2][j + 2] == flag&&state[i + 3][j + 3] == flag&&
                state[i + 4][j + 4] == flag)
            z=1;
    }

    //�жϸ��Խ����Ƿ���������
    if( (row - 1) >(N - column) )
        len = (N - column) ;
    else
        len = row - 1;
    if (len > 4)
        len = 4;
    begin0 = row - len;       //���������ʼλ��
    begin1 = column + len;      //���������ʼλ��

    if((N - row) > (column - 1) )
        len = (column - 1) ;
    else
        len = (N - row);
    if (len>4)
        len = 4;
    end0 = row + len;       //������Ľ���λ��
    end1 = column - len;      //������Ľ���λ��


    for (int i = begin0, j = begin1; (i + 4 <= end0) && (j - 4 >= end1); ++i, --j)
    {


        if (state[i][j] == flag&&state[i + 1][j - 1] == flag&&
                state[i + 2][j - 2] == flag&&state[i + 3][j - 3] == flag&&
                state[i + 4][j - 4] == flag)
        {
            z = 1;
            break;
        }
        if(order==1)
        {
            if((state[i][j] == flag&&state[i + 1][j - 1] == flag&&state[i + 2][j - 2] == flag)||(state[i][j] == flag&&state[i + 2][j - 2] == flag&&state[i + 3][j - 3] == flag))
                three_sum+=1;

            else if(state[i][j] == flag&&state[i + 1][j - 1] == flag&&state[i + 2][j - 2] == flag&&state[i + 3][j - 3] == flag)
                four_sum+=1;

            else if (state[i][j] == flag&&state[i + 1][j - 1] == flag&&state[i + 2][j - 2] == flag&&state[i + 3][j - 3] == flag&&state[i + 4][j - 4] == flag&&state[i + 5][j - 5]==flag )
                long_sum+=1;

            else if (state[i][j] == flag&&state[i + 1][j - 1] == flag&&state[i + 2][j - 2] == flag&&state[i + 3][j - 3] == flag&&state[i + 4][j - 4] == flag&&state[i - 1][j + 1]==flag )
                long_sum+=1;

        }
    }

    //��������
    if(three_sum>=2)
    {
        z=-3;
        return 0;
    }

    //���Ľ���
    if(four_sum>=2)
    {
        z=-4;
        return 0;
    }

    //��������
    if(long_sum>=1)
    {
        z=-2;
        return 0;
    }

    for (int i = 0; i < N ; ++i)           //������û������
    {
        for (int j =0; j < N ; ++j)
        {
            if (state[i][j] == 0)
                return 0;                      //0��ʾ����û��
        }
    }
    z=-1;
    return 0;      //����

}



