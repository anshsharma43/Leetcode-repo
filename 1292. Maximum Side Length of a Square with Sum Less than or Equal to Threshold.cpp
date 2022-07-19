class Solution {
public:
    
    bool check(vector<vector<int>> &dp,int k,int max_sum)
    {
        int rows=dp.size();
        int cols=dp[0].size();
        
        int sum=0;
        
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(i-k>=0 && j-k>=0)
                {
                    sum=dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k];
                    
                    if(sum<=max_sum)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    int maxSideLength(vector<vector<int>>& arr, int max_sum)
    {
        int rows=arr.size();
        int cols=arr[0].size();
        
        int res=0;
        
        int low=0;
        int high=min(rows,cols);
        
        vector<vector<int>> dp(rows+1,vector<int> (cols+1,0));
        
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=cols;j++)
            {
                dp[i][j]=arr[i-1][j-1] + (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
            }
        }
        
//         for(int i=0;i<=rows;i++)
//         {
//             for(int j=0;j<=cols;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
            
//             cout<<"\n";
//         }
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(check(dp,mid,max_sum)==true)
            {
                res=mid;
                low=mid+1;
            }
            
            else
            {
                high=mid-1;
            }
        }
        
        return res;
    }
};
