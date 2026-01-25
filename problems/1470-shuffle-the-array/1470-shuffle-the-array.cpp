class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> temp;
        int c=0;
        for(int i=n;i<2*n;i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i=0;i<2*n;i+=2)
        {
            nums.insert(nums.begin()+i+1,temp[c]);
            nums.erase(nums.end());
            c++;
        }
        return nums;
    }
};