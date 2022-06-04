class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n=arr.size();
        
        int res=0;
        
        if(n<3)
        {
            return res;
        }
        
        vector<int> leftMax(n+1,0);
        vector<int> rightMax(n+1,0);
        
        leftMax[0]=arr[0];
        rightMax[n-1]=arr[n-1];
        
        for(int i=1;i<n-1;i++)
        {
            leftMax[i]=max(leftMax[i-1],arr[i]);
            rightMax[n-i-1]=max(rightMax[n-i],arr[n-i-1]);
        }
        
        for(int i=1;i<n-1;i++)
        {
            res+=min(leftMax[i],rightMax[i])-arr[i];
        }
        
        return res;
    }
};
