/*
	The task of this problem is simple: insert a sequence of distinct positive integers 
into a hash table, and output the positions of the input numbers. The hash function 
is defined to be H(key) = key \% TSizeH(key)=key%TSize where TSizeTSize is the 
maximum size of the hash table. Quadratic probing (with positive increments only) 
is used to solve the collisions.
Note that the table size is better to be prime. If the maximum size given by the 
user is not prime, you must re-define the table size to be the smallest prime number 
which is larger than the size given by the user.

Input Specification:
	Each input file contains one test case. For each case, the first line contains two 
positive numbers: MSizeMSize  and Nwhich are the user-defined table size and the number 
of input numbers, respectively. Then NN distinct positive integers are given in the 
next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the
input numbers in one line. All the numbers in a line are separated by a space, and
there must be no extra space at the end of the line. In case it is impossible to 
insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15

Sample Output:
0 1 4 -

*/ 
#include<stdio.h>
#include<stdlib.h>

typedef int HashTable;

int NextPrime(int n);
int Insert(int key, int H[], int TableSize);
int Find(int H[], int TableSize, int Key );
int Hash(int key, int TableSize);

int main()
{
	int M, N, TableSize, i, key, p;				//M是TableSize， N是数字个数 
	scanf("%d %d", &M, &N);
	
	TableSize = NextPrime(M);
	
	HashTable H[TableSize];	
	
	for(i = 0; i < TableSize; i ++)
	{
		H[i] = 0;
	}
	
	for(i = 0; i < N; i ++)
	{
		scanf("%d", &key);
		p = Insert(key, H, TableSize);
		if(p == -1)
		{
			printf("- ");
		}
		else
		{
			printf("%d ", p);
		}
	}
	
	return 0;
}

int NextPrime(int n)
{
	int i;
	while(1)
	{
		for(i = 2; i < n; i ++)
		{
			if(n % i == 0)
				break;
			else 
				return n;
		}
		n++; 
	}
}

int Insert(int key, int H[], int TableSize)
{
	int p;
	p = Find(H, TableSize, key);
	if(p >= 0 && p < TableSize)
	{
		H[p] = key;
		return p;
	}
	else
	{
		return -1;
	}
}


int Find(int H[], int TableSize, int key )
{
    int CurrentPos, NewPos;
    int count = 0;
    int CNum = 0; /* 记录冲突次数 */
 
    NewPos = CurrentPos = Hash( key, TableSize ); /* 初始散列位置 */
    /* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
    while( H[NewPos] != 0 && H[NewPos] != key ) {
        /* 统计1次冲突，并判断奇偶次 */
        if( ++CNum%2 ){ /* 奇数次冲突 */
            NewPos = CurrentPos + (CNum+1)*(CNum+1)/4; /* 增量为+[(CNum+1)/2]^2 */
            if ( NewPos >= TableSize )
                NewPos = NewPos % TableSize; /* 调整为合法地址 */
        }
        else { /* 偶数次冲突 */
            NewPos = CurrentPos - CNum*CNum/4; /* 增量为-(CNum/2)^2 */
            while( NewPos < 0 )
                NewPos += TableSize; /* 调整为合法地址 */
        }
        count++;
        if(count > 10)
        {
        	NewPos = -1;
        	break;
        }
    }
    return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}

int Hash(int key, int TableSize)
{
	return (key % TableSize);
}
