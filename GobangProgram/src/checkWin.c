#include "checkWin.h"



extern int z;
//判断胜负
int judge(int **state, int order, int row, int column) {

    //char str[100];

    if(judge_victory(state, row, column)) {
        switch(order) {
            case 1:
                 printf("黑方获胜!\n");
                 break;
            case 2:
                 printf("白方获胜\n");
                break;
        }
        z = 1;
        return 0;
    }

	if(order == 1)
	{
		z = is_forbid(state, row, column);
    	if(z==3 || z==4 || z==5) {
	        switch(z){
	            case 3:
	                //printf("黑方三三禁手，白方获胜\n");
	                break;
	            case 4:
	                //printf("黑方四四禁手，白方获胜\n");
	                break;
	            case 5:
	                //printf("黑方长连禁手，白方获胜\n");
	                break;
	        }
       	 	return 0;
    	}
	}

    if(!judge_full(state)) {
    	//printf("棋盘已满，形成平局\n");
    	z = 2;
		return -1;
	}

    return 0;
}


//判断棋盘是否满
int judge_full(int **state) {
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COLUMN; j++){
            if(state[i][j] == 0)
                return -1;
        }
    }


    return 0;
}

//五子连珠判断
int judge_victory(int **state, int row, int column) {
    int i, j, num;
    int rol;
    rol =state[row][column];


    if(rol == 0)
        return -1;

    //行判断
	j = column;
	while(j-1>=0 && state[row][j-1]==rol)	j--;			//找左端点
	for(num=1; j+1< COLUMN && state[row][j+1]==rol; j++)	    //找右端点
		num++;
	if(num >= 5)
        return 1;


	i = row;//列判断
	while(i-1>=0 && state[i-1][column]==rol)
        i--;
	for(num=1; i+1<ROW && state[i+1][column]==rol; i++)
		num++;
	if(num >= 5)
        return 1;

    //主对角线判断
	i = row;
	j = column;
	while(i-1>=0 && j-1>=0 && state[i-1][j-1]==rol) {
		i--;
		j--;
	}
	for(num=1; i+1<ROW && j+1<COLUMN && state[i+1][j+1]==rol; i++,j++)
		num++;
	if(num >= 5)
        return 1;

    //副对角线判断
	i = row;
	j = column;
	while(i+1<ROW && j-1>=0 && state[i+1][j-1]==rol) {
		i++;
		j--;
	}
	for(num=1; i-1>=0 && j+1<COLUMN && state[i-1][j+1]==rol; i--,j++)
		num++;
	if(num >= 5)
        return 1;

	return 0;
}

