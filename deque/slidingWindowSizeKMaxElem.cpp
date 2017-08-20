#include <bits/stdc++.h>

using namespace std;

void printKMax(int *arr,int n,int k)
{
    deque<int> dq;
    int i = 0;
    for(;i < k;++i)
    {
        while((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for(;i < n;++i)
    {
        cout << arr[dq.front()] << ' ';
        //this pop will only from front side as new index is pushed_back 
        while((!dq.empty()) && dq.front() <= (i-k))
            dq.pop_front();

        while((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    cout << arr[dq.front()] << ' ';
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}