class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int m=nums[nums.size()/2];
        int c=0;
        for(int i=0;i<nums.size();i++)
            {
                if (nums[i]==m)
                    c++;
            }
        return (c==1);
    }
};