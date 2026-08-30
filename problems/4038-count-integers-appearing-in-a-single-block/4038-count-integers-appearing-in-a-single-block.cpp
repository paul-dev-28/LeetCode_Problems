class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> l;
        unordered_set<int>  b;
        for(int i=0;i<nums.size();i++)
            {
                if (l.count(nums[i]) && l[nums[i]]!=i-1)
                    b.insert(nums[i]);
                l[nums[i]]=i;
            }
        return l.size()-b.size();
    }
};