class Solution {
public:
	
	// Naive method - Min Heap - TC: O(nlogk)
	
    /*vector<int> topKFrequent(vector<int>& arr, int k) 
    {
        int n=arr.size();
        
        vector<int> res;
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> min_heap;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            min_heap.push({it->second,it->first});
            
            if(min_heap.size()>k)
            {
                min_heap.pop();
            }
        }
        
        while(min_heap.empty()==false)
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return res;
    }*/
    
    // Better method - Bucket Sort - TC: O(n)
    
    vector<int> topKFrequent(vector<int>& arr, int k) 
    {
        int n=arr.size();
        
        if(k==n)
        {
            return arr;
        }
        
        vector<int> res;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> bucketSort[n+1];
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            bucketSort[it->second].push_back(it->first);
        }
        
        int count=k;
        
        for(int i=n;i>=0;i--)
        {
            
            if(bucketSort[i].size()!=0)
            {
                for(int x:bucketSort[i])
                {
                    res.push_back(x);
                }
                
                count--;
            }
            
            if(count==0)
            {
                break;
            } 
        }
        
        count=0;
        
        vector<int> finalRes;
        
        for(int i=0;i<k;i++)
        {
            finalRes.push_back(res[count]);
            count++;
        }
        
        return finalRes;
    }
    
};
