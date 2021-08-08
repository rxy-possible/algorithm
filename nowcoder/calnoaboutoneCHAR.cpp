#include <set>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count = 0;
    string s;
    getline(cin,s);
    char c =tolower(getchar());
    for(auto i : s)
    {
        if(tolower(i) == c)
            ++count;
    }
        
    cout << count <<endl;
    
}