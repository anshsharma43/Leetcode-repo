class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) 
    {
        int n=arr.size();
        
        int res=0;
        
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            if(arr[mid]==x)
            {
                low=mid+1;
            }
            
            else if(arr[mid] > x)
            {
                res=mid;
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
            }
        }
        
        return res>=n?arr[0]:arr[res];
    }
};
