class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        int n=arr.size();
        
        vector<int> res;
        deque<int> dq;
        
        int i=0,j=0;
        
        while(j<n)
        {
            while(dq.empty() == false && dq.back() < arr[j])
            {
                dq.pop_back();
            }
            
            dq.push_back(arr[j]);
            
            if(j-i+1 < k)
            {
                j++;
            }
            
            else
            {
                res.emplace_back(dq.front());
                
                if(dq.front() == arr[i])
                {
                    dq.pop_front();
                }
                
                i++;
                j++;
            }
        }
        
        return res;
    }
};
