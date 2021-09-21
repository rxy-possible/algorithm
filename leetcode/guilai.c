#include <stdio.h>
int func(int ii)
{
	if(ii >100)
		return 0;
	int total = ii + func(ii +1);
	printf("total = %d\n",total);
	return total;
}

int main()
{
	printf("total = %d\n",func(1));
}
