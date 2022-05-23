class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if(numRows==1)
        {
            return {{1}};
        }
        
        vector<vector<int>> arr;
        
        arr.push_back({1});
        arr.push_back({1,1});
        
        for(int i=2;i<numRows;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            
            int size=arr[i-1].size();
            
            for(int index=1;index<size;index++)
            {
                temp.push_back(arr[i-1][index] + arr[i-1][index-1]);
            }
            
            temp.push_back(1);
            
            arr.push_back(temp);
        }
        
        return arr;
    }
};
