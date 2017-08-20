/*
    original problem : http://www.geeksforgeeks.org/collect-coins-minimum-number-steps/
*/

#include <bits/stdc++.h>

using namespace std;

int minStepsHelper(int*arr,int l,int r,int ht)
{
    if(l >= r)
        return 0;
    int m = l;
    for(int i = l+1;i < r;++i)
    {
        if(arr[m] > arr[i])
        {
            m = i;
        }
    }
    return min(r-l,
                minStepsHelper(arr,l,m,arr[m])+minStepsHelper(arr,m+1,r,arr[m]) + arr[m]-ht
        );
}

int minSteps(int *arr,int N)
{
    return minStepsHelper(arr,0,N,0);
}

int main()
{
    int height[] = {2, 1, 2, 5, 1};
    int N = sizeof(height) / sizeof(int);
 
    cout << minSteps(height, N) << endl;

    return 0;
}