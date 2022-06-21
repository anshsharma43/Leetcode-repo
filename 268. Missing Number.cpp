class Solution {
public:
	
	// XOR solution
	
	int missingNumber(vector<int>& arr) 
    {
        int n=arr.size();
        
        int xor_val=0;
        
        for(int i=0;i<n;i++)
        {
            xor_val^=(i^arr[i]);
        }
        
        return xor_val^n;
    }
	
	// Using maths
	
    /*int missingNumber(vector<int>& arr) 
    {
        int n=arr.size();
        
        int sum=((n+1)*(n))/2;
        int sumarray=accumulate(arr.begin(),arr.end(),0);
        
        return sum-sumarray;
    }*/
};
