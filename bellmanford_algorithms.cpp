#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define pll pair<ll,ll>
#define inf 1000000000
typedef long long ll;
using namespace std;

vector <pll>g[102];   // g({node,dis})
ll n,m;

bool has_negative_cycle()
{   
    int i,u,v,edge_cost;
    vector <ll>dis(n+1,inf);
    dis[0]=0;  // source is o

    for(i=1;i<=n-1;i++)  // relaxing each node, node-1 times
    {   
        for(u=0;u<n;u++)   // iterating for every edge
        {
            for(auto child:g[u])
            {   
                v = child.F ;  edge_cost = child.S;
                if(dis[u]+edge_cost<dis[v])
                    dis[v] = dis[u]+edge_cost;
            }
        }
    }

    // if edges relaxes for one more time it indicates that negative weight cycle
    for(u=0;u<n;u++)
    {
        for(auto child:g[u])
        {   
            v = child.F ; edge_cost = child.S;
            if(dis[u]+edge_cost<dis[v])     
                return true;
        }    
    }
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,u,v,w;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m;

        for(i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            g[u].pb({v,w});
        }
            

        cout<<has_negative_cycle()<<"\n";

        for(i=0;i<n;i++) g[i].clear();
    }
    
    return 0;
}