/*
    question is http://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized
    O(NlogN)
*/

#include <bits/stdc++.h>

using namespace std;

bool valid(int *arr,int dis,int K,int N)
{
    if(K > N)
        return 0;
    if(dis == 0)
        if(K <= N)
            return 1;
        else
            return 0;

    int cnt = 1;
    int i = 0;
    while(i < N && cnt < K)
    {
        i = lower_bound(arr+i+1,arr+N,arr[i] + dis) - arr;
        if(i < N)
            cnt++;
    }
    if(cnt == K)
        return 1;
    else
        return 0;
}

int func(int *arr,int K,int N)
{
    if(N == 0)
        return -1;
    sort(arr,arr+N);
    int lo = 0,hi = arr[N-1]-arr[0];
    while(lo < hi)
    {
        int mid = (lo+hi)/2;
        if(valid(arr,mid,K,N))
        {
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return hi;
}

int main()
{
    int arr[] = {1, 2, 7, 5, 11, 12};
    int k = 3;
    int N = sizeof(arr)/sizeof(arr[0]);

    cout << func(arr,k,N) << '\n';

    return 0;
}