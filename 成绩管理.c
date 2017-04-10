/*输入包括多组测试数据。
每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,
  分别代表学生的数目和操作的数目。
学生ID编号从1编到N。
第二行包含N个整数，代表这N个学生  
  的初始成绩，其中第i个数代表ID为i的学生的成绩
接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），
  和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，
  成绩最高的是多少
当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。*/
#include<stdio.h>

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	int grades[N+1];
	int i;
	for(i = 1; i < N+1; i ++)		//初始化学生成绩 
	{
		scanf("%d",&grades[i]);
	}
	
	char ch;
	int a, b;
	while(M)
	{
		int a, b;
		scanf("%c%d%d",&ch, &a, &b);
		if(ch == 'Q')
		{
			grades[0] = grades[a];
			for(i = a + 1; i < b+1; i ++)		//找出最大值 
			{
				if(grades[0]<grades[i])
				{
					grades[0] = grades[i];
				}
			}
			printf("%d\n",grades[0]);
			M --;
		} else if(ch == 'U')
		{
			grades[a] = b;		
			M --;
		}
	}
	return 0;
} 





