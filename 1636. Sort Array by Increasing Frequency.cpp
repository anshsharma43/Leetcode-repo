class Solution {
public:
    
    static bool comp(pair<int,int> &p1,pair<int,int> &p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second>p2.second;
        }
        
        else
        {
            return p1.first<p2.first;
        }
    }
    
    vector<int> frequencySort(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<pair<int,int>> temp;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            temp.push_back({it->second,it->first});
        }
        
        sort(temp.begin(),temp.end(),comp);
        
        vector<int> res;
        
        for(int i=0;i<temp.size();i++)
        {
            int count=temp[i].first;
            
            while(count>0)
            {
                res.push_back(temp[i].second);
                count--;
            }
        }
        
        return res;
    }
};
