#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include "checkWin.h"
#include "move.h"
#include "display.h"
#include "ComputerMode.h"
#include "choiceMode.h"


int main()
{
    extern int order;
    extern int z;
    extern int **board;

    while(1)
    {
        order = 1;
        int i,j;
        //int **board;
        //1�ڷ�,2�׷�;�����Ǻڷ�����,���ڷ����н���
        board = malloc(sizeof(int*)*ROW);
        for(i = 0; i < ROW; i++)
            board[i] = malloc(sizeof(int)*COLUMN);
        for(i = 0; i < ROW; i++)
            for(j = 0; j < COLUMN; j++)
                board[i][j] = 0;
        draw(board, ROW, COLUMN);
        int P=ChoiceMode();
        fflush(stdin);
        if(P==1)  //�˻�
        {
            while(1)
            {
                playermove(board, ROW, COLUMN, order);
                draw(board, ROW, COLUMN);
                if(z==1)
                {
                    if(order==1)
                        printf("\n�ڷ�ʤ����");
                    else
                        printf("\n�׷�ʤ����");
                    z=0;
                    break;
                }
                else if(z==-1)
                {
                    printf("����!");
                    z=0;
                    break;
                }
                else if( z == -2 )
                {
                    printf("�ڷ����ַ��棡�׷�ʤ����");
                }
                else
                    ;
                order = order%2+1;

                ComputerMode(board,ROW,COLUMN);
                draw(board, ROW, COLUMN);
                if(z==1)
                {
                    if(order==1)
                        printf("�ڷ�ʤ����");
                    else
                        printf("�׷�ʤ����");
                    z=0;
                    break;
                }
                else if(z==-1)
                {
                    printf("����!");
                    z=0;
                    break;
                }
                else if(z==-2)
                {
                    printf("�ڷ����ַ��棡�׷�ʤ����");
                }
                else
                    ;
                order = order%2+1;
            }
        }

        else if(P==2)
        {
            while(1)
            {
                playermove(board, ROW, COLUMN, order);
                draw(board, ROW, COLUMN);
                //printf("%d",z);
                if(z==1)
                {
                    if(order == 1)
                        printf("�ڷ�ʤ����");
                    else
                        printf("�׷�ʤ����");
                    z=0;
                    break;
                }
                else if(z==-1)
                {
                    printf("����!");
                    z=0;
                    break;
                }
                else if(z==-2)
                {
                    printf("�ڷ��������ַ��棡�׷�ʤ����");
                }
                else if(z==-3)
                {
                    printf ("�ڷ��������ַ��棡�׷�ʤ����");
                }
                else if(z==-4)
                {
                    printf("�ڷ����Ľ��ַ��棡�׷�ʤ����");
                }

                order = order%2+1;
            }
        }
        else
            break;
        system("pause");
        for(i = 0; i < ROW; i++)
            free(board[i]);
        free(board);
    }

    return 0;

}
