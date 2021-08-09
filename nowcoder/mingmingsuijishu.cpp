#include<iostream>
#include<set>
using namespace std;
int main()
{
    int N,n;
    set<int> ss;
    while(cin>>N)     //多组数据
    {
        ss.clear();   //清除上一组数据的影响
     while(N--)
     {
         cin>>n;
         ss.insert(n);
     }
     for (set<int>::iterator it = ss.begin(); it != ss.end(); it++)
     {
            cout << *it << endl;
     }     
    }
    return 0;
}