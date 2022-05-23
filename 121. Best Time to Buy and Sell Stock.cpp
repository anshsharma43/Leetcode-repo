class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int n=arr.size();
        
        int minPrice=INT_MAX;
        int maxProfit=0;
        
        for(int i=0;i<n;i++)
        {
            minPrice=min(minPrice,arr[i]);
            maxProfit=max(maxProfit,arr[i]-minPrice);
        }
        
        return maxProfit;
    }
};
