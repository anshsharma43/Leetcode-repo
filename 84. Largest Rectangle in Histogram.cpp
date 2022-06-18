// Stack

class Solution {
public:
    
    void helperSmallestOnLeft(vector<int> &arr,vector<int> &left,int n)
    {
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(s.empty()==false && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            
            left[i]=s.empty()==true?-1:s.top();
            
            s.push(i);
        }
    }
    
    void helperSmallestOnRight(vector<int> &arr,vector<int> &right,int n)
    {
        stack<int> s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==false && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            
            right[i]=s.empty()==true?n:s.top();
            
            s.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& arr) 
    {
        int n=arr.size();
        
        int res=INT_MIN;
        
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        helperSmallestOnLeft(arr,left,n);
        helperSmallestOnRight(arr,right,n);
        
        for(int i=0;i<n;i++)
        {
            int val=(right[i]-left[i]-1)*arr[i];
            
            res=max(res,val);
        }
        
        return res;
    }
};
