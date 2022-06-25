class Solution {
public:
	
	// Better - One traversal
	
	int maxProduct(vector<int>& arr) 
    {
        int n=arr.size();
        
        int result=arr[0];
        int max_product=arr[0];
        int min_product=arr[0];
        
        for(int i=1;i<n;i++)
        {
            int temp=max({arr[i],max_product*arr[i],min_product*arr[i]});
            min_product=min({arr[i],max_product*arr[i],min_product*arr[i]});
            max_product=temp;
            
            result=max(result,max_product);
        }
        
        return result;
    }
	
	// Naive: Two traversals
	
    /*int maxProduct(vector<int>& arr) 
    {
        int n=arr.size();
        
        int product=1;
        
        int max_left=arr[0];
        int max_right=arr[n-1];
        
        bool isZero=false;
        
        for(int i=0;i<n;i++)
        {
            product*=arr[i];
            
            if(arr[i]==0)
            {
                product=1;
                isZero=true;
                continue;
            }
            
            max_left=max(max_left,product);
        }
        
        product=1;
        
        for(int i=n-1;i>=0;i--)
        {
            product*=arr[i];
            
            if(arr[i]==0)
            {
                product=1;
                isZero=true;
                continue;
            }
            
            max_right=max(max_right,product);
        }
        
        return isZero==false?max(max_left,max_right):max({max_left,max_right,0});
    }*/
};
