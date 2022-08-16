class Solution {
public:
    int helper(vector<vector<int>> &arr,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 1e9;
        }

        if(i==0 && j==0)
        {
            return arr[i][j];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int up=helper(arr,i-1,j,dp);
        int left=helper(arr,i,j-1,dp);

        return dp[i][j]=arr[i][j] + min(up,left);
    }

    int minPathSum(vector<vector<int>> &arr) 
    {
        int m=arr.size();
        int n=arr[0].size();

        /*vector<vector<int>> dp(m,vector<int> (n,-1));

        return helper(arr,m-1,n-1,dp);*/

        vector<vector<int>> dp(m+1,vector<int> (n+1,0));

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i<1 || j<1)
                {
                    //return 1e9;
                    dp[i][j]=1e9;
                    continue;
                }

                if(i==1 && j==1)
                {
                    //return arr[i][j];
                    dp[i][j]=arr[i-1][j-1];
                    continue;
                }

                int up=helper(arr,i-1,j,dp);
                int left=helper(arr,i,j-1,dp);

                dp[i][j]=arr[i-1][j-1] + min(up,left);
            }
        }

        return dp[m][n];
    }
};
