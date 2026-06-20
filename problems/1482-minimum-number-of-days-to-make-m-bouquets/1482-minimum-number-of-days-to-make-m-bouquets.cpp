class Solution {
public:
    int func(int midi, vector<int> v,int k1)
    {
        int c=0,ctr=0;
        for(int i=0;i<v.size();i++)
        {
            if (v[i]<=midi)
            {
                c++;
                if (c==k1)
                {
                    ctr++;
                    c=0;
                }
            }
            
            else
                c=0;
        }
        return ctr;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if (m>(n/k))
            return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=0,ans=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            int bouquet=func(mid,bloomDay,k);
            if (bouquet>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};