class Solution {
public:
    string getPermutation(int n, int k) 
    { 
        vector<int> arr;
        
        int fact=1;
        
        for(int i=1;i<n;i++)
        {
            fact*=i;
            arr.push_back(i);
        }
        
        arr.push_back(n);
        
        k--;
        
        string res;
        
        while(true)
        {
            int index=k/fact;
            
            res.append(to_string(arr[index]));
            arr.erase(arr.begin()+index);
                
            if(arr.size()==0)
            {
                break;
            }
            
            k%=fact;
            fact/=arr.size();
        }
        
        return res;
    }
};
