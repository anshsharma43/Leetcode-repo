class Solution {
public:
    string intToRoman(int n) 
    {
        string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        string res;
        
        for(int i=0;i<13 && n!=0;i++)
        {
            while(n>=value[i])
            {
                res.append(symbol[i]);
                n-=value[i];
            }
        }
        
        return res;
    }
};
