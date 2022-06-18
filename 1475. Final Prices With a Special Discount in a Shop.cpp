class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<int> res(n,-1);
        
        stack<int> s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==false && s.top()>arr[i])
            {
                s.pop();
            }
            
            res[i]=s.empty()==true?arr[i]:arr[i]-s.top();
            
            s.push(arr[i]);
        }
        
        return res;
    }
};
