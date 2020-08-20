#include<stdio.h>

int main()
{
	int t,amount,dp[301][1000],i,j,coins[300],n,coin;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);

	    for(i=0;i<n;i++)
	      scanf("%d",&coins[i]);

	    scanf("%d",&amount);
	    
	    for(i=0;i<=amount;i++)  // with zero denominations we can't cover any amount except amount=0
	        dp[0][i]=0;
        
        for(i=0;i<=n;i++)     // amount 0 can be covered by any no.of denominations 
	        dp[i][0]=1;       // important
    

	    for(i=1;i<=n;i++)
	    {
	        coin=coins[i-1];
	        for(j=1;j<=amount;j++)
	        {
	            if(coin>j) dp[i][j] = dp[i-1][j];
	            else dp[i][j]=dp[i-1][j]+dp[i][j-coin];
	        }
	    }
	    printf("%d\n",dp[n][amount]);
	    
	}
	return 0;
}