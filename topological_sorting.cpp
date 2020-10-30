/*  topological sorting works only for directed acyclic graph  */
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

vector <ll>g[100005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t=1,i,n,m,u,v,node,cnt=0;
    
   
    cin>>n>>m;
    vector <ll>in(n+1,0),ans;

    priority_queue <ll,vector<ll>,greater<ll>>pq;  /* we can also queue if order of vertices not needed in incresing order */

    for(i=0;i<m;i++)
    {
        cin>>u>>v;g[u].pb(v); 
        in[v]++;
    }
    
    for(i=1;i<=n;i++)
        if(in[i]==0)
            pq.push(i);
    
        while(!pq.empty())
        {
            node = pq.top();
            ans.pb(node);
            pq.pop();

            for(ll child:g[node])
            {
                in[child]--;
                if(in[child]==0)
                    pq.push(child);    
            }
            cnt++;
        }
        if(cnt!=n)
            cout<<"there exists cycle in given graph"; 
        else  
            for(i=0;i<n;i++)
                cout<<ans[i]<<" ";
    
    return 0;
}