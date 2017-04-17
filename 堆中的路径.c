/*
 *将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。
 
 	输入样例:
5 3
46 23 26 24 10
5 4 3
	输出样例:
24 23 10
46 23 10
26 10
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 1001
#define MIN -1001

int H[MAX],size;

void CreatHeap();
void Insert(int x);

int main(void)
{
	int N, M, i, n;
	CreatHeap();
	scanf("%d %d",&N, &M);
	for(i = 1; i <= N; i ++){
		scanf("%d", &n);
		Insert(n);
	}
	
	int find;
	for(i = 0; i < M; i ++){
		scanf("%d", &find);
		
		while(find > 0){
			printf("%d ",H[find]);
			find /= 2;
		}
		printf("\n");
	}
	return 0;
} 

void CreatHeap(){
	size = 0;
	H[0] = MIN;
}

void Insert(int x){
	int i;
	for(i = ++size; H[i/2] > x; i /= 2 ){	//这样不用交换，更好 
		H[i] = H[i/2];
	}
	H[i] = x;
}
