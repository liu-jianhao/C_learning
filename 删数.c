/* ��Ŀ������
 * ����һ������Ĵ�Сsize���ҳ�ʼ��Ϊ0��1��2...size-1
 * ÿ��������ɾȥһ����ֱ��ʣ�����һ����
 * ��ӡ���һ����
 */
 
#include<stdio.h>
int main(void)
{
	int size;
	printf("Please input the size:\n");
	scanf("%d",&size);
	int a[size];
	
	//��ʼ������
	int i;
	for(i = 0; i < size; i++)
	{
		a[i] = i;
	} 
	
	//ɾ��
	int count = 0, rest = size;
	while(rest != 1)
	{
		for(i = 0; i < size;)
		{
			
			if(count == 2 && a[i] != -1)  //ɾ�� 
			{
				a[i] = -1;
				rest--;
				count = 0;
				i++;
			} else if(a[i] == -1 )  //�����ɾ����־������������ 
			{
				i++;
			} else                 
			{
				count ++;
				i++;
			}
		}
	}
	
	//��ӡʣ�µ����һ���� 
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



