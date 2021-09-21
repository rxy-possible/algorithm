#include <stdio.h>

int func(int ii,int total)
{
	if(ii>100)
	{
		return total;
	}
	total = total+ii;
	return func(ii+1,total);
}

int main()
{
	printf("total = %d\n",func(1,0));
	return 0;
}
