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
	for(i = 0; i < N; i ++)		//��ʼ���ڵ� 
	{
		node[i].root = 1;		//��Ϊ�ж��Ƿ�Ϊ�սڵ�ı�־ 
		node[i].left = -1;
		node[i].right = -1;	
	}
	
	char ch1, ch2;
	for(i = 0; i < N; i ++)   	//���� 
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
		
	//�ò����������������������Ҷ�ڵ�	����ʵ�� 
	int queue[N];
	int front = 0, rear = 0; 
	queue[rear++] = root;		//���ڵ���� 
	while(rear - front)
	{
		int first = queue[front++];		//���׽ڵ����
		if(node[first].left == -1 && node[first].right == -1)		//Ҷ�ڵ���� 
		{
			printf("%d ",first);
		} 
		if(node[first].left != -1)		//������ڵ� 
		{
			queue[rear++] = node[first].left; 
		}
		if(node[first].right != -1)		//�����ҽڵ�
		{
			queue[rear++] = node[first].right;
		} 
	}
	return 0;
}






