#include "choiceMode.h"
#include <stdio.h>
int ChoiceMode() //ѡ��ģʽ
{
    int i = 0;
    printf("0.�˳� 1.����vs��� 2���vs��ң�");
    while (1)
    {
        printf("��ѡ��(��������)��  ");
        scanf("%d",&i);
        if (i == 0) //ѡ��0�˳�
            exit(1);
        if (i == 1 || i == 2)
            return i;
        printf("���벻�Ϸ�");
    }
}
