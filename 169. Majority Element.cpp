class Solution {
public:
    int majorityElement(vector<int>& arr) 
    {
        int n=arr.size();
        
        int res=0;
        int count=1;
        
        for(int i=1;i<n;i++)
        {
            if(arr[res] == arr[i])
            {
                count++;
            }
            
            else
            {
                count--;
            }
            
            if(count==0)
            {
                res=i;
                count=1;
            }
        }
        
        return arr[res];
    }
};
