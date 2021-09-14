#include <stdio.h>

int singlenumber(int* nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++)
	{
		int count = 0;
		for (int j = 0; j < numsSize; j++)
		{
			if (*(nums+i) == *(nums+j))
			{
				count++;
			 }
		}
		if (count == 1)
		{
			return nums[i];
		}
	}
	return -1;
}

int main()
{
	int a[5] = { 10,1,1,2,2 };
	int b = singlenumber(a, sizeof(a)/sizeof(a[0]));
	printf("%d\n", b);
	return 0;
}