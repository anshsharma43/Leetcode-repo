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
    
    string multiply(string str1, string str2) 
    {
        int n1=str1.size();
        int n2=str2.size();
        
        if(n1<n2)
        {
            return multiply(str2,str1);
        }
        
        if(str1=="0" || str2=="0")
        {
            return "0";
        }
        
        int i=n1-1;
        int j=n2-1;
        
        int count=0;
        
        string res;
        
        for(int i=n2-1;i>=0;i--)
        {
            string temp;
            
            int carry=0;
            
            for(int j=n1-1;j>=0;j--)
            {
                int val=str1[j]-'0';
                
                val*=(str2[i]-'0');
                
                val+=carry;

                carry=val/10;
                val=val%10;
                
                temp.push_back(val+'0');
            }
            
            if(carry>0)
            {   
                temp.push_back(carry+'0');
            }
            
            reverse(temp.begin(),temp.end());
            
            int add=count;
            
            while(add>0)
            {
                temp.push_back('0');
                add--;
            }
            
            res=addStrings(res,temp);
            
            count++;
        }
        
        return res;
    }
};
