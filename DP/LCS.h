#include <string>
#include <string.h>
using namespace std;

int LCS_arr[10001][1001];

/*
    LCS(M,N) = 1 + LCS(M-1,N-1) or max(LCS(M-1,N),LCS(M,N-1))
    if that is the case then we are starting from right as we are always keeping element equal at right most
*/

int longest_common_subsequence(string s1,string s2)
{
    if(s1.length() > 1000 || s2.length() > 1000)
    {
        return 0;
    }
    memset(LCS_arr,-1,sizeof(LCS_arr));
    for(int i = 0;i < 1001;++i)
    {
        LCS_arr[i][0] = 0;
        LCS_arr[0][i] = 0;
    }
    for(int i = 1;i <= s1.length();++i)
    {
        for(int j = 1;j <= s2.length();++j)
        {
            if(s1[i-1] == s2[j-1])
                LCS_arr[i][j] = LCS_arr[i-1][j-1]+1;    
            else 
                LCS_arr[i][j] = max(LCS_arr[i][j-1],LCS_arr[i-1][j]);
        }
    }
    return LCS_arr[s1.length()][s2.length()];
}

int longest_common_substring(string A,string B)
{
    
}