#include <string>
#include <string.h>

using namespace std;

int DP_arr[1001][1001];

int findDistance(string s1,string s2)
{
    if(s1.length() > 1000 || s2.length() > 1000)
    {
        return -1;
    }
    memset(DP_arr,1,sizeof(DP_arr));
    for(int i = 0;i < 1001;++i)
    {
        DP_arr[i][0] = i;
        DP_arr[0][i] = i;
    }

    for(int i = 1;i <= s1.length();++i)
    {
        for(int j = 1;j <= s2.length();++j)
        {
            if(s1[i-1] == s2[j-1])
                DP_arr[i][j] = min(DP_arr[i][j],DP[i-1][j-1]);
            else
                DP_arr[i][j] = min({DP_arr[i][j],DP_arr[i-1][j]+1,DP_arr[i][j-1]+1});
        }
    }
    return DP_arr[s1.length()][s2.length()];
}