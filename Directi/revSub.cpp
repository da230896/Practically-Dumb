#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        int l_b=-1,r_a=-1;
        for(int i = 0;i < s.length();++i)
        {
            if(s[i] == 'b' && l_b == -1)
            {
                l_b = i;
            }
            if(s[s.length()-i-1] == 'a' && r_a == -1)
            {
                r_a = s.length()-i-1;
            }
        }
        if(l_b < r_a && l_a != -1 && r_a != -1)
        {
            cout << l_b << ' ' << r_a << '\n';
        }else{
            cout << "0 0\n";
        }
    }
    return 0;
}