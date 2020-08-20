/* sqrt decomposition with example of range minimum query   */

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t=1,i,n,q,l,r,LB,RB,BLK,ans;
    //cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n),root(n,INT_MAX);
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        BLK = sqrt(n);

        for(i=0;i<n;i++)
            root[i/BLK]=min(root[i/BLK],arr[i]);
        
        cin>>q;

        while(q--)
        {   
            ans = INT_MAX;
            cin>>l>>r;
            if(l>r)  swap(l,r);
            
            LB = l/BLK;  RB = r/BLK;

            if(LB==RB)
                for(i=l;i<=r;i++)
                    ans = min(ans,arr[i]);
            
            else  
            {
                for(i=l;i<BLK*(LB+1);i++)
                    ans = min(ans,arr[i]);
                
                for(i=LB+1;i<RB;i++)
                    ans = min(ans,root[i]);
                
                for(i=BLK*(RB);i<=r;i++)
                    ans = min(ans,arr[i]);
                
            }

            cout<<ans<<"\n";
        }
    }
    
    return 0;
}