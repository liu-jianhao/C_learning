#include<stdio.h>
#include<stdlib.h>

void Merge(int A[], int tmp[], int L, int R, int REND);
void MSort(int A[], int tmp[], int L, int REND);
void Mergesort(int A[], int N);

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
	
	Mergesort(A, N);
	
	for(i = 0; i < N; i ++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}

void MSort(int A[], int tmp[], int L, int REND)
{
	int center;
	
	if(L < REND)
	{
		center = (L + REND) / 2;
		MSort(A, tmp, L, center);
		MSort(A, tmp, center + 1, REND);
		Merge(A, tmp, L, center + 1, REND);
	}
}

void Mergesort(int A[], int N)
{
	int *tmp;
	tmp = malloc(N * sizeof(int));
	if(tmp != NULL)
	{
		MSort(A, tmp, 0, N - 1);
		free(tmp);
	}
}

void Merge(int A[], int tmp[], int L, int R, int REND)
{
	int i, leftend, num, tmppos;
	
	leftend = R - 1;
	tmppos = L;
	num = REND + 1;
	
	while(L <= leftend && R <= REND)
	{
		if(A[L] <= A[R])
			tmp[tmppos++] = A[L++];
		else
			tmp[tmppos++] = A[R++];
	}
	
	while(L <= leftend)
		tmp[tmppos++] = A[L++];
	while(R <= REND)
		tmp[tmppos++] = A[R++];
		
		
	for(i = 0; i < num; i++, REND--)
	{
		A[REND] = tmp[REND];
	}
}
