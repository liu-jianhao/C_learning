/*给定一个有NN个顶点和EE条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N-1N?1编号。
进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
	输入格式:
输入第1行给出2个整数N和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。
输出格式:
每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。
	输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
	输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/ 
#include<stdio.h>

#define MAX 10

void DFS(int i, int N);
void BFS(int i, int N);

int visit[MAX] = {0};		//用作是否访问过的标志 
int G[MAX][MAX] = {0};


int main(void)
{
	int N,E,i,x,y;
	scanf("%d%d",&N, &E);
	
	for(i = 0; i < E; i ++)
	{
		scanf("\n%d%d",&x, &y);
		G[x][y] = G[y][x] = 1;
	}
	
	for(i = 0; i < N; i ++)
	{
		if(!visit[i])
		{
			printf("{");
			DFS(i, N);
			printf(" }\n");
		}
	}
	
	for(i = 0; i < N; i ++)
	{
		visit[i] = 0;
	}
	
	for(i = 0; i < N; i ++)
	{
		if(!visit[i])
		{
			printf("{");
			BFS(i, N);
			printf(" }\n");
		}
	}
	return 0;
} 

void DFS(int i, int N)
{
	int j;
	visit[i] = 1;
	printf(" %d",i);
	for(j = 0; j < N; j ++)
	{
		if(!visit[j] && G[i][j] == 1)
			DFS(j, N);
	}
}

void BFS(int i, int N)
{
	int queue[MAX], rear, front, v, j;
	rear = front = -1;
	visit[i] = 1;
	queue[++rear] = i;
	while(rear > front)
	{
		v = queue[++front];
		printf(" %d", v);
		for(j = 0; j < N ; j ++)
		{
			if(!visit[j] && G[v][j])
			{
				visit[j] = 1;
				queue[++rear] = j;
			}
		}
	}
} 
