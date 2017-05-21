/*给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

输入格式:
	输入首先给出正整数N，为通话记录条数。随后N行，每行给出一条
通话记录。简单起见，这里只列出拨出方和接收方的11位数字构成
的手机号码，其中以空格分隔。

输出格式:
	在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。
如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并
且附加给出并列狂人的人数。

输入样例:
4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832

输出样例:
13588625832 3
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef char ElementType[12];

typedef struct LNode *PtrToLNode;
struct LNode{
	ElementType data;
	PtrToLNode next;
	int count;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TablNode *HashTable;
struct TablNode{
	int TableSize;
	List Heads;
};

HashTable InitializeTable(int TableSize);
void ScanAndOutput(HashTable H);
Position Find(char *key, HashTable H);
int NextPrime(int n);
int Hash(int key, int p);
int Insert(HashTable H, char *key);
void DestoryTable(HashTable H);

int main()
{
	int N, i;
	ElementType key;
	scanf("%d", &N);
	
	HashTable H;
	H = InitializeTable(2*N);
	
	for(i = 0 ; i < N; i++)
	{
		scanf("%s", &key);
		Insert(H, key);
		scanf("%s", &key);
		Insert(H, key);
	}
	
	ScanAndOutput(H);
	DestoryTable(H);
	
	return 0;
} 

int Hash(int key, int p)
{
	return key%p;
} 

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	
	H = (HashTable)malloc(sizeof(struct LNode));
	
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
	for(i = 0; i < H->TableSize; i ++)
	{
		H->Heads[i].data[0] = '\0';
		H->Heads[i].next = NULL;
		H->Heads[i].count = 0;
	}
	return H;
}

int NextPrime(int n)
{
	int i;
	while(1)
	{
		n++;
		for(i = 2; i < n; i ++)
		{
			if(n%i == 0)
				break;
			else 
				return n;
		}
	}
}

Position Find(char *key, HashTable H)
{
	Position P;
	int pos;
	
	pos = Hash(atoi(key+11-5), H->TableSize);
	P = H->Heads[pos].next;
	
	while(P && strcmp(P->data, key))
		P = P->next;
	return P;
}

int Insert(HashTable H, char *key)
{
	Position P,NewCell;
	int pos;
	
	P = Find(key, H);
	if(!P)
	{
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->data, key);
		NewCell->count = 1;
		pos = Hash(atoi(key+11-5), H->TableSize);
		
		NewCell->next = H->Heads[pos].next;
		H->Heads[pos].next = NewCell;
		return 1;
	}
	else
	{
		P->count ++;
		return 0;
	}
}

void ScanAndOutput(HashTable H)
{
	int i, MaxCnt = 0, PCnt = 0;
	List ptr;
	ElementType MinPhone;
	MinPhone[0] = '\0';
	
	for(i = 0; i < H->TableSize; i ++)
	{
		ptr = H->Heads[i].next;
		while(ptr)
		{
			if(ptr->count > MaxCnt)
			{
				MaxCnt = ptr->count;
				strcpy(MinPhone, ptr->data);
				PCnt = 1;
			}
			else if(ptr->count == MaxCnt)
			{
				PCnt ++;
				if(strcmp(MinPhone, ptr->data) > 0)
					strcpy(MinPhone, ptr->data);
			}
			ptr = ptr->next;
		}
	}
	printf("%s %d", MinPhone, MaxCnt);
	if(PCnt > 1)
		printf(" %d", PCnt);
	printf("\n");
}

void DestoryTable(HashTable H)
{
	free(H);
}
