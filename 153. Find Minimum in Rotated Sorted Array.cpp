class Solution {
public:
    int findMin(vector<int>& arr) 
    {
        int n=arr.size();
        
        int low=0;
        int high=n-1;
        
        if(n==1)
        {
            return arr[0];
        }
        
        if(arr[0]<arr[n-1])
        {
            return arr[0];
        }
        
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            
            if(arr[mid]<=arr[next] && arr[mid]<=arr[prev])
            {
                return arr[mid];
            }
            
            if(arr[mid]>=arr[0])
            {
                low=mid+1;
            }
            
            else
            {
                high=mid-1;
            }
        }
        
        return -1;
    }
};
