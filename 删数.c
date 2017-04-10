/* 题目描述：
 * 输入一个数组的大小size，且初始化为0，1，2...size-1
 * 每个两个数删去一个数直到剩下最后一个数
 * 打印最后一个数
 */
 
#include<stdio.h>
int main(void)
{
	int size;
	printf("Please input the size:\n");
	scanf("%d",&size);
	int a[size];
	
	//初始化数组
	int i;
	for(i = 0; i < size; i++)
	{
		a[i] = i;
	} 
	
	//删除
	int count = 0, rest = size;
	while(rest != 1)
	{
		for(i = 0; i < size;)
		{
			
			if(count == 2 && a[i] != -1)  //删数 
			{
				a[i] = -1;
				rest--;
				count = 0;
				i++;
			} else if(a[i] == -1 )  //如果有删除标志则跳过不计数 
			{
				i++;
			} else                 
			{
				count ++;
				i++;
			}
		}
	}
	
	//打印剩下的最后一个数 
	for(i = 0; i < size; i++)
	{
		if(a[i] != -1)
		{
			printf("%d", a[i]);
			break;
		}
	}
	return 0;	
}



