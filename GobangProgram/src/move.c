#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include "checkWin.h"

extern int **board;
void playermove(int **state, int row, int column, int order){
	int x, y;
	char a, b;
	char str[100];

	sprintf(str, "玩家%d-%s走", order, order==1? "黑方" : "白方");
	printf("%s，如H行A列,则输入HA:", str);

	while (1) {
		scanf("%c%c",&a,&b);
		fflush(stdin); //清空输入缓冲

		x = a - 'A';
		y = b - 'A';
		if (x >=0 && x <= row-1 && y >= 0 && y <= column-1){
			if (state[x][y]) {
				printf("该位置已经有棋子了，请下别的位置:");
				continue;
				}
			else{
				state[x][y] = order;
				break;
				}
		}
		else{
			printf("非法输入，请重新输入:");
			continue;
		}
	}
	judge(state,order,x,y);
}
