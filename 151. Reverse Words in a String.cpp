class Solution {
public:
    
    void reverse(string &str,int low,int high)
    {
        while(low<high)
        {
            swap(str[low],str[high]);
            low++;
            high--;
        }
    }
    
    string reverseWords(string str) 
    {
        int n=str.size();
        
        string temp;
        
        for(int i=0;i<n;i++)
        {
            if(str[i]!=' ')
            {
                temp.push_back(str[i]);
            }
            
            else
            {
                if(temp.size()>0 && str[i-1]!=' ')
                {
                    temp.push_back(' ');
                }
            }
        }
        
        int index=temp.size()-1;
        
        while(index>=0 && temp[index]==' ')
        {
            temp.pop_back();
            index--;
        }
        
        n=temp.size();

        int low=0;
        
        for(int high=0;high<n;high++)
        {
            if(temp[high]==' ')
            {
                reverse(temp,low,high-1);
                low=high+1;
            }
        }
        
        reverse(temp,low,n-1);
        
        reverse(temp,0,n-1);
        
        return temp;
    }
};
