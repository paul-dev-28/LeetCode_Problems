class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int c=1;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if (nums[i]!=nums[i-1])
                c=0;
            if (c<k)
            {
                ans.push_back(nums[i]);
                c++;
            }    
        }
        return ans;
    }
};