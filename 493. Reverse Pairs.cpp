class Solution {
public:
    
    int helperMerge(vector<int> &arr,int l,int m,int r)
    {
        int res=0;
        
        int n1=m-l+1;
        int n2=r-m;
        
        int left[n1];
        int right[n2];
        
        for(int i=0;i<n1;i++)
        {
            left[i]=arr[i+l];
        }
        
        for(int i=0;i<n2;i++)
        {
            right[i]=arr[i+m+1];
        }
        
        int i=0,j=0,k=l;
        
        while(i<n1 && j<n2)
        {
            if((long)left[i] <= (long)2*right[j]) //or if(left[i]/2.0 <= right[j])
            {
                i++;
            }
            
            else if((long)left[i] > (long)2*right[j]) //or else if(left[i]/2.0 > right[j])
            {
                res+=n1-i;
                j++;
            }
        }
        
        i=0,j=0;
        
        while(i<n1 && j<n2)
        {
            if(left[i] <= right[j])
            {
                arr[k]=left[i];
                i++;
            }
            
            else
            {
                arr[k]=right[j];
                j++;
            }
            
            k++;
        }
        
        while(i<n1)
        {
            arr[k]=left[i];
            k++;
            i++;
        }
        
        while(j<n2)
        {
            arr[k]=right[j];
            k++;
            j++;
        }
        
        return res;
    }
    
    int helper(vector<int> &arr,int l,int r)
    {
        int res=0;
        
        if(l<r)
        {
            int m=l + (r-l)/2;
            res+=helper(arr,l,m);
            res+=helper(arr,m+1,r);
            res+=helperMerge(arr,l,m,r);
        }
        
        return res;
    }
    
    int reversePairs(vector<int>& arr) 
    {
        int n=arr.size();
        
        int res=helper(arr,0,n-1);
        
        return res;
    }
};
