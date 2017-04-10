#include<stdio.h>
struct Node
{
	int root; 
	int left;
	int right;	
};

int main()
{
	int N;
	scanf("%d",&N); 
	struct Node node[N];
	
	int i;
	for(i = 0; i < N; i ++)		//初始化节点 
	{
		node[i].root = 1;		//作为判断是否为空节点的标志 
		node[i].left = -1;
		node[i].right = -1;	
	}
	
	char ch1, ch2;
	for(i = 0; i < N; i ++)   	//建树 
	{
		scanf("\n%c %c", &ch1, &ch2);
		if(ch1 != '-')
		{
			node[i].left = ch1 - '0';
			node[ch1 - '0'].root = 0;
		}
		
		if(ch2 != '-')
		{
			node[i].right = ch2 - '0';
			node[ch2 - '0'].root = 0;
		}
	}
	
	int root;
	for(i = 0; i < N; i ++)
	{
		if(node[i].root == 1)
			root = i;
	} 
		
	//用层序遍历来输出从上至下输出叶节点	队列实现 
	int queue[N];
	int front = 0, rear = 0; 
	queue[rear++] = root;		//根节点入队 
	while(rear - front)
	{
		int first = queue[front++];		//队首节点出队
		if(node[first].left == -1 && node[first].right == -1)		//叶节点输出 
		{
			printf("%d ",first);
		} 
		if(node[first].left != -1)		//存在左节点 
		{
			queue[rear++] = node[first].left; 
		}
		if(node[first].right != -1)		//存在右节点
		{
			queue[rear++] = node[first].right;
		} 
	}
	return 0;
}






