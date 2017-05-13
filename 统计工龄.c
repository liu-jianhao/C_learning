#include<stdio.h>

#define NUM 50

int main()
{
	int i, N;
	scanf("%d", &N);
	int A[N];
	
	for(i = 0; i < N; i ++)
	{
		scanf("%d", &A[i]);
	}
	
	int count[NUM] = {0};
	for(i = 0; i < N; i ++)
	{
		count[A[i]]++;
	}
	
	for(i = 0; i < NUM; i ++)
	{
		if(count[i])
		{
			printf("%d:%d\n", i, count[i]);
		}
	}
	return 0;
} 
