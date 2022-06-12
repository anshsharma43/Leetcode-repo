class Solution {
public:
    
    // Naive solution
    
    /*bool check(vector<string> &temp,int row,int col,int n)
    {
        int r=row;
        int c=col;
        
        // upper diagonal
        while(r>=0 && c>=0)
        {
            if(temp[r][c]=='Q')
            {
                return false;
            }
            
            r--;
            c--;
        }
        
        r=row;
        c=col;
        
        // left
        while(c>=0)
        {
            if(temp[r][c]=='Q')
            {
                return false;
            }
            
            c--;
        }
        
        r=row;
        c=col;
        
        // right diagonal
        while(r<n && c>=0)
        {
            if(temp[r][c]=='Q')
            {
                return false;
            }
            
            r++;
            c--;
        }
        
        return true;
    }
    
    void helper(vector<vector<string>> &res,vector<string> &temp,int col,int n)
    {
        if(col==n)
        {
            res.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(check(temp,row,col,n)==true)
            {
                temp[row][col]='Q';
                helper(res,temp,col+1,n);
                temp[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> temp(n);
        
        string str(n,'.');
        
        for(int i=0;i<n;i++)
        {
            temp[i]=str;
        }
        
        int col=0;
        
        helper(res,temp,col,n);
        
        return res;
    }*/
    
    // Better solution
    
    void helper(vector<vector<string>> &res,vector<string> &temp,int col,int n,
               vector<int> &leftRow,
               vector<int> &lowerDiagonal,
               vector<int> &upperDiagonal)
    {
        if(col==n)
        {
            res.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]!=1 && 
              lowerDiagonal[row+col]!=1 &&
              upperDiagonal[n-1+col-row]!=1)
            {
                temp[row][col]='Q';
                
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                
                helper(res,temp,col+1,n,leftRow,lowerDiagonal,upperDiagonal);
                
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
                
                temp[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> res;
        vector<string> temp(n);
        
        vector<int> leftRow(n,0);
        vector<int> lowerDiagonal(2*n-1,0);
        vector<int> upperDiagonal(2*n-1,0);
        
        string str(n,'.');
        
        for(int i=0;i<n;i++)
        {
            temp[i]=str;
        }
        
        int col=0;
        
        helper(res,temp,col,n,leftRow,lowerDiagonal,upperDiagonal);
        
        return res;
    }
};
