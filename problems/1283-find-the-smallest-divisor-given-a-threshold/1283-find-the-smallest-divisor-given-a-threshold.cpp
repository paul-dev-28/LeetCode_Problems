class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int mid=0,total=0,ans=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            for(int i=0;i<nums.size();i++)
            {
                total+=ceil((double(nums[i])/(double)mid));
            }
            if (total<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
            total=0;
        }
        return ans;
    }
};