#include <bits/stdc++.h>

using namespace std;

double e;

double find_cube_root(int &N)
{
    double lo = 0.0,hi = N;
    while(true)
    {
        double mid = (lo+hi)/2.0;
        if(abs(N-mid*mid*mid) <= e)
        {
            return mid;
        }else if(N > (mid*mid*mid))
        {
            lo = mid;
        }else{
            hi = mid;
        }
    }
}

int main()
{
    int N;
    e = 0.000001;
    cin >> N;

    cout << find_cube_root(N) << '\n';

    return 0;
}