class Solution {
public:
    
    int helper(string &pattern,string &text,int i,int j,vector<vector<int>> &dp)
    {
        if(j<0)
        {
            if(i<0)
            {
                return 1;
            }

            else
            {
                while(i>=0)
                {
                    if(pattern[i]!='*')
                    {
                        return 0;
                    }

                    i--;
                }

                return 1;
            }
        }

        if(i<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int res=0;

        if(pattern[i]==text[j])
        {
            res=helper(pattern,text,i-1,j-1,dp);
        }

        else
        {
            if(pattern[i]=='?')
            {
                res=helper(pattern,text,i-1,j-1,dp);
            }

            else if(pattern[i]=='*')
            {
                res=max({helper(pattern,text,i-1,j-1,dp), 
                         helper(pattern,text,i,j-1,dp),
                         helper(pattern,text,i-1,j,dp)});
            }

            else
            {
                res=0;
                return res;
            }
        }

        return dp[i][j]=res;
    }
    
    bool isMatch(string text, string pattern) 
    {
        int m=pattern.size();
        int n=text.size();

       /* vector<vector<int>> dp(m,vector<int> (n,-1));

        return helper(pattern,text,m-1,n-1,dp);*/

        vector<vector<int>> dp(m+1,vector<int> (n+1,0));

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j<1)
                {
                    if(i<1)
                    {
                        //return 1;
                        dp[i][j]=1;
                    }

                    else
                    {
                        bool flag=true;

                        int x=i;

                        while(x>=1)
                        {
                            if(pattern[x-1]!='*')
                            {
                                flag=false;
                                break;
                            }

                            x--;
                        }

                        if(flag==false)
                        {
                            dp[i][j]=0;
                        }

                        else
                        {
                            dp[i][j]=1;
                        }
                    }

                    continue;
                }

                if(i<1)
                {
                    //return 0;
                    dp[i][j]=0;
                    continue;
                }

                int res=0;

                if(pattern[i-1]==text[j-1])
                {
                    //res=helper(pattern,text,i-1,j-1,dp);
                    res=dp[i-1][j-1];
                }

                else
                {
                    if(pattern[i-1]=='?')
                    {
                        //res=helper(pattern,text,i-1,j-1,dp);
                        res=dp[i-1][j-1];
                    }

                    else if(pattern[i-1]=='*')
                    {
                        /*res=max({helper(pattern,text,i-1,j-1,dp), 
                                 helper(pattern,text,i,j-1,dp),
                                 helper(pattern,text,i-1,j,dp)});*/

                        //res=max({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                        res=max(dp[i-1][j],dp[i][j-1]);
                    }

                    else
                    {
                        /*res=0;
                        return res;*/
                        dp[i][j]=0;
                        continue;
                    }
                }

                dp[i][j]=res;
            }
        }

        return dp[m][n];
    }
};
