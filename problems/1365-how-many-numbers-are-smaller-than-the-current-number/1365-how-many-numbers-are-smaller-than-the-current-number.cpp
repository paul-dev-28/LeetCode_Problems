class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> num;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if ((nums[i]!=nums[j]) && (nums[j]<nums[i]))
                    c++;
            }
            num.push_back(c);
            c=0;
        }
        return num;
    }
};