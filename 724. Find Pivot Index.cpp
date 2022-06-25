class Solution {
public:
    int pivotIndex(vector<int>& arr) 
    {
        int n=arr.size();
        
        int res=-1;
        
        int left_sum=0;
        int right_sum=accumulate(arr.begin(),arr.end(),0);
        
        for(int i=0;i<n;i++)
        {
            if(left_sum==right_sum-arr[i])
            {
                return i;
            }
            
            left_sum+=arr[i];
            right_sum-=arr[i];
        }
        
        return -1;
    }
};
