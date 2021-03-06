int dp[101][101];
class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    if(t.size()==0)
		    {
		        return s.size();
		    }
		    if(s.size()==0)
		    {
		        return t.size();
		    }
		    int n=s.size(),m=t.size();
		    for(int i=0;i<=n;i++)
		    {
		        dp[i][0]=i;
		    }
		    for(int j=0;j<=m;j++)
		    {
		        dp[0][j]=j;
		    }
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=m;j++)
		        {
		            if(s[i-1]==t[j-1])
		            {
		                dp[i][j]=dp[i-1][j-1];
		            }
		            else
		            {
		                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		            }
		        }
		    }
		    return dp[n][m];
		}
};
