#include <string>
#include <cstring>
// #include 
using namespace std;
/*
    Though Z-algorithm can be used in many more places it is here implemented for 
    string searching.
*/

bool find(string text,string pattern)
{
    string var = pattern + "#" + text;
    int *Z = new int[var.length()];
    memset(Z,0,sizeof(Z)*var.length());
    // for(int i = 0;i < var.length();++i)
    // {
    //     Z[i] = 0;
    // }
    int L = 0,R = 0;
    for(int i = 1;i < var.length();++i)
    {
        if(L == 0 && R == 0)
        {
            Z[i] = 0;
            L = R = i;
            while(R < var.length() && var[R] == var[R-L])
            {
                R++;
            }
            Z[i] = R-L;R--;//due to wrong increment
        }else{
            int k = i-L;
            if(Z[k] < (R-i+1))
            {
                Z[i] = R-i+1;
                continue;
            }else{
                L = R = i;
                while(R < var.length() && var[R] == var[R-L])
                {
                    R++;
                }
                Z[i] = R-L;R--;
            }
        }
    }

    for(int i = 1;i < var.length();++i)
    {
        if(Z[i] == pattern.length())
            return true;
    }
    return false;
}