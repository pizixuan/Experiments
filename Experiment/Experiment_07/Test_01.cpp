/*
    用栈求解迷宫问题中的应用。
    编写一个程序exp7-1.cpp，在教材3.1.4节中例子的基础上改进，
    要求输出图3.28所示的迷宫的所有路径，并求第一条最短路径长度及最短路径。
*/

#include <stdio.h>

#define M 4 //行数
#define N 4 //列数
#define MAXSIZE 100 //栈最多元素个数

// mg为迷宫二维数组:一个迷宫,其四周加上均为1的边框
int maze[M + 2][N + 2] = {{1, 1, 1, 1, 1, 1},
                          {1, 0, 0, 0, 1, 1},
                          {1, 0, 1, 0, 0, 1},
                          {1, 0, 0, 0, 1, 1},
                          {1, 1, 0, 0, 0, 1},
                          {1, 1, 1, 1, 1, 1}};

struct{
    int i; // 纵坐标
    int j; // 横坐标
    int di;
}simplePath[MAXSIZE], minPath[MAXSIZE];

int top = -1; //栈顶指针
int count = 1; //路径数计数
int minLen = MAXSIZE; //最短路径长度
/*--------------------------------------------------------*/
void dispPath()
{
    printf("  %5d: ", count++); // 输出第cnt条路径
    for(int k = 0; k <= top; k++)
        printf("(%d,%d)", simplePath[k].i, simplePath[k].j);
    printf("\n");
    if(top + 1 < minLen) //比较找最短路径
    {
        for(int k = 0; k <= top; k++) //将最短路径存放在path中
            minPath[k] = minPath[k];
        minLen = top + 1; // 将最短路径长度存放在minlen中
    }
}

void dispMinPath()
{
    printf("最短路径如下:\n");
    printf("长度: %d\n", minLen);
    printf("路径: ");
    for(int k = 0; k < minLen; k++)
        printf("(%d,%d)", minPath[k].i, minPath[k].j);
    printf("\n");
}

void findPath(){
    int i, j, di, line, col;
    top++;      //进栈
    simplePath[top].i = 1;
    simplePath[top].j = 1;
    simplePath[top].di = -1;
    maze[1][1] = -1;        //入口变为不可走
    while (top > -1){       //栈不为空时
        i = simplePath[top].i;
        j = simplePath[top].j;
        di = simplePath[top].di;        //读取位置和方向
        // printf("当前位置(%d,%d)", i, j);
        printf("当前坐标%d", maze[i][j]);
        while (di < 4){
            di++;
            switch (di)
            {
            case 0:
                line = i - 1;
                col = j;
                break;
            case 1:
                line = i;
                col = j + 1;
                break;
            case 2:
                line = i + 1;
                col = j;
                break;
            case 3:
                line = i;
                col = j - 1;
                break;
            }
            if (line == M && col == N){
                simplePath[top].di = di;
                top++;
                simplePath[top].i = line;
                simplePath[top].j = col;
                simplePath[top].di = -1;
                dispPath();        
                top--;
                break;
            }
            if (maze[line][col] == 0){
                simplePath[top].di = di;
                top++;
                simplePath[top].i = line;
                simplePath[top].j = col;
                simplePath[top].di = -1;
                i = line;
                j = col;
                di = -1;
                maze[i][j] = -1;
            }    
            if (di == 3 && maze[line][col] != 0){
                maze[i][j] = 0;
                top--;
                break;
            }
        }
    }
    dispMinPath();
}


int main()
{
    findPath();
    printf("提交！\n");
    return 0;
}