#include <stdio.h>
#define bool char
#define true 1
#define false 0

int next_n(int n)       //ÿλƽ���͵���һλ��
{
	int r = 0;
	while (n != 0)
	{
		int d = n % 10;
		n /= 10;
		r += d * d;
	}
	return r;
}

bool contains(int* history, int size, int n) //�ж���������Ƿ��������ֹ�
{
	for (int i = 0; i < size; i++)
	{
		if (history[i] == n)
		{
			return true;
		}
	}
	return false;
}

bool isHappy(int n)                //���յĽ��
{
	

	int history[10000];
	int size = 0;

	while (!contains(history, size, n))
	{
		printf("%d\n", next_n(n));
		history[size] = n;
		size++;
		n = next_n(n);
	}
	

	return false;
}

bool isHappy1(int n)         //�ڶ��ַ���ʡȥ������ռ�history
{
	int slow = n;
	int fast = n;
	do{
	slow = next_n(slow);
	fast = next_n(fast);
	fast = next_n(fast);
	} while (slow != fast);
	return fast == 1;
}

int main()
{
	bool a = isHappy(20);
	return 0;
}