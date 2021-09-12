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
    n��������ֿ��Ա�5�����м���5�����м���0
    ��25�����м���25���ڼӼ���0
        ��5^ x��, �м���5^ x�ڼ��ϼ���0
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