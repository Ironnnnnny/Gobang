#include "Judege.h"
#include "chess.h"

extern int z;
extern int order;

void judege_win(int **state,int flag)
{
    int i,j;

    //判断行
    for(i=0;i<=N;i++)
    {
        for(j=0;j<=N;j++)
        {
            if(order == 1)
            {
                if (state[i][j] == flag&&state[i][j + 1] == flag&&
                state[i][j + 2] == flag&&state[i+2][j+2] == flag&&state[i+2][j+3] == flag)
                {
                    z=-2;
                    break;
                }
            }

            //行
            if (state[i][j] == flag&&state[i][j + 1] == flag&&
                state[i][j + 2] == flag&&state[i][j + 3] == flag&&
                state[i][j + 4] == flag)
            z=1;
            //列
            if (state[i][j] == flag&&state[i + 1][j] == flag&&
                state[i + 2][j] == flag&&state[i + 3][j] == flag&&
                state[i + 4][j] == flag)
            z=1;
            //对角线
            if (state[i][j] == flag&&state[i + 1][j + 1] == flag&&
                state[i + 2][j + 2] == flag&&state[i + 3][j + 3] == flag&&
                state[i + 4][j + 4] == flag)
            z=1;
            //反对角线
            if (state[i][j] == flag&&state[i + 1][j - 1] == flag&&
                state[i + 2][j - 2] == flag&&state[i + 3][j - 3] == flag&&
                state[i + 4][j - 4] == flag)
            z=1;
        }
    }

}
