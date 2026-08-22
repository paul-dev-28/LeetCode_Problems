class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]%6==0)
            {
                total+=nums[i];
                c++;
            }
        }
        if (c==0)
            return 0;
        return (total/c);
    }
};