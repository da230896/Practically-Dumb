#include <vector>
#include <string.h>

using namespace std;

int strStr(const string &haystack, const string &needle) {
    int n = needle.length();
    vector<int> failure(n,0);
    for(int i = 1;i < n;++i)
    {
        if(needle[i] == needle[failure[i-1]])
        {
            failure[i] = failure[i-1]+1;
        }else{
            int x = failure[i-1];
            while(x > 0)
            {
                if(needle[i] == needle[x])
                {
                    break;
                }else{
                    x = failure[x-1];
                }
            }
            if(needle[i] == needle[x])
                failure[i] = x+1;
            else
                failure[i] = 0;
        }
    }
    int j = 0;
    int m = haystack.length();
    for(int i = 0;i <= (m-n);)
    {
        while(i < m && j < n && haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        if(j == n)
            return i-n+1;
        else{
            if(j > 0)
            {
                j = failure[j-1];
            }else{
                i++;
            }
        }
    }
    return -1;
}
