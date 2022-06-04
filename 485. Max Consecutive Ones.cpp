class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) 
    {
        int n=arr.size();
        
        int res=0;
        
        int maxRes=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                res++;
                maxRes=max(maxRes,res);
            }
            
            else
            {
                res=0;
            }
        }
        
        return maxRes;
    }
};
