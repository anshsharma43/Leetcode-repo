class Solution {
public:
    
    // naive method
    
    /*int dp[501][501];
    
    int helper(int index,int k,vector<int> &arr)
    {
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        
        if(arr.size()==1)
        {
            return dp[index][k]=arr[0];
        }
        
        index=(index+k)%(arr.size());
        
        arr.erase(arr.begin()+index);
        
        return dp[index][k]=helper(index,k,arr);
    }
    
    int findTheWinner(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        
        vector<int> arr;
        
        for(int i=0;i<n;i++)
        {
            arr.push_back(i+1);
        }
        
        k--;
        
        int index=0;
        
        int res=helper(index,k,arr);
        
        return res;
    }*/
    
    
    
    // efficient method
    
    int dp[501][501];
    
    int helper(int n,int k)
    {
        if(dp[n][k]!=-1)
        {
            return dp[n][k];
        }
        
        if(n==1)
        {
            return dp[n][k]=0;
        }
        
        return dp[n][k]=(helper(n-1,k)+k)%n;
    }
    
    int findTheWinner(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        
        int res=helper(n,k);
        
        return res+1;
    }
};
