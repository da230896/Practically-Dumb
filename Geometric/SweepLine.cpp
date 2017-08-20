#include <iostream>

using namespace std;
const int MAXN = 100001;

typedef struct st{
    double x,y,e;
}point;

bool intersect(const point &a,const point &b,const point &c,const point &d)
{
    /*
        a-----b  c-----d is the format function expects
    */
    double A = ;
    double B = ;
    double C = ;

    

}

point arr[MAXN];

bool comp(const point &a,const point &b)
{
    if(a.x > b.x)
        return false;
    else if(a.x == b.x){
        if(a.e > b.e)
            return false;
        else if(a.e == b.e)
        {
            if(a.y > b.y)
                return false;
        }
    }
    return true;
}

int main()
{
    int N;//number of lines
    cin >> N;
    for(int i = 0;i < 2*N;++i)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i++].e = 0;
        cin >> arr[i].x >> arr[i].y;
        arr[i].e = 1;
    }
    sort(arr,arr+N,comp);

    return 0;
}