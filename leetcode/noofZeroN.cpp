#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
     //

    /*
    n里面的数字可以被5除，有几个5，就有几个0
    被25除，有几个25就在加几个0
        被5^ x除, 有几个5^ x在加上几个0
     */
    long long trailingZeros(long long n) {
        // write your code here
        long long num = n;
        int step = 0;
        while (num != 0)
        {
            num = num / 5;
            step++;
        }
        long long n1 = 0;
        long long j = 5;
        for (int i = 0; i < step - 1; i++)
        {
            n1 += n / j;
            j = j * 5;
        }
        return n1;
    }
};

int main()
{
    Solution solution;
    long long n = 10;
    int no = solution.trailingZeros(n);
    cout << no << endl;
    return 0;
}