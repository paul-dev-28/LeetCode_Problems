class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        short int gcd=0;
        for(int i=1;i<=nums[0];i++)
        {
            if (nums[nums.size()-1]%i==0 && nums[0]%i==0)
                gcd=i;
        }
        return gcd;
    }
};