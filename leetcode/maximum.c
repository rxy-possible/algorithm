#include <stdio.h>
//方法一：暴力法
int maxSubArray(int* nums, int numsize)
{
	int max=nums[0];
	//选择一个起点
	for (int i = 0; i < numsize; i++)
	{
		//选择一个终点
		for (int j = i; j < numsize; j++)
		{
			int sum = 0;
			//计算从七点到终点的数值和
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

//方法二：

int main()
{
	int a[10] = { -1,-2,-3,-4,5,6,-4,5,10,9 };
	int sum = maxSubArray(a, 10);
	printf("%d\n", sum);
	return 0;

}