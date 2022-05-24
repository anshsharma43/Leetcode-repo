class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) 
    {
        int rows=arr.size();
        int cols=arr[0].size();
        
        int low=0,high=(rows*cols)-1;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            int temp_row=mid/cols;
            int temp_col=mid%cols;
            
            if(arr[temp_row][temp_col] == target)
            {
                return true;
            }
            
            if(arr[temp_row][temp_col] > target)
            {
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
            }
        }
        
        return false;
    }
};
