#include "forbid.h"



//��������
bool overLine(int **state, int row, int column)
{
    int i, j, num;

    //����
    j = column;
    while(j-1>=0 && state[row][j-1]==1)
    {
        j--;			//Ѱ������������˵�
    }

    for(num=1; j+1<COLUMN && state[row][j+1]==1; j++)	    //Ѱ�����������Ҷ˵�
        num++;												//�ۼƺ�������������
    if(num>5)
        return true;

    //����
    i = row;
    while(i-1>=0 && state[i-1][column]==1)	{
        i--;			//Ѱ�����������϶˵�
    }

    for(num=1; i+1<ROW && state[i+1][column]==1; i++)	        //Ѱ�����������¶˵�
        num++;
    if(num>5)
        return true;

    //��������(\)
    i = row;
    j = column;
    while(i-1>=0 && j-1>=0 && state[i-1][j-1]==1)  					//Ѱ�������������϶˵�
    {
        i--;
        j--;
    }
    for(num=1; i+1<ROW && j+1<COLUMN && state[i+1][j+1]==1; i++,j++)	//Ѱ�������������¶˵�
        num++;
    if(num>5)	return true;

    //��������(/)
    i = row;
    j = column;
    while(i+1<ROW && j-1>=0 && state[i+1][j-1]==1)  		 			//Ѱ�������������¶˵�
    {
        i++;
        j--;
    }
    for(num=1; i-1>0 && j+1<COLUMN && state[i-1][j+1]==1; i--,j++)	//Ѱ�������������϶˵�
        num++;
    if(num>5)	return true;

    return false;
}


//��������
bool threeLine(int **state, int row, int column)
{
    int i, j;
    int left, right, top, blank;    //�����ҵ�������ꣻ���ϡ��µ��������
    int flag[4] = {1, 1, 1, 1};     //�����ĸ������γɻ���

    //�����ж�
    blank = 0;
    j =  column;
    while((j-1>=0 && state[row][j-1]==1) || 						//������˵������ 1����-
            (j-2>=0 && state[row][j-1]==0 && state[row][j-2]==1))//2����-��-
        {
            j--;
        }

    left = j;														//��¼�����λ��
    while((j+1<COLUMN && state[row][j+1]==1) ||					//�����Ҷ˵������1��-��
            (j+2<COLUMN && state[row][j+1]==0 && state[row][j+2]==1))  //2��-��-��
    {
        if(state[row][j]==0)									    //ͳ�����˵�֮��Ŀ�λ��
            blank++;
        j++;
    }
    if(j-left+1-blank != 3)												//�ж������˵�֮��ĺ������Ƿ�պõ���3
        flag[0] = 0;                                                    //������3���ǻ���
    else if(left-1<0 || j+1>=COLUMN || state[row][left-1]==2 || state[row][j+1]==2)
        flag[0] = 0;													//�ж����Ҷ˵���Ե�����λ���Ƿ�Ϊ��λ
    else if(blank > 1)                                                  //�ж����Ҷ˵�֮��Ŀո����1
        flag[0] = 0;                                                    //����1���ǻ���
    else if((blank==0) && (left-2<0 || state[row][left-2]==2) &&		//0��λ����������������������1��
            (j+2>=COLUMN || state[row][j+2]==2))								//�ж��Ƿ�Ϊ ��/��-��-��-��-��-��-��/�� �ļٻ���
        flag[0] = 0;
    else if((blank==0) && (left-3>=0 && state[row][left-3]==1) && 	//0��λ����������������������2��
            (j+3<COLUMN && state[row][j+3]==1))								//�ж��Ƿ�Ϊ ��-��-��-��-��-��-��-��-�� �ļٻ���
        flag[0] = 0;

    //�����ж�
    blank = 0;
    i = row;
    while((i-1>=0 && state[i-1][column]==1) ||
            (i-2>=0 && state[i-1][column]==0 && state[i-2][column]==1))
        i--;
    top = i;    //��¼����(���Ϸ�)��������
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

    //��������(\)
    blank = 0;
    i = row;
    j = column;
    while((i-1>=0 && j-1>=0 && state[i-1][j-1]==1) ||
            (i-2>=0 && j-2>=0 && state[i-1][j-1]==0 && state[i-2][j-2]==1))
    {
        i--;
        j--;
    }
    top = i;    //��¼���Ͻǵ�������
    left = j;   //��¼���Ͻǵ�������
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

    //��������(/)
    blank = 0;
    i = row;
    j = column;
    while((i-1>=0 && j+1<COLUMN && state[i-1][j+1]==1) ||
            (i-2>=0 && j+2<COLUMN && state[i-1][j+1]==0 && state[i-2][j+2]==1))
    {
        i--;
        j++;
    }
    top = i;    //��¼���Ͻǵ�������
    right = j;  //��¼���Ͻǵ�������
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

//���Ľ���
bool fourLine(int **state, int row, int column)
{
    int i, j;
    int blank, left, right, top;
    int flag[4] = {0, 0, 0, 0};

    //�����ж�
    blank = 0;
    j = column;
    while((j-1>=0 && state[row][j-1]==1) || (blank==0 &&          //Ѱ����˵�
            (j-2>=0 && state[row][j-1]==0 && state[row][j-2]==1)))     //���˵�֮�����ֻ�ܴ���һ����λ
    {
        if(state[row][j] == 0)	blank = 1;                          //ͳ�ƿ�λ��
        j--;
    }
    left = j;                                                       //��¼��˵�
    blank = 0;
    while((j+1<COLUMN && state[row][j+1]==1) || (blank==0 &&
            (j+2<COLUMN && state[row][j+1]==0 && state[row][j+2]==1)))
    {
        if(state[row][j] == 0)	blank = 1;
        j++;
    }
    if(j-left+1-blank == 4)                                 //�����˵�֮�����ֻ���ĸ�����ʱ
    {
        if(blank == 1)		                                //���˵�֮�����һ����λ������
            flag[0] = 1;
        else
        {
            if((left-1>=0 && state[row][left-1]==0) ||		//���˵�֮��û�п�λ
                    (j+1<COLUMN && state[row][j+1]==0))			//��˵���ࡢ���Ҷ˵��Ҳ����һ����λ
                flag[0] = 1;								//����Ϊ���Ļ����
        }
    }

    //�����ж�
    blank = 0;
    i = row;
    while((i-1>=0 && state[i-1][column]==1) || (blank==0 &&
            (i-2>=0 && state[i-1][column]==0 && state[i-2][column]==1)))
    {
        if(state[i][column] == 0)	blank = 1;
        i--;
    }
    top = i;     //��¼����(��ߵ�)������
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

    //��������(\)
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
    top = i;    //��¼���Ͻǵĺ�����
    left = j;   //��¼���Ͻǵ�������
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

    //��������(/)
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
    top = i;    //��¼���Ͻǵĺ�����
    right = j;  //��¼���Ͻǵ�������
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


    return 0;	//���������������δ�γɽ���
}
