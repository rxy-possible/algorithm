//����һ�������� source �ַ�����һ�� target �ַ�������Ӧ���� source �ַ������ҳ� target �ַ������ֵĵ�һ��λ��(��0��ʼ)����������ڣ��򷵻� -1��

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param source:
     * @param target:
     * @return: return the index
     */
    int strStr(string& source, string& target) {
        // Write your code here
        size_t n;
        n = source.find(target);
        if (n == string::npos)
            return -1;
        return n;
    }
};

int main()
{
    string a = "qwer";
    string b = "er";
    Solution solution;
    int n = solution.strStr(a, b);
    cout << "n:" << n << endl;
    return 0;
}
