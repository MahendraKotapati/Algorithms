//  spoj prime generator 
//  https://www.spoj.com/problems/PRIME1/

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define maxn 100005
typedef long long ll;
using namespace std;

vector <ll>arr;

void seive()
{
    ll i,j,prime[maxn+1];
    memset(prime,0,sizeof(prime));
    prime[0] = prime[1] = 1;  // making it as non-prime

    for(i=2;i*i<=maxn;i++)
        if(!prime[i])
            for(j=i*i;j<=maxn;j+=i)
                prime[j] = 1; // making it as non-prime
    
    for(i=2;i<=maxn;i++)
        if(!prime[i]) 
            arr.pb(i);
}

void segmented_seive(ll low,ll high)
{   
    if(low==1) low++;
    seive();

    ll i,j,prime[high-low+1];

    memset(prime,0,sizeof(prime));

    for(ll p:arr)
    {   
        if(p*p<=high)
        {
            j = (low/p) * p;
            if(j<low) j+=p;
            if(j==p) j+=p;
            for(;j<=high;j+=p)
                prime[j-low]=1; // making it as non-prime
        }
    }

    for(i=low;i<=high;i++)
        if(!prime[i-low])
            cout<<i<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,a,b;
    cin>>t;
	
    while(t--)
    {   
        cin>>a>>b;
        segmented_seive(a,b);
        cout<<"\n";
    }
    
    return 0;
}