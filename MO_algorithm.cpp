#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll BLK,cnt[1000006],ans[200005],arr[30003],uniq;
 
struct query
{
    int l,r,idx;

}
q[200005];

bool cmp(query a,query b)
{
    if(a.l/BLK!=b.l/BLK)
        return a.l/BLK<b.l/BLK;
    return a.r<b.r;
}

void add(ll idx)
{
    cnt[arr[idx]]++;
    if(cnt[arr[idx]]==1)
        uniq++;
    
}

void remove(ll idx)
{
    cnt[arr[idx]]--;
    if(cnt[arr[idx]]==0)
        uniq--;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll i,n,queries,l,r,ML,MR;
      
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];

    cin>>queries;
    BLK = sqrt(n);

    for(i=0;i<queries;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--; q[i].r--;
        q[i].idx = i;
    }

    sort(q,q+queries,cmp);
    ML = 0; MR = -1; uniq = 0;

    for(i=0;i<queries;i++)
    {   
        l = q[i].l ; 
        r = q[i].r ;

        while(MR<r)
            MR++,add(MR);

        while(ML>l)
            ML--,add(ML);  
        
        while(MR>r)
            remove(MR),MR--;
        
        while(ML<l)
            remove(ML),ML++;
        
        ans[q[i].idx] = uniq;

    }
    for(i=0;i<queries;i++)
        cout<<ans[i]<<"\n";
    
    return 0;
}