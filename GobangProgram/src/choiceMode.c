#include "choiceMode.h"
#include <stdio.h>
int ChoiceMode() //选择模式
{
    int i = 0;
    printf("0.退出 1.电脑vs玩家 2玩家vs玩家，");
    while (1)
    {
        printf("请选择(输入数字)：  ");
        scanf("%d",&i);
        if (i == 0) //选择0退出
            exit(1);
        if (i == 1 || i == 2)
            return i;
        printf("输入不合法");
    }
}
