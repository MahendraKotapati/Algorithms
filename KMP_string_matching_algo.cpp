/*  
    https://www.youtube.com/watch?v=tWDUjkMv6Lc
    https://www.youtube.com/watch?v=eKOMXcmKF7w
    https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

*/
#include <bits/stdc++.h>
using namespace std;

int LPS[100005];

void lps(string s)
{
    int n = s.length(),i,j;
        
    LPS[0] = 0;
    
    for(i=1;i<n;i++)
    {
        j = LPS[i-1];   
        // always LPS[i]<=LPS[i-1]+1 , so we take LPS[i-1] and now check s[i] , s[j] because s[0:j-1]  already LPS of length j
        while(j>0 && s[i]!=s[j])
            j = LPS[j-1];
        
        if(s[i]==s[j])
            j++;
            
        LPS[i] = j;  
    }
    
}

int KMP(string text,string pat)
{   
    int n,m,i,j,count = 0;

    n = text.length() ; m = pat.length(); 
    i = j = 0;

    while(i<n)
    {
        if(text[i]==pat[j]) {
            i++;j++;
        }
        if(j==m) {
            count++;
            j = LPS[j-1];
        }
        else if(i<n && text[i]!=pat[j]) {

            if(j!=0)
                j = LPS[j-1];
            else   
                i++;
        }
    }
    return count;

}

 
int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string text,pat;
   		cin >> pat >> text;
        //cout<<" P:"<<pat<<" T:"<<text;
        lps(text);
   		cout << KMP(text,pat) << "\n";
   	}

    return 0;
}  // } Driver Code Ends