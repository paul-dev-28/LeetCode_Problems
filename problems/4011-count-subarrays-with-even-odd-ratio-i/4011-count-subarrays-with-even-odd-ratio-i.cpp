class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int even=0,odd=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if (nums[j]%2==0)
                    even++;
                else
                    odd++;
                if (odd>0 && (1LL*even*b)<=(1LL*odd*a))
                    c++;
            }
            even=0;
            odd=0;
        }
        return c;
    }
};