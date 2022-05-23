class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        
        vector<vector<int>> res;
        
        sort(arr.begin(),arr.end());
        
        int count=0; 
        
        res.push_back({arr[0][0],arr[0][1]});
        
        for(int i=1;i<n;i++)
        {
            if(arr[i][0] >= res[count][0] && arr[i][0] <= res[count][1])
            {
                res[count][1]=max(arr[i][1],res[count][1]);
            }
            
            else
            {
                count++;
                res.push_back({arr[i][0],arr[i][1]});
            }
        }
        
        return res;
    }
};
