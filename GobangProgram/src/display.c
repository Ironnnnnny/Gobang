#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
void draw(int **state, int row, int column){
	//system("cls"); //«Â∆¡
	int i,j;
	printf("  ");
	for (i = 0; i < column; i++)
		printf("%c ", (char)(i+65));
    printf("\n");
	for (i = 0; i < row; i++) {
		printf("%c ", (char)(i+65));
		for (j = 0; j < column; j++) {
			switch(state[i][j]){
				case 0:
					if (j > 0 && j < column-1)
						printf("%s", (i == 0 ? TOP_CENTER : i == row-1? BOTTOM_CENTER : INTERNAL));
					else if (j == 0)
						printf("%s", (i == 0 ? LEFT_TOP : i == row-1 ? LEFT_BOTTOM : LEFT_CENTER));
					else if(j == column-1)
						printf("%s", (i == 0 ? RIGHT_TOP : i == row-1 ? RIGHT_BOTTOM : RIGHT_CENTER));
					break;
				case 1:
					printf("%s", BLACK);
					break;
				case 2:
					printf("%s", WHITE);
					break;
				default:
					break;
			}
		}
		printf("\n");
	}
}
