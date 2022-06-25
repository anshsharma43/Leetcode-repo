class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        int n1=arr1.size();
        int n2=arr2.size();
        
        vector<int> count(1001,0);
        
        vector<int> res;
        
        for(int i=0;i<n1;i++)
        {
            count[arr1[i]]++;
        }
        
        for(int i=0;i<n2;i++)
        {
            int k=count[arr2[i]];
            
            while(k>0)
            {
                res.push_back(arr2[i]);
                k--;
            }
            
            count[arr2[i]]=0;
        }
        
        for(int i=0;i<=1000;i++)
        {
            int k=count[i];
            
            while(k>0)
            {
                res.push_back(i);
                k--;
            }
        }
        
        return res;
    }
};
