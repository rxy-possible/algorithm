#include <stdio.h>
//����һ��������
int maxSubArray(int* nums, int numsize)
{
	int max=nums[0];
	//ѡ��һ�����
	for (int i = 0; i < numsize; i++)
	{
		//ѡ��һ���յ�
		for (int j = i; j < numsize; j++)
		{
			int sum = 0;
			//������ߵ㵽�յ����ֵ��
			for (int k = i; k <= j; k++)
			{
				sum += nums[k];
			}
			if (sum > max)
			{
				max = sum;
			}
			printf("%d %d : %2d (%d)\n", i, j, sum, max);
		}
		
	}
	return max;
	
}

//��������

int main()
{
	int a[10] = { -1,-2,-3,-4,5,6,-4,5,10,9 };
	int sum = maxSubArray(a, 10);
	printf("%d\n", sum);
	return 0;

}