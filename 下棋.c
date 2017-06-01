#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print();
void player();
void computer();
void check();

#define N 4			// 棋盘大小 

/* 棋盘 */ 
char data[N][N];

int main(int argc, char* argv[])
{
	int i, j;
	/* 初始化棋盘 */ 
	for(i = 1; i < N; i ++)
	{	
		for(j = 1; j < N; j ++)
		{
			data[i][j] = '-';
		}
	}
	print();		 
	while(1)
	{
		player();		// 玩家下棋 
		computer();		// 电脑下棋 
	}
	return 0;
}

/* 打印棋盘 */
void print()
{
	system("cls");			// 清屏函数 
	int i, j;
	for(i = 0; i < N; i ++)
	{	
		for(j = 0; j < N; j ++)
		{
			if(i == 0)
			{
				printf("%d ", j);
			}
			else if(j == 0)
			{
				printf("%d ", i);
			}
			else
			{
				printf("%c ", data[i][j]);
			}
		}
		printf("\n");
	}
}

/*  轮到玩家下棋 */ 
void player()
{
	printf("Please input the position of your piece(such as 2 1):\n");
	int x , y;
	scanf("%d %d", &x, &y);
	/* 判断位置是否是空的 */ 
	if(data[x][y] != '-')
	{
		printf("Error! The place is being used\n");
		player();
	}else
	{
		data[x][y] = 'X';
	}
	print(); 			// 下完棋后要重新打印棋盘 
	check();			// 每下一个棋子就要判断游戏是否已经结束了 
}

/* 轮到电脑下棋 */ 
void computer()
{
	int x, y;
	do
	{
		srand((unsigned)time( NULL ));		// 随机数种子 
		/* 随机产生电脑下棋的位置 */
		x = rand()%3+1;						
		y = rand()%3+1;		
	} while(data[x][y] != '-');				// 直到位置为空 
	
	data[x][y] = 'O';		// 下子 

	print();				// 重新打印棋盘 
	check();				// 检查判断 
}

/*  检查棋盘是否已经决出胜负 */
void check()
{
	int i, j, count;
	/*  判断对角线 */ 
	if(data[1][1] == data[2][2] && data[2][2] == data[3][3] && data[1][1] == 'X')
	{
		printf("You win!");
		exit(0);
	}
	else if(data[1][1] == data[2][2] && data[2][2] == data[3][3] && data[1][1] == 'O')
	{
		printf("Computer win!");
		exit(0);
	}
	else if(data[3][1] == data[2][2] && data[1][3] == data[2][2] && data[2][2] == 'X')
	{
		printf("You win!");
		exit(0);
	}
	else if(data[3][1] == data[2][2] && data[1][3] == data[2][2] && data[2][2] == 'O')
	{
		printf("Computer win!");
		exit(0);
	}
	/*  判断横轴和纵轴 */ 
	for(i = 1; i < N; i ++)
	{
		if(data[i][1] == data[i][2] && data[i][3] == data[i][2] && data[i][1] == 'X')
		{
			printf("You win!");
			exit(0);
		}
		else if(data[i][1] == data[i][2] && data[i][3] == data[i][2] && data[i][1] == 'O')
		{
			printf("Computer win!");
			exit(0);
		}
		else if(data[1][i] == data[2][i] && data[3][i] == data[2][i] && data[1][i] == 'X')
		{
			printf("You win!");	
			exit(0);
		}
		else if(data[1][i] == data[2][i] && data[3][i] == data[2][i] && data[1][i] == 'O')
		{
			printf("Computer win!");
			exit(0);
		}
	}
	/*  判断棋盘是否满了， 即平局 */ 
	for(i = 1; i < N; i ++)
	{
		for(j = 1; j < N; j ++)
		{
			if(data[i][j] != '-')
			{
				count++;			// 记录棋盘的棋子数 
			}
		}
	}
	if(count == 9)
	{
		printf("Draw!");
		exit(0);
	}
}
