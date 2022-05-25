class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) 
    {
        int n=arr.size();
        
        if(n<4)
        {
            return {};
        }
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> res;
        
        for(int i=0;i<n-3;i++)
        {
            while(i>0 && arr[i]==arr[i-1])
            {
                i++;
            }
            
            for(int j=i+1;j<n-2;j++)
            {
                while(j>i+1 && arr[j]==arr[j-1])
                {
                    j++;
                }
                
                int sum=target-arr[i]-arr[j];
                
                int low=j+1;
                int high=n-1;
                
                while(low<high)
                { 
                    if(arr[low] + arr[high] == sum) 
                    {
                        int a=arr[i];
                        int b=arr[j];
                        int c=arr[low];
                        int d=arr[high];
                        res.push_back({a,b,c,d});
                        
                        while(low<high && arr[low] == c)
                        {
                            low++;
                        }
                        
                        while(low<high && arr[high] == d)
                        {
                            high--;
                        }
                    }
                    
                    else if(arr[low] + arr[high] < sum)
                    {
                        low++;
                    }
                    
                    else
                    {
                        high--;
                    }
                }
            }
        }
        
        return res;
    }
};
