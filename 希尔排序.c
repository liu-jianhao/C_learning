#include<stdio.h>

void shellsort(int A[], int N);



int main()
{
	int N, i;
	printf("please input the num of the numbers:\n");
	scanf("%d", &N);
	int A[N];
	
	for(i = 0; i < N; i ++)
	{
		scanf("%d", &A[i]);
	}
	
	shellsort( A, N );
	
	for(i = 0; i < N; i ++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}

void shellsort(int A[], int N)
{
	int i, tmp, P, D;
	for(D = N / 2; D > 0; D /= 2)
	{
		for(P = D; P < N; P++)
		{
			tmp = A[P];
			for(i = P; i >= D && A[i - D] > tmp; i -= D)
			{
				A[i] = A[i - D];
			}
			A[i] = tmp;
		}
	}
}
