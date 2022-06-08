class Solution {
public:

    int helper(int n,int k)
    {
        
        if(n==1 && k==1)
        {
            return 0;
        }
        
        int mid=pow(2,n-1)/2;
        
        if(k<=mid)
        {
            return helper(n-1,k);
        }
        
        else
        {
            return 1 - helper(n-1,k-mid);
        }
    }
    
    int kthGrammar(int n, int k) 
    {
        int res=helper(n,k);
        
        return res;
    }
};
