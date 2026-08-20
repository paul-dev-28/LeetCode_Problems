class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        int i=2;
        while(i<nums.size())
        {
            if (v1.back()>v2.back())
                v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
            i++;
        }
        i=0;
        while(i<v2.size())
        {
            v1.push_back(v2[i]);
            i++;
        }
        return v1;
    }
};