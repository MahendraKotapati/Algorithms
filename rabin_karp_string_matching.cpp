/*  
    https://www.youtube.com/watch?v=aKQmwAVGd3s 
    https://www.spoj.com/problems/NAJPF/
    
    Time complexity : O(|text|+|pattern|)
*/
#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;

void RabinKarp(string text,string pattern)
{
    ll len_text = text.length(),len_pat = pattern.length(),i,curr_hash;
    vector<ll>occurences;

    if(len_pat>len_text)
    {
       cout<<"Not Found"<<"\n";
       return ;
    }

    ll p=31,p_power[len_text],hash_text[len_text],hash_pattern; 

    p_power[0] = 1;    
    for(i=1;i<len_text;i++)   // pre-calculting powers of p
        p_power[i] = (p_power[i-1]*p)%mod;
    
    hash_text[0] = (text[0]-'a'+1)*p_power[0];

    for(i=1;i<len_text;i++)   // hash_text[i] stores prefix hash for every i
        hash_text[i] = ( hash_text[i-1] + (text[i]-'a'+1)*p_power[i] ) % mod;


    hash_pattern = 0;
    for(i=0;i<len_pat;i++)
        hash_pattern = (hash_pattern + (pattern[i]-'a'+1)*p_power[i] ) % mod;
    
    for(i=0;i+len_pat-1<len_text;i++)
    {
        curr_hash = hash_text[i+len_pat-1];
        if(i-1>=0) 
            curr_hash = (curr_hash - hash_text[i-1]+mod)%mod;

        if(curr_hash == (hash_pattern*p_power[i])%mod ) // very important insted of dividing with p_power[i] on leftside we multiply p_power[i] on right side 
            occurences.push_back(i+1);
    }

    if(occurences.size()==0)
        cout<<"Not Found";
    else   
    {   
        cout<<occurences.size()<<"\n";
        for(auto idx:occurences)
            cout<<idx<<" ";
    }
    cout<<"\n";

}

int main()
{
    ll t,i,len;
    string text,pattern;
    
    cin>>t;

    while(t--)
    {
        cin>>text>>pattern;
        RabinKarp(text,pattern);
        cout<<"\n";
    }

    return 0;
}

/*

3
ababab ab
aaaaa bbb
aafafaasf aaf


*/