#include "ComputerMode.h"

void ComputerMode(int **state, int row, int column)
{
    // ͳ����һ��ߵ������ɵ���
    int personNum = 0; // ��������ӵĸ���
    int botNum = 0; // AI�����ӵĸ���
    int emptyNum = 0; // ������հ�λ�ĸ���
    int goodadress[row][column];
    int r,col;
    int i,j;
    int maxscore=0;
    int x=0,y=0;
    int mp=0;
    int a[10];
    int b[10];
// �����������
    for( i=0; i<row; i++)
    {
        for( j=0; j<column; j++)
        {
            goodadress[i][j]=0;
        }
    }
    // �Ʒ֣��˴�����ȫ��������ʵ������bfs����dfs�Ӽ�֦���͸��Ӷȣ�ͨ������Ȩ��ֵ������AI���̶ܳ��Լ����ط��
    for ( r=0; r< row; r++)

    {

        for ( col = 0; col < column; col++)
        {
            // �հ׵����
            if (r >= 0 && col >= 0 &&
                    state[r][col] == 0)
            {
                // ������Χ�˸�����
                for ( y = -1; y <= 1; y++)



                    for ( x = -1; x <= 1; x++)
                    {
                        // ����
                        personNum = 0;
                        botNum = 0;
                        emptyNum = 0;

                        // ԭ���겻��
                        if (!(y == 0 && x == 0))
                        {
                            // ÿ����������4����

                            // ����Ұ������֣�������������
                            for ( i = 1; i <= 4; i++)
                            {
                                if (r + i * y > 0 && r + i * y < row &&
                                        col + i * x > 0 && col + i * x < column &&
                                        state[r + i * y][col + i * x] == 1) // ��ҵ���
                                {
                                    personNum++;
                                }
                                else if (r + i * y > 0 && r + i * y < row &&
                                         col + i * x > 0 && col + i * x < column &&
                                         state[r + i * y][col + i * x] == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else
                                    // ���߽�

                                    break;
                            }

                            for ( i = 1; i <= 4; i++)
                            {
                                if (r - i * y > 0 && r - i * y < row &&
                                        col - i * x > 0 && col - i * x < column &&
                                        state[r - i * y][col - i * x] == 1) // ��ҵ���
                                {
                                    personNum++;
                                }
                                else if (r - i * y > 0 && r - i * y < row &&
                                         col - i * x > 0 && col - i * x < column &&
                                         state[r - i * y][col - i * x] == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // ���߽�
                                    break;
                            }


                            if (personNum == 1)                      // ɱ��
                                goodadress[r][col] += 10;
                            else if (personNum == 2)                 // ɱ��
                            {
                                if (emptyNum == 1)
                                    goodadress[r][col] += 30;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 40;
                            }
                            else if (personNum == 3)                 // ɱ��
                            {
                                // �����λ��һ�������ȼ���һ��
                                if (emptyNum == 1)
                                    goodadress[r][col] += 60;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 110;
                            }
                            else if (personNum == 4)                 // ɱ��
                                goodadress[r][col] += 10100;

                            // ����һ�����
                            emptyNum = 0;

                            // ��AI��������
                            for ( i = 1; i <= 4; i++)
                            {
                                if (r + i * y > 0 && r + i * y < row &&
                                        col + i * x > 0 && col + i * x < column &&
                                        state[r + i * y][col + i * x] == 1) // ��ҵ���
                                {
                                    botNum++;
                                }
                                else if (r + i * y > 0 && r + i * y < row &&
                                         col + i * x > 0 && col + i * x < column &&
                                         state[r +i * y][col + i * x] == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // ���߽�
                                    break;
                            }

                            for ( i = 1; i <= 4; i++)
                            {
                                if (r - i * y > 0 && r - i * y < row &&
                                        col - i * x > 0 && col - i * x < column &&
                                        state[r - i * y][col - i * x] == -1) // AI����
                                {
                                    botNum++;
                                }
                                else if (r - i * y > 0 && r - i * y < row &&
                                         col - i * x > 0 && col - i * x < column &&
                                         state[r - i * y][col - i * x] == 0) // �հ�λ
                                {
                                    emptyNum++;
                                    break;
                                }
                                else            // ���߽�
                                    break;
                            }

                            if (botNum == 0)                      // ��ͨ����
                                goodadress[r][col] += 5;
                            else if (botNum == 1)                 // ���
                                goodadress[r][col] += 10;
                            else if (botNum == 2)
                            {
                                if (emptyNum == 1)                // ����
                                    goodadress[r][col] += 25;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 50;  // ����
                            }
                            else if (botNum == 3)
                            {
                                if (emptyNum == 1)                // ����
                                    goodadress[r][col] += 55;
                                else if (emptyNum == 2)
                                    goodadress[r][col] += 100; // ����
                            }
                            else if (botNum >= 4)
                                goodadress[r][col] += 10000;   // ����

                        }
                    }

            }
        }
    }


// ���������ҳ���������λ��

    for ( r=0; r<row; r++)
    {

        for ( col=0; col<column; col++)
        {
            // ǰ������������ǿյ�
            if (state[r][col] == 0)
            {
                if (goodadress[r][col]>=maxscore)          // ��������������
                {

                    maxscore = goodadress[r][col];

                    x=r;
                    y=col;
                    // mp=mp+1;

                }

            }
        }

    }
    // ������ӣ�����ж����Ļ�
    // srand((unsigned)time(0));
    //  int last=rand()%mp;

    state[x][y]=2;

}
