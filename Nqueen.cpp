/* 
    Nqueen refer sahani algorithms textbook  
    TimeComplexity : O( (n^n)* n)   
*/

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

bool has_sol;
ll ans[11],n;

void print_solution()
{
    has_sol=true;
    for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<"\n";
}

bool place(ll k)
{
    
    for(ll j=1;j<k;j++)
        if( (ans[j]==ans[k]) || ((j-ans[j])==(k-ans[k])) || (j+ans[j]==k+ans[k]) ) // straight or diagonal 
            return false;
    return true;

}

void Nqueen(ll k)
{   
    if(k==n+1){    
        print_solution(); 
        return ;
    }
    
    for(ll i=1;i<=n;i++)
    {   
        ans[k]=i;
        if(place(k))
            Nqueen(k+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i;
    cin>>t;
	
    while(t--)
    {   
        has_sol = false;
        cin>>n;
        Nqueen(1);
        if(!has_sol)    
            cout<<"-1"<<"\n";
    }
    
    return 0;
}