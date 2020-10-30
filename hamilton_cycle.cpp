/*
    hamilton cycle refer sahani algorithms textbook  
    TimeComplexity : O(n!)
*/
#include<bits/stdc++.h>
#define F first
#define S second
#define maxn 100
#define pb push_back
typedef long long ll;
using namespace std;

ll g[11][11];
ll col[maxn+1],n;
bool flag,has_sol;

void next_node(ll k)
{   
    ll i;
    while(1)
    {
        col[k]=(col[k]+1)%(n+1); 

        if(col[k]==0)  // if all nodes are tried and unable to assign node
            return ;

        if(g[col[k-1]][col[k]]==1) // last node in cycle and current node should have link ,because it is a path 
        {
            for(i=1;i<k;i++)
                if(col[k]==col[i])  // if kth node is already visited  
                    break;

            if(i==k) // if new node we assigned is not visited 
                if( (k==n && g[col[k]][col[1]]==1 ) || (k<n) )  // if( (it is last node && has link to first node) || (it is not last node) )  we assigned a node to kth position
                    return ;
        }
    }
}

void print_solution()
{
    has_sol=true;
    for(ll i=1;i<=n;i++) cout<<col[i]<<" ";cout<<"\n";
}

void hamilton_cycle(ll k)
{   
    while(1)
    {
        next_node(k);
        if(col[k]==0)
            return ;
        if(k==n)
            print_solution();
        else 
            hamilton_cycle(k+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,u,v,m;
    cin>>t;
	
    while(t--)
    {   
        cin>>n>>m;
        has_sol=0;
        memset(col,0,sizeof(col));
        memset(g,0,sizeof(g));

        for(i=0;i<=n;i++) g[0][i]=g[i][i]=1;

        for(i=0;i<m;i++)
            cin>>u>>v,g[u][v]=1,g[v][u]=1; 
        
        hamilton_cycle(1);
        if(!has_sol) 
            cout<<"No Solution"<<"\n";
    }
    
    return 0;
}