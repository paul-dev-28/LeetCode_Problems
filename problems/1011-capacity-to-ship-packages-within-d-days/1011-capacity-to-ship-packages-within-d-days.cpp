class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end()),high=0,mid=0,ans=0,c=0,total=0;
        for(int i=0;i<weights.size();i++)
            high+=weights[i];
        while(low<=high)
        {
            mid=low+(high-low)/2;
            c=1;
            total=0;
            for(int i=0;i<weights.size();i++)
            {
                total+=weights[i];
                if (total>mid)
                {
                    c++;
                    total=weights[i];
                }
                if (c>days)
                    break;
            }
            if (c<=days)
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