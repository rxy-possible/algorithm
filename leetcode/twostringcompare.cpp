//对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。如果不存在，则返回 -1。

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
