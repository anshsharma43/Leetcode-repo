class Solution {
public:
    
    void helper(vector<int> &arr,int low,int high,int sum,vector<vector<int>> &res,
               int element)
    {
        while(low<high)
        {
            if(arr[low]+arr[high] < sum)
            {
                low++;
            }
            
            else if(arr[low]+arr[high]>sum)
            {
                high--;
            }
            
            else
            {
                res.push_back({element,arr[low],arr[high]});
                
                int last_low_occurence=arr[low];
                int last_high_occurence=arr[high];
                
                while(low<high && arr[low]==last_low_occurence)
                {
                    low++;
                }
                
                while(low<high && arr[high]==last_high_occurence)
                {
                    high--;
                }
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<vector<int>> res;
        
        if(n<3)
        {
            return res;
        }
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i]==arr[i-1])
            {
                continue;
            }
            
            int sum=0;
            sum-=arr[i];
            
            helper(arr,i+1,n-1,sum,res,arr[i]);
        }
        
        return res;
    }
};
