#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define INF 1000000000
typedef long long ll;
#define pii pair<ll,ll>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,m,a,b,w,u,v,curr_dis;
    cin>>n>>m;
    vector <pii>arr[n+1];

    while(m--) 
    {
        cin>>a>>b>>w;
        arr[a].pb({w,b});  // {dis,node}
        arr[b].pb({w,a});
    }

    vector <ll>d(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii>>pq;  // declaration of min heap
    d[1] = 0;   pq.push({0,1});  // {dis,node}  dis taken as first parameter to sort automatically 
    
    while(!pq.empty())
    {
        curr_dis  = pq.top().F;
        u = pq.top().S;
        pq.pop();

        for(pii child:arr[u])
        {   
            w = child.F; v=child.S; 
            if(curr_dis+w<=d[v])   
            {
                d[v] = curr_dis+w;
                pq.push({d[v],v});   
            }
        }
    }

    for(i=1;i<=n;i++)
        cout<<d[i]<<" ";
    
    return 0;
}