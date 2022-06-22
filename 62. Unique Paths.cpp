class Solution {
public:
    
    int dp[101][101];
    
    int helper(int x1,int y1)
    {
        if(x1<0 || y1<0)
        {
            return 0;
        }
        
        if(dp[x1][y1]!=-1)
        {
            return dp[x1][y1];
        }
        
        if(x1==0 && y1==0)
        {
            return dp[x1][y1]=1;
        }

        return dp[x1][y1]=helper(x1,y1-1) + helper(x1-1,y1);
    }
    
    int uniquePaths(int m, int n) 
    {
        memset(dp,-1,sizeof(dp));
        
        int res=helper(m-1,n-1);
        
        return res;
    }
};
