/*�����������������ݡ�
ÿ�������һ��������������N��M��0 < N <= 30000,0 < M < 5000��,
  �ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
ѧ��ID��Ŵ�1�ൽN��
�ڶ��а���N��������������N��ѧ��  
  �ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�
��������M�У�ÿһ����һ���ַ�C��ֻȡ��Q����U������
  ������������A,B,��CΪ'Q'��ʱ��, ��ʾ����һ��ѯ�ʲ�������ѯ��ID��A��B������A,B����ѧ�����У�
  �ɼ���ߵ��Ƕ���
��CΪ��U����ʱ�򣬱�ʾ����һ�����²�����Ҫ���IDΪA��ѧ���ĳɼ�����ΪB��*/
#include<stdio.h>

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	int grades[N+1];
	int i;
	for(i = 1; i < N+1; i ++)		//��ʼ��ѧ���ɼ� 
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
			for(i = a + 1; i < b+1; i ++)		//�ҳ����ֵ 
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





