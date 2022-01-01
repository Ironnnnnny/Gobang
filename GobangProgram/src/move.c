#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include "checkWin.h"

extern int **board;
void playermove(int **state, int row, int column, int order){
	int x, y;
	char a, b;
	char str[100];

	sprintf(str, "���%d-%s��", order, order==1? "�ڷ�" : "�׷�");
	printf("%s����H��A��,������HA:", str);

	while (1) {
		scanf("%c%c",&a,&b);
		fflush(stdin); //������뻺��

		x = a - 'A';
		y = b - 'A';
		if (x >=0 && x <= row-1 && y >= 0 && y <= column-1){
			if (state[x][y]) {
				printf("��λ���Ѿ��������ˣ����±��λ��:");
				continue;
				}
			else{
				state[x][y] = order;
				break;
				}
		}
		else{
			printf("�Ƿ����룬����������:");
			continue;
		}
	}
	judge(state,order,x,y);
}
