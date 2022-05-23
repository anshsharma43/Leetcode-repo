class Solution {
public:
    int maxSubArray(vector<int>& arr) 
    {
        int n=arr.size();
        
        int max_sum=arr[0];
        int curr_sum=arr[0];
        
        for(int i=1;i<n;i++)
        {
            curr_sum=max(arr[i],arr[i]+curr_sum);
            max_sum=max(max_sum,curr_sum);
        }
        
        return max_sum;
    }
};
