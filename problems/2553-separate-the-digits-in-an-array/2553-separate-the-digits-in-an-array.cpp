class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(nums[i]>0)
            {
                int digit=nums[i]%10;
                digits.push_back(digit);
                nums[i]/=10;
            }
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};