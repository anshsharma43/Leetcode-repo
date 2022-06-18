// Stack
// Follow up of 84. Largest Rectangle in Histogram

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
    
    int helperMAH(vector<int>& arr) 
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
    
    int maximalRectangle(vector<vector<char>>& arr) 
    {
        int rows=arr.size();
        int cols=arr[0].size();
        
        vector<int> temp(cols,0);
        
        int res=INT_MIN;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(i==0)
                {
                    temp[j]=arr[i][j]-'0';
                }
                
                else
                {
                    if(arr[i][j]-'0'==0)
                    {
                        temp[j]=0;
                    }
                    
                    else
                    {
                        temp[j]+=(arr[i][j]-'0');
                    }
                }
            }
            
            res=max(res,helperMAH(temp));
        }
        
        return res;
    }
};
