class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>newNum=nums;

        for(int i=0;i<nums.size();i++){
            int newIndex=(i+k)%nums.size();
            newNum[newIndex]=nums[i];
        }
        nums=newNum;
    }
};