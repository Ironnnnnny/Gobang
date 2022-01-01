#include "forbid.h"



//长连禁手
bool overLine(int **state, int row, int column)
{
    int i, j, num;

    //横向
    j = column;
    while(j-1>=0 && state[row][j-1]==1)
    {
        j--;			//寻找连续黑棋左端点
    }

    for(num=1; j+1<COLUMN && state[row][j+1]==1; j++)	    //寻找连续黑棋右端点
        num++;												//累计横向连续黑棋数
    if(num>5)
        return true;

    //纵向
    i = row;
    while(i-1>=0 && state[i-1][column]==1)	{
        i--;			//寻找连续黑棋上端点
    }

    for(num=1; i+1<ROW && state[i+1][column]==1; i++)	        //寻找连续黑棋下端点
        num++;
    if(num>5)
        return true;

    //左上右下(\)
    i = row;
    j = column;
    while(i-1>=0 && j-1>=0 && state[i-1][j-1]==1)  					//寻找连续黑棋左上端点
    {
        i--;
        j--;
    }
    for(num=1; i+1<ROW && j+1<COLUMN && state[i+1][j+1]==1; i++,j++)	//寻找连续黑棋右下端点
        num++;
    if(num>5)	return true;

    //左下右上(/)
    i = row;
    j = column;
    while(i+1<ROW && j-1>=0 && state[i+1][j-1]==1)  		 			//寻找连续黑棋左下端点
    {
        i++;
        j--;
    }
    for(num=1; i-1>0 && j+1<COLUMN && state[i-1][j+1]==1; i--,j++)	//寻找连续黑棋右上端点
        num++;
    if(num>5)	return true;

    return false;
}


