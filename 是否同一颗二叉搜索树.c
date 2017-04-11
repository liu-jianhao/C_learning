/*	给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。
例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，
你需要判断它们是否能生成一样的二叉搜索树。
	
输入格式:
		输入包含若干组测试数据。每组数据的第1行给出两个正整数NN (\le 10≤10)和LL，分别是每个序列插入元素的个数和需要
	检查的序列个数。第2行给出NN个以空格分隔的正整数，作为初始插入序列。最后LL行，每行给出NN个插入的元素，属于LL个需要检查的序列。
	简单起见，我们保证每个插入序列都是1到NN的一个排列。当读到NN为0时，标志输入结束，这组数据不要处理。
	
输出格式:
	对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
输入样例:
	4 2
	3 1 4 2
	3 4 1 2
	3 2 4 1
	2 1
	2 1
	1 2
	0
输出样例:
	Yes
	No
	No 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* Tree;
struct TreeNode
{
	int v;
	Tree Left, Right;
	int flag;			//记录是否经过这个节点，在判断函数中使用 
};

Tree NewNode(int V);
Tree insert(Tree T, int V);
Tree MakeTree(int N);
int check(Tree T, int V);
int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);

int main()
{
	int N, L, i;
	Tree T;
	
	scanf("%d",&N);	
	while(N)
	{
		scanf("%d", &L);
		T = MakeTree(N);
		for(i = 0; i < L; i ++)
		{
			if(Judge(T, N))
				printf("Yes\n");
			else
				printf("No\n");
			ResetT(T);
		}
		FreeTree(T);
		scanf("%d",&N);
	}
	return 0;
} 

//创建一个新节点 
Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0; 
}

//插入 
Tree insert(Tree T, int V)
{
	if(!T)
		T = NewNode(V);
	else
	{
		if(V > T->v)
			T->Right = insert(T->Right, V);
		else
			T->Left = insert(T->Left, V);	
	}
	return T;
}

//建二叉搜索树 
Tree MakeTree(int N)
{
	Tree T;
	int i, V;
	scanf("%d",&V);
	T = NewNode(V);
	
	for(i = 1; i < N; i ++)
	{
		scanf("%d",&V);
		T = insert(T,V);
	} 
	return T;
}



//用类似查找的方式看每个节点经过的路径是否一致，作为判定的标准
int check(Tree T, int V)
{	
	if(T->flag)
	{
		if(V < T->v)
			return check(T->Left, V);
		else if(V > T->v)
			return check(T->Right, V);
		else 
			return 0;			//重复节点，也就相当于不等 
	} else
	{
		if(V == T->v)
		{
			T->flag = 1;
			return 1;
		} else
			return 0;
	}
} 
//输入并判断序列是否一致 
int Judge(Tree T, int N)
{
	int i, V, flag = 0;   		//flag等于零表示暂时不一致，等于一表示已经不一致 
	
	scanf("%d", &V);
	if(V != T->v)				//判断根节点 
		flag = 1;
	else
		T->flag = 1; 
	
	for(i = 1; i < N; i ++)
	{
		scanf("%d",&V);
		if((!flag) && (!check(T, V)))
			flag = 1;
	}
	if(flag)
		return 0;
	else
		return 1;
} 
//重置Flag的值 
void ResetT(Tree T)
{
	if(T->Left)
		ResetT(T->Left);
	if(T->Right)
		ResetT(T->Right);
	T->flag = 0;
}
//释放空间 
void FreeTree(Tree T)
{
	if(T->Left)
		FreeTree(T->Left);
	if(T->Right)
		FreeTree(T->Right);
	free(T);
} 





