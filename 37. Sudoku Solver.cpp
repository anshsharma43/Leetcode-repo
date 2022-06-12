class Solution {
public:

    bool check(vector<vector<char>> &arr,char ch,int row,int col)
    {
        for(int i=0;i<9;i++)
        {
            if(arr[i][col]==ch)
            {
                return false;
            }
            
            if(arr[row][i]==ch)
            {
                return false;
            }
            
            int r=3*(row/3)+i/3;
            int c=3*(col/3)+i%3;
            
            if(arr[r][c]==ch)
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool helper(vector<vector<char>> &arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {   
                        if(check(arr,ch,i,j)==true)
                        {
                            arr[i][j]=ch;
                        
                            if(helper(arr)==true)
                            {
                                return true;
                            }

                            else
                            {
                                arr[i][j]='.';
                            }
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& arr) 
    {
        helper(arr);
    }
};
