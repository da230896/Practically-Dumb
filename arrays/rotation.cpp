#include <bits/stdc++.h>

using namespace std;

void swap_block(int *arr,int fi,int si,int d)
{
    for(int i = 0;i < d;++i)
    {
        int temp = arr[fi+i];
        arr[fi+i] = arr[si+i];
        arr[si+i] = temp;
    }
}

void shiftleft(int* arr,int d,int n)
{
    if(d == n-d)
    {
        swap_block(arr,0,d,d);
        return;
    }
    if(d < n-d)
    {
        swap_block(arr,0,n-d,d);
        shiftleft(arr,d,n-d);
    }else{
        swap_block(arr,0,n-d,d);
        shiftleft(arr+n-d,2*d-n,n-d);
    }
}

int find_pivot_index(int *arr,int n)
{
    //assuming alll distinct is necessary
    int l = 0,r = n-1;

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid] > arr[l])
        {
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return r+1;
}

bool binary(int *arr,int fi,int si,int val)
{
    while(fi < si)
    {
        int mid = (fi + (si-fi)/2);
        if(arr[mid] == val)
            return 1;
        if(arr[mid] > val)
            si = mid-1;
        else
            fi = mid+1;
    }
    return 0;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    shiftleft(arr,3,9);

    for(int i = 0;i < 9;++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    int x = 10;
    int i = find_pivot_index(arr,9);
    if(binary(arr,i,8,x) || binary(arr,0,i-1,x))
    {
        cout << "Element Found" << '\n';
        return 0;
    }
    cout << "Element not Found" << '\n';
    return 0;
}