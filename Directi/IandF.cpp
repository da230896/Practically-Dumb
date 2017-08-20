#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string I,F;
    cin >> I >> F;

    unordered_map<string,int> dis;

    queue<pair<string,int> > q;
    int pp = -1;
    for(int i = 0;i < I.length();++i)
    {
        if(I[i] == '_')
        {
            pp = i;
            break;
        }
    }
    q.push({I,pp});

    while(!q.empty())
    {
        string node = q.front().first;
        int idx = q.front().second;
        q.pop();
        int d = dis[node];

        if(idx > 0)
        {
            swap(node[idx],node[idx-1]);
            if(!dis.count(node))
            {    
                if(node.compare(F) == 0)
                {
                    cout << d+1 << '\n';
                    return;
                }
                dis[node] = d+1;
                q.push({node,idx-1});    
            }    
            swap(node[idx],node[idx-1]);
        }
        if(idx < node.length()-1)
        {
            swap(node[idx],node[idx+1]);
            if(!dis.count(node))
            {
                if(node.compare(F) == 0)
                {
                    cout << d+1 << '\n';
                    return;
                }
                dis[node] = d+1;
                q.push({node,idx+1});    
            }
            swap(node[idx],node[idx+1]);
        }
        if(idx+2 < node.length() && node[idx+1] != node[idx+2])
        {
            swap(node[idx],node[idx+2]);
            if(!dis.count(node))
            {
                if(node.compare(F) == 0)
                {
                    cout << d+1 << '\n';
                    return;
                }
                dis[node] = d+1;
                q.push({node,idx+2});    
            }
            swap(node[idx],node[idx+2]);
        }
        if(idx-2 >= 0 && node[idx-1] != node[idx-2])
        {
            swap(node[idx-2],node[idx]);
            if(!dis.count(node))
            {
                if(node.compare(F) == 0)
                {
                    cout << d+1 << '\n';
                    return;
                }
                dis[node] = d+1;
                q.push({node,idx-2});    
            }
            swap(node[idx],node[idx-2]);
        }
    }
    if(dis[F] == 0)
        cout << "Not Possible\n";
    else
        cout << dis[F] << '\n';
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}