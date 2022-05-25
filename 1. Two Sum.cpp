class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) 
    {
        int n=arr.size();
        
        vector<int> res;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            int element=target-arr[i];
            
            if(m.find(element)!=m.end())
            {
                res.push_back(i);
                res.push_back(m[element]);
                break;
            }
            
            m[arr[i]]=i;
        }
        
        return res;
    }
};
