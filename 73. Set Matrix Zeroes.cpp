class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) 
    {
        int rows=arr.size();
        int cols=arr[0].size();
        
        int col0=1;
        
        for(int i=0;i<rows;i++)
        {
            if(arr[i][0]==0)
            {
                col0=0;
            }
            
            for(int j=1;j<cols;j++)
            {
                if(arr[i][j]==0)
                {
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }
        
        for(int i=rows-1;i>=0;i--)
        {
            for(int j=cols-1;j>=1;j--)
            {
                if(arr[i][0]==0 || arr[0][j]==0)
                {
                    arr[i][j]=0;
                }
            }
            
            if(col0==0)
            {
                arr[i][0]=0;
            }
        }
    }
};
