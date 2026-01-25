class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int duplicate = -1, missing = -1;

    for (int i = 0; i < nums.size(); i++) {
        int val = std::abs(nums[i]);
        if (nums[val - 1] < 0) {
            duplicate = val;
        } else {
            nums[val - 1] *= -1;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            missing = i + 1;
        }
    }

    return {duplicate, missing};
}
};