// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

vector<int> rg[5001],order,scc;  // SSC stores strongly connected components of current SSC    , rg[] stores transpose graph
int vis[5001];

/* 
order vector contains nodes in increasing order of OutTime , highest out time means it like root, it has indegree zero , inorder to print that SCC
we use transpose graph  (if we use normal graph from root it can aslo go to other SSC)
*/

void dfs(int node,const vector<int>g[])
{
    vis[node]=1;
    for(int child:g[node])
        if(vis[child]==0)
            dfs(child,g);

    order.push_back(node);
}

void dfs_SCC(int node)
{
    vis[node]=1;
    for(int child:rg[node])
        if(vis[child]==0)
            dfs_SCC(child);

    scc.push_back(node);
}

int kosaraju(int V, vector<int> adj[])
{

    int i,j,scc_count=0;

    for(i=0;i<V;i++)   // constructing transpose graph
    {
        for(int j:adj[i])
            rg[j].push_back(i);
    }

    memset(vis,0,sizeof(vis));
    order.clear();

    for(i=0;i<V;i++)
        if(vis[i]==0)
            dfs(i,adj);


    memset(vis,0,sizeof(vis));

    for(i=V-1;i>=0;i--)   // traversing graph from nodes having highest out time , becaouse it has out degree zero
    {
        if(vis[order[i]]==0)
        {   
            scc.clear();
            dfs_SCC(order[i]);

            scc_count++;

            /*for(int node:scc)      //to print SCC 
                cout<<node<<" ";
            cout<<"\n"; */
        }
    }

    for(i=0;i<5001;i++)
        rg[i].clear();

    return scc_count;
}

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  