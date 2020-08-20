/* mColoring problem refer sahani algorithms textbook  

   TimeComplexity : O(m^n)
*/

#include<bits/stdc++.h>
#define F first
#define S second
#define maxn 1000
#define pb push_back
typedef long long ll;
using namespace std;

//vector <ll>g[maxn+1];
ll g[maxn+1][maxn+1];
ll col[maxn+1],m,n;
bool flag,has_sol;

void next_color(ll k)
{
    while(1)
    {
        col[k]=(col[k]+1)%(m+1);

        if(col[k]==0)  // if all colors are tried and unable to assign color 
            return ;

        ll i;

        for(i=1;i<=n;i++)
            if(g[k][i]==1 && col[i]==col[k])  // if kth node assigned  color = child (adjacent node) color we try to assign next color 
                break;
            

        if(i==n+1) // if  currently assigned color is satisfying so return 
            return ;
    }

}

void print_solution()
{
    has_sol=true;
    //for(ll i=1;i<=n;i++) cout<<col[i] <<" ";cout<<"\n";
}

void graph_coloring(ll k)
{   
    while(1)
    {
        next_color(k);
        if(col[k]==0)
            return ;
        if(k==n)
            print_solution(); 
        else 
            graph_coloring(k+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,u,v,edges;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m>>edges;
        has_sol=0;
        memset(col,0,sizeof(col));
        memset(g,0,sizeof(g));
        for(i=0;i<edges;i++)
            cin>>u>>v,g[u][v]=g[v][u]=1; 
        
        graph_coloring(1);
        //if(!has_sol)
        //    cout<<"No Solution";
        cout<<has_sol<<"\n";
    }
    
    return 0;
}