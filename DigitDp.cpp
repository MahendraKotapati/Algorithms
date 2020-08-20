// spoj k-12-OE numbers
// https://www.spoj.com/problems/KOPC12H/

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll len;
vector <ll>num;
ll dp[10][2][100][100];

vector<ll> to_array(ll n)
{   
    vector <ll>res;
    while(n>0)
    {
        res.pb(n%10);
        n/=10;
    }
    reverse(res.begin(),res.end());
    return  res;
}

ll solve(ll idx,ll tight,ll e,ll o)  // solve(idx,even,odd)
{
    
    //cout<<"check";
    if(idx==len)
        return e>o;
    
    if(dp[idx][tight][e][o]!=-1)
        return dp[idx][tight][e][o];
    
    ll limit,i,new_tight,ans = 0;

    limit = (tight) ? num[idx] : 9 ;   

    /* 
       tight = 0 means unrestricted range 
       tight = 1 means restricted range  
    */

    for(i=0;i<=limit;i++)
    {
         
        new_tight =  (i==limit) ? tight : 0;  
        /*  
            if i!=num[idx] then number generated will always less n 
            problem occurs when i == num[idx]  then we try to assign newtight for next recursive call (for the next positions )  
            
        */

        if(i&1)
            ans+= solve(idx+1,new_tight,e,o+i);
        else  
            ans+= solve(idx+1,new_tight,e+i,o);

    }

    return dp[idx][tight][e][o]=ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,a,b;
    cin>>t;
	
    while(t--)
    {   
        cin>>a>>b;

        num = to_array(a-1); len = num.size();
        memset(dp,-1,sizeof(dp));
        a=solve(0,1,0,0);
       
        num = to_array(b);  len = num.size();
        memset(dp,-1,sizeof(dp));
        b=solve(0,1,0,0);
        
        cout<<b-a<<"\n";
    }
    
    return 0;
}