class Solution {
public:
    
    // Better solution
    
    // DLRU method
    
    int orangesRotting(vector<vector<int>>& arr) 
    {
        if(arr.empty()==true)
        {
            return 0;
        }
        
        int rows=arr.size();
        int cols=arr[0].size();
        
        int res=0;
        
        int count_fresh=0;
        
        queue<pair<int,int>> q;
        
        int final_size=0;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j]!=0)
                {
                    count_fresh++;
                }
                
                if(arr[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        if(count_fresh==0)
        {
            return 0;
        }
        
        // DLRU
        
        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};
        
        while(q.empty()==false)
        {
            int size=q.size();
            
            final_size+=size;
            
            while(size>0)
            {
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int rx=x+dx[i];
                    int ry=y+dy[i];
                    
                    if(rx<0 || ry<0 || rx>=rows || ry>=cols || arr[rx][ry]!=1)
                    {
                        continue;
                    }
                    
                    arr[rx][ry]=2;
                    
                    q.push({rx,ry});
                }
                
                size--;
            }
            
            if(q.empty()==false)
                res++;
        }
        
        return final_size==count_fresh?res:-1;
    }
    
    // Naive (Have to write more if-else conditions)
	
	/*int orangesRotting(vector<vector<int>>& arr) 
    {
        if(arr.empty()==true)
        {
            return 0;
        }
        
        int rows=arr.size();
        int cols=arr[0].size();
        
        int res=0;
        
        int count_fresh=0;
        
        queue<pair<int,int>> q;
        
        int final_size=0;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j]!=0)
                {
                    count++;
                }
                
                if(arr[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        if(count_fresh==0)
        {
            return 0;
        }
        
        while(q.empty()==false)
        {
            int size=q.size();
            
            final_size+=size;
            
            while(size>0)
            {
                int i=q.front().first;
                int j=q.front().second;
                
                q.pop();
                
                if(i-1>=0)
                {
                    if(arr[i-1][j]==1)
                    {
                        q.push({i-1,j});
                        arr[i-1][j]=2;
                    }
                }
                
                if(j-1>=0)
                {
                    if(arr[i][j-1]==1)
                    {
                        q.push({i,j-1});
                        arr[i][j-1]=2;
                    }
                }
                
                if(i+1<rows)
                {
                    if(arr[i+1][j]==1)
                    {
                        q.push({i+1,j});
                        arr[i+1][j]=2;
                    }
                }
                
                if(j+1<cols)
                {
                    if(arr[i][j+1]==1)
                    {
                        q.push({i,j+1});
                        arr[i][j+1]=2;
                    }
                }
                
                size--;
            }
            
            if(q.empty()==false)
                res++;
        }
        
        return final_size==count_fresh?res:-1;
    }*/
};
