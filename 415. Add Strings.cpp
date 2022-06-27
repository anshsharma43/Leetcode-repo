class Solution {
public:
    string addStrings(string str1, string str2) 
    {
        int n1=str1.size();
        int n2=str2.size();
        
        int i=n1-1;
        int j=n2-1;
        
        int carry=0;
        
        string res;
        
        while(i>=0 || j>=0 || carry==1)
        {
            int val=0;
            
            if(i>=0)
            {
                val+=str1[i]-'0';
            }
            
            if(j>=0)
            {
                val+=str2[j]-'0';
            }
            
            if(carry==1)
            {
                val+=carry;
            }
            
            carry=val/10;
            val=val%10;
            
            res.push_back(val+'0');
            
            i--;
            j--;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