//三三禁手
bool threeLine(int **state, int row, int column)
{
    int i, j;
    int left, right, top, blank;    //最左、右点的列坐标；最上、下点的行坐标
    int flag[4] = {1, 1, 1, 1};     //假设四个方向都形成活三

    //横向判断
    blank = 0;
    j =  column;
    while((j-1>=0 && state[row][j-1]==1) || 						//符合左端点的条件 1：黑-
            (j-2>=0 && state[row][j-1]==0 && state[row][j-2]==1))//2：黑-空-
        {
            j--;
        }

    left = j;														//记录左起点位置
    while((j+1<COLUMN && state[row][j+1]==1) ||					//符合右端点的条件1：-黑
            (j+2<COLUMN && state[row][j+1]==0 && state[row][j+2]==1))  //2：-空-黑
    {
        if(state[row][j]==0)									    //统计两端点之间的空位数
            blank++;
        j++;
    }
    if(j-left+1-blank != 3)												//判断两个端点之间的黑棋数是否刚好等于3
        flag[0] = 0;                                                    //不等于3：非活三
    else if(left-1<0 || j+1>=COLUMN || state[row][left-1]==2 || state[row][j+1]==2)
        flag[0] = 0;													//判断左、右端点各自的左右位置是否为空位
    else if(blank > 1)                                                  //判断左、右端点之间的空格大于1
        flag[0] = 0;                                                    //大于1，非活三
    else if((blank==0) && (left-2<0 || state[row][left-2]==2) &&		//0空位的连续三个黑棋的特殊情况1，
            (j+2>=COLUMN || state[row][j+2]==2))								//判断是否为 白/界-空-黑-黑-黑-空-白/界 的假活三
        flag[0] = 0;
    else if((blank==0) && (left-3>=0 && state[row][left-3]==1) && 	//0空位的连续三个黑棋的特殊情况2，
            (j+3<COLUMN && state[row][j+3]==1))								//判断是否为 黑-空-空-黑-黑-黑-空-空-黑 的假活三
        flag[0] = 0;

    //纵向判断
    blank = 0;
    i = row;
    while((i-1>=0 && state[i-1][column]==1) ||
            (i-2>=0 && state[i-1][column]==0 && state[i-2][column]==1))
        i--;
    top = i;    //记录顶点(最上方)的行坐标
    while((i+1<ROW && state[i+1][column]==1) ||
            (i+2<ROW && state[i+1][column]==0 && state[i+2][column]==1))
    {
        if(state[i][column]==0)
            blank++;
        i++;
    }
    if(top-1<0 || i+1>=ROW || state[top-1][column]==2 || state[i+1][column]==2)
        flag[1] = 0;
    else if(i-top+1-blank != 3)
        flag[1] = 0;
    else if(blank > 1)
        flag[1] = 0;
    else if((blank==0) && (top-2<0 || state[top-2][column]==2) &&
            (i+2>=ROW || state[i+2][column]==2))
        flag[1] = 0;
    else if((blank==0) && (top-3>=0 && state[top-3][column]==1) &&
            (i+3<ROW && state[i+3][column]==1))
        flag[1] = 0;

    //左上右下(\)
    blank = 0;
    i = row;
    j = column;
    while((i-1>=0 && j-1>=0 && state[i-1][j-1]==1) ||
            (i-2>=0 && j-2>=0 && state[i-1][j-1]==0 && state[i-2][j-2]==1))
    {
        i--;
        j--;
    }
    top = i;    //记录左上角的行坐标
    left = j;   //记录左上角的列坐标
    while((i+1<ROW && j+1<COLUMN && state[i+1][j+1]==1) ||
            (i+2<ROW && j+2<COLUMN && state[i+1][j+1]==0 && state[i+2][j+2]==1))
    {
        i++;
        j++;
        if(state[i][j] == 0)
            blank++;
    }
    if(top-1<0 ||left-1<0 || state[top-1][left-1]==2 ||
            i+1>=ROW || j+1>=COLUMN || state[i+1][j+1]==2)
        flag[2] = 0;
    else if(j-left+1-blank != 3)
        flag[2] = 0;
    else if(blank > 1)
        flag[2] = 0;
    else if((blank==0) && (top-2<0 || left-2<0 || state[top-2][left-2]==2) &&
            (i+2>=ROW || j+2>=COLUMN || state[i+2][j+2]==2))
        flag[2] = 0;
    else if((blank==0) && (top-3>=0 && left-3>=0 && state[top-3][left-3]==1)
            && (i+3<ROW && j+3<COLUMN && state[i+3][j+3]==1))
        flag[2] = 0;

    //左下右上(/)
    blank = 0;
    i = row;
    j = column;
    while((i-1>=0 && j+1<COLUMN && state[i-1][j+1]==1) ||
            (i-2>=0 && j+2<COLUMN && state[i-1][j+1]==0 && state[i-2][j+2]==1))
    {
        i--;
        j++;
    }
    top = i;    //记录右上角的行坐标
    right = j;  //记录右上角的列坐标
    while((i+1<ROW && j-1>=0 && state[i+1][j-1]==1) ||
            (i+2<ROW && j-2>=0 && state[i+1][j-1]==0 && state[i+2][j-2]==1))
    {
        i++;
        j--;
        if(state[i][j] == 0)
            blank++;
    }
    if(top-1<0 || right+1>=COLUMN || state[top-1][right+1]==2 ||
            i+1>=ROW || j-1<0 || state[i+1][j-1]==2)
        flag[3] = 0;
    else if(right-j+1-blank != 3)
        flag[3] = 0;
    else if(blank > 1)
        flag[3] = 0;
    else if(blank==0 && (top-2<0 || right+2>=COLUMN || state[top-2][right+2]==2) &&
            (i+2>=ROW || j-2<0 || state[i+2][j-2]==2))
        flag[3] = 0;
    else if((blank==0) && (top-3>=0 && right+3<COLUMN && state[top-3][right+3]==1)
            && (i+3<ROW && j-3>=0 && state[i+3][j-3]==1))
        flag[3] = 0;


    if(flag[0]+flag[1]+flag[2]+flag[3] > 1)
    {
        printf("three_threeLine:%2d%2d%2d%2d\n",flag[0],flag[1],flag[2],flag[3]);
        return true;
    }
    else
        return false;
}

