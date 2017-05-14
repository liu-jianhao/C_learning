#include<stdio.h>

#define N 100

int main()
{
	int num, i = 0;
	char n[N];
	printf("input a number:\n");
	scanf("%d", &num);
	
	while((num/10) > 0)
	{
		n[i++] = (char)((num%10)+'0');
		num /= 10;
	}
	n[i] =(char)(num+'0');
	n[i+1] = '\0';
	
	printf("%s", n);
	
	return 0;
} 
