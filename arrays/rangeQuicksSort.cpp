#include <bits/stdc++.h>

using namespace std;

void threeWayPartition(int *arr,int N,int low,int high,int &i,int &j)
{
    for(int k = 0;k < N;++k)
    {
        if(arr[k] > high)
        {
            continue;
        }else if(arr[k] <= high && arr[k] >= low)
        {
            j++;
            swap(arr[j],arr[k]);
        }else{
            i++;
            swap(arr[i],arr[k]);
            j++;
            swap(arr[j],arr[k]);
        }
    }
}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87,98, 3, 1, 32};
    int l = -1,h = -1;
    int n = sizeof(arr)/sizeof(int);

    threeWayPartition(arr,n,10,20,l,h);

    for(int i = 0;i < n;++i)
    {
        cout << arr[i] << ' ' ;
    }

    if(l+1 <= h)
    {
        cout << "\nNow elements are between(Range [10,20]) ";
        cout << l+2 << ' ' << h+1 << '\n';
        return 0;
    }else{
        cout << "No element in this range\n";
    }
    return 0;
}