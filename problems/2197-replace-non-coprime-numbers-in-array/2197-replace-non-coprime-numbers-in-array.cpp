class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int j=0;
        for (int i=0;i<nums.size();i++)
        {
            nums[j]=nums[i];
            while(j>0)
            {
                int hcf=gcd(nums[j],nums[j-1]);
                if (hcf>1)
                {
                    nums[j-1]=(1LL*nums[j]*nums[j-1])/hcf;
                    j--;
                }
                else
                    break;
            }
            j++;
        }
        nums.resize(j);
        return nums;
    }
};