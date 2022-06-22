class Solution {
public:
    int maxSubArray(vector<int>& arr) 
    {
    	int n=arr.size();
        
        int sum=0;
        int max_sum=arr[0];
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            
            max_sum=max(max_sum,sum);
            
            if(sum<0)
            {
                sum=0;
            }
        }
        
        return max_sum;
    }
};