//四四禁手
bool fourLine(int **state, int row, int column)
{
    int i, j;
    int blank, left, right, top;
    int flag[4] = {0, 0, 0, 0};

    //横向判断
    blank = 0;
    j = column;
    while((j-1>=0 && state[row][j-1]==1) || (blank==0 &&          //寻找左端点
            (j-2>=0 && state[row][j-1]==0 && state[row][j-2]==1)))     //两端点之间最多只能存在一个空位
    {
        if(state[row][j] == 0)	blank = 1;                          //统计空位数
        j--;
    }
    left = j;                                                       //记录左端点
    blank = 0;
    while((j+1<COLUMN && state[row][j+1]==1) || (blank==0 &&
            (j+2<COLUMN && state[row][j+1]==0 && state[row][j+2]==1)))
    {
        if(state[row][j] == 0)	blank = 1;
        j++;
    }
    if(j-left+1-blank == 4)                                 //当两端点之间仅仅只有四个黑棋时
    {
        if(blank == 1)		                                //两端点之间存在一个空位，冲四
            flag[0] = 1;
        else
        {
            if((left-1>=0 && state[row][left-1]==0) ||		//两端点之间没有空位
                    (j+1<COLUMN && state[row][j+1]==0))			//左端点左侧、或右端点右侧存在一个空位
                flag[0] = 1;								//可能为冲四或活四
        }
    }

    //纵向判断
    blank = 0;
    i = row;
    while((i-1>=0 && state[i-1][column]==1) || (blank==0 &&
            (i-2>=0 && state[i-1][column]==0 && state[i-2][column]==1)))
    {
        if(state[i][column] == 0)	blank = 1;
        i--;
    }
    top = i;     //记录顶点(最高点)横坐标
    blank = 0;
    while((i+1<ROW && state[i+1][column]==1) || (blank==0 &&
            (i+2<ROW && state[i+1][column]==0 && state[i+2][column]==1)))
    {
        if(state[i][column] == 0)	blank = 1;
        i++;
    }
    if(i-top+1-blank == 4)
    {
        if(blank == 1)
            flag[1] = 1;
        else
        {
            if((top-1>=0 && state[top-1][column]==0) ||
                    (i+1<ROW && state[i+1][column]==0))
                flag[1] = 1;
        }
    }

    //左上右下(\)
    blank = 0;
    i = row;
    j = column;
    while((i-1>=0 && j-1>=0 && state[i-1][j-1]==1) || (blank==0 &&
            (i-2>=0 && j-2>=0 && state[i-1][j-1]==0 && state[i-2][j-2]==1)))
    {
        if(state[i][j] == 0)	blank = 1;
        i--;
        j--;
    }
    top = i;    //记录左上角的横坐标
    left = j;   //记录左上角的纵坐标
    blank = 0;
    while((i+1<ROW && j+1<COLUMN && state[i+1][j+1]==1) || (blank==0 &&
            (i+2<ROW && j+2<COLUMN && state[i+1][j+1]==0 && state[i+2][j+2]==1)))
    {
        if(state[i][j] == 0)	blank=1;
        i++;
        j++;
    }
    if(j-left+1-blank == 4)
    {
        if(blank == 1)
            flag[2] = 1;
        else
        {
            if((top-1>=0 && left-1>=0 && state[top-1][left-1]==0) ||
                    (i+1<ROW && j+1<COLUMN && state[i+1][j+1]==0))
                flag[2] = 1;
        }
    }

    //左下右上(/)
    blank = 0;
    i = row;
    j = column;
    blank = 0;
    while((i-1>=0 && j+1<COLUMN && state[i-1][j+1]==1) || (blank==0 &&
            (i-2>=0 && j+2<COLUMN && state[i-1][j+1]==0 && state[i-2][j+2]==1)))
    {
        if(state[i][j] == 0)	blank=1;
        i--;
        j++;
    }
    top = i;    //记录右上角的横坐标
    right = j;  //记录右上角的纵坐标
    while((i+1<ROW && j-1>=0 && state[i+1][j-1]==1) || (blank==0 &&
            (i+2<ROW && j-2>=0 && state[i+1][j-1]==0 && state[i+2][j-2]==1)))
    {
        if(state[i][j] == 0)	blank=1;
        i++;
        j--;
    }
    if(right-j+1-blank == 4)
    {
        if(blank == 1)
            flag[3] = 1;
        else
        {
            if((top-1>=0 && right+1<COLUMN && state[top-1][right+1]==0) ||
                    (i+1<ROW && j-1>=0 && state[i+1][j-1]==0))
                flag[3] = 1;
        }
    }

    if(flag[0]+flag[1]+flag[2]+flag[3] > 1)
    {
        printf("three_threeLine:%2d%2d%2d%2d\n",flag[0],flag[1],flag[2],flag[3]);
        return true;
    }
    else
        return false;
}


int is_forbid(int **state, int row, int column)
{
    if(threeLine(state, row, column))
    {
        return 3;
    }

    if(fourLine(state, row, column))
    {
        return 4;
    }

    if(overLine(state, row, column))
    {
        return 5;
    }


    return 0;	//不存在以上情况，未形成禁手
}
