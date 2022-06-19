class Solution {
public:
    
    // Better space complexity
    void helper(vector<int> &arr,vector<int> &res,int n)
    {
        stack<int> s;
        
        for(int i=2*n-1;i>=0;i--)
        {
            while(s.empty()==false && s.top()<=arr[i%n])
            {
                s.pop();
            }
            
            if(i<n)
            {
                res[i]=s.empty()==true?-1:s.top();
            }
            
            s.push(arr[i%n]);
        }
    }
    
    vector<int> nextGreaterElements(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<int> res(n,-1);
        
        helper(arr,res,n);
        
        return res;
    }
    
    
    // Naive solution
    
    /*void helper(vector<int> &arr,vector<int> &res,int n)
    {
        stack<int> s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==false && s.top()<=arr[i])
            {
                s.pop();
            }
            
            res[i]=s.empty()==true?-1:s.top();
            
            s.push(arr[i]);
        }
    }
    
    vector<int> nextGreaterElements(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<int> res(2*n,-1);
        
        for(int i=0;i<n;i++)
        {
            arr.push_back(arr[i]);
        }
        
        n=arr.size();
        
        helper(arr,res,n);
        
        vector<int> finalRes;
        
        for(int i=0;i<n/2;i++)
        {
            finalRes.push_back(res[i]);
        }
        
        return finalRes;
    }*/
};

