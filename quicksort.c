#include<stdio.h>
#include<stdlib.h>

int median3(int A[], int Left, int Right);
void swap(int *a, int *b);
void Quicksort(int A[], int Left, int Right);

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
	
	Quicksort(A, 0, N - 1);
	
	for(i = 0; i < N; i ++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}

int median3(int A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if(A[Left] > A[Center])
		swap(&A[Left], &A[Center]); 
	if(A[Left] > A[Right])
		swap(&A[Left], &A[Right]);
	if(A[Center] > A[Right])
		swap(&A[Center], &A[Right]);
		
	swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Quicksort(int A[], int Left, int Right)
{
	int i, j;
	int pivot = median3(A, Left, Right);
	i = Left;
	j = Right - 1;
	for(;;)
	{
		while(A[++i] > pivot) {}
		while(A[--j] < pivot) {}
		if(i < j)
			swap(&A[i], &A[j]);
		else break;
	}
	swap(&A[i], &A[Right - 1]);
	Quicksort(A, Left, i - 1);
	Quicksort(A, i + 1, Right);
}
