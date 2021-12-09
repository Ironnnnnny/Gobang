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
        //1黑方,2白方;规则是黑方先走,但黑方会有禁手
        board = malloc(sizeof(int*)*ROW);
        for(i = 0; i < ROW; i++)
            board[i] = malloc(sizeof(int)*COLUMN);
        for(i = 0; i < ROW; i++)
            for(j = 0; j < COLUMN; j++)
                board[i][j] = 0;
        draw(board, ROW, COLUMN);
        int P=ChoiceMode();
        fflush(stdin);
        if(P==1)  //人机
        {
            while(1)
            {
                playermove(board, ROW, COLUMN, order);
                draw(board, ROW, COLUMN);
                if(z==1)
                {
                    if(order==1)
                        printf("\n黑方胜利！");
                    else
                        printf("\n白方胜利！");
                    z=0;
                    break;
                }
                else if(z==-1)
                {
                    printf("和棋!");
                    z=0;
                    break;
                }
                else if( z == -2 )
                {
                    printf("黑方禁手犯规！白方胜利！");
                }
                else
                    ;
                order = order%2+1;

                ComputerMode(board,ROW,COLUMN);
                draw(board, ROW, COLUMN);
                if(z==1)
                {
                    if(order==1)
                        printf("黑方胜利！");
                    else
                        printf("白方胜利！");
                    z=0;
                    break;
                }
                else if(z==-1)
                {
                    printf("和棋!");
                    z=0;
                    break;
                }
                else if(z==-2)
                {
                    printf("黑方禁手犯规！白方胜利！");
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
                        printf("黑方胜利！");
                    else
                        printf("白方胜利！");
                    z=0;
                    break;
                }
                else if(z==-1)
                {
                    printf("和棋!");
                    z=0;
                    break;
                }
                else if(z==-2)
                {
                    printf("黑方长连禁手犯规！白方胜利！");
                }
                else if(z==-3)
                {
                    printf ("黑方三三禁手犯规！白方胜利！");
                }
                else if(z==-4)
                {
                    printf("黑方四四禁手犯规！白方胜利！");
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
