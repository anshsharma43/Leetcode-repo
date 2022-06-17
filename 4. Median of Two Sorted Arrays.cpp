class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) 
    {
        int n1=arr1.size();
        int n2=arr2.size();
        
        if(n2<n1)
        {
            return findMedianSortedArrays(arr2,arr1);
        }
        
        bool oddIndexed;
        
        if((n1+n2)%2==1)
        {
            oddIndexed=true;
        }
        
        else
        {
            oddIndexed=false;
        }
        
        int low=0;
        int high=n1;
        
        while(low<=high)
        {
            int mid1=low + (high-low)/2;
            int mid2=(n1+n2+1)/2-mid1;
            
            int l1=mid1==0?INT_MIN:arr1[mid1-1];
            int l2=mid2==0?INT_MIN:arr2[mid2-1];
            
            int r1=mid1==n1?INT_MAX:arr1[mid1];
            int r2=mid2==n2?INT_MAX:arr2[mid2];
            
            if(l1<=r2 && l2<=r1)
            {
                if(oddIndexed==true)
                {
                    return max(l1,l2);
                }
                
                else
                {
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            
            else if(l1>r2)
            {
                high=mid1-1;
            }
            
            else
            {
                low=mid1+1;
            }
        }
        
        return 0.0;
    }
};
