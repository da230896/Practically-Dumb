#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <iomanip>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

int MAXN = 50001;
vector<pii> arr(MAXN),X(MAXN),Y(MAXN);
int N;

double dist(pii a,pii b)
{
    int x = (a.fi - b.fi);
    int y = (a.se - b.se);
    return sqrt(x*1ll*x + y*1ll*y);
}

bool comp(const pii &a,const pii &b)
{
    if(a.fi > b.fi)
        return false;
    if(a.fi == b.fi && a.se > b.se)
        return false;
    return true;
}

double solve(int L,int R)
{ 
    if(R-L < 3)
    {
        if(R-L == 2)
            return min({dist(arr[X[L].se],arr[X[L+1].se]),dist(arr[X[L].se],arr[X[L+2].se]),dist(arr[X[L+2].se],arr[X[L+1].se])});
        else
            return dist(arr[X[L].se],arr[X[L+1].se]);
    }else{
        int mid = L + ((R-L)>>1);
        double del_1 = solve(L,mid);
        double del_2 = solve(mid+1,R);
        double del = min(del_2,del_1);
        int pos_l = lower_bound(X.begin(),X.begin()+mid,mp(X[mid].fi-del,INT_MIN),comp)-X.begin();
        int pos_r = upper_bound(X.begin()+mid,X.begin()+R-L,mp(X[mid].fi+del,INT_MAX),comp)-X.begin();
        
        unordered_map<int,bool> YL,YR;
        for(int i = pos_l;i <= mid;++i)
        {
            YL[arr[X[i].se].se] = 1;
        }
        for(int i = mid+1;i < pos_r;++i)
        {
            YR[arr[X[i].se].se] = 1;
        }

        vector<pii> stripe;
        for(int i = 0;i < N;++i)
        {
            if(YL[Y[i].fi] || YR[Y[i].fi])
            {
                stripe.pb(arr[Y[i].se]);
            }
        }

        for(int i = 0;i < stripe.size();++i)
        {
            for(int j = i+1;j < i+8 && j < stripe.size();++j)
            {
                del = min(del,dist(stripe[i],stripe[j]));
            }
        }
        return del;
    }    
}

int main()
{
    freopen("in.txt","r",stdin);    
    cin >> N;
    for(int i=0;i < N;++i)
    {
        cin >> arr[i].fi >> arr[i].se;
        X[i].fi = arr[i].fi,X[i].se = i;
        Y[i].fi = arr[i].se,Y[i].se = i;
    }  
    sort(X.begin(),X.begin()+N);
    sort(Y.begin(),Y.begin()+N);
    if(N > 3)
        cout << setprecision(10) << solve(0,N-1) << '\n';
    else{
        cout << min({dist(arr[0],arr[1]),dist(arr[0],arr[2]),dist(arr[2],arr[1])}) << '\n';
    }
    return 0;
}