class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) 
    {
        int n=arr2.size();
        
        vector<int> res;
        
        stack<int> s;
        
        unordered_map<int,int> mp;
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==false && s.top()<=arr2[i])
            {
                s.pop();
            }
            
            int a=s.empty()==true?-1:s.top();
            
            mp[arr2[i]]=a;
            
            s.push(arr2[i]);
        }
        
        for(int i=0;i<arr1.size();i++)
        {
            res.push_back(mp[arr1[i]]);
        }
        
        return res;
    }
};
