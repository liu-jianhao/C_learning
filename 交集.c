#include<stdio.h>
#include<stdlib.h>

typedef struct linked *lklist;     //定义链表 
struct linked
{
	int key;
	int *link;
};

Readlist()
{
	lklist lk,rear,t;
	lk = (lklist)malloc(sizeof(struct linked));
	
	lk->link = NULL;
	rear = lk;
	
	int num,k;
	printf("Please input the number of the linked list:\n");
	scanf("%d",&num);
	printf("Now input the numbers:\n");
	while(num--)
	{
		scanf("%d",&k);
		Attach(k,&rear);
	}
	
	t = lk;
	lk = lk->link;
	free(t);
		
	return lk;
	
}

Compare(lklist l1,lklist l2)
{
	while(l1 && l2){
		if(l1->key < l2->key )
		{
			l1 = l1->link;
		} else if (l1->key > l2->key)
		{
			l2 = l2->link;
		} else
		{
			printf("%d\t",l1->key);
			l1 = l1->link;
			l2 = l2->link;
		}
	}
}

Attach(int k, lklist *pRear)
{
	lklist l;
	l = (lklist)malloc(sizeof(struct linked));
	l->key  = k;
	l->link  = NULL;
	(*pRear)->link = l;
	*pRear = l;	
}


int main(void)
{
	lklist lk1,lk2;
	lk1 = Readlist();
	lk2 = Readlist();
	Compare(lk1,lk2);
	return 0;
}
