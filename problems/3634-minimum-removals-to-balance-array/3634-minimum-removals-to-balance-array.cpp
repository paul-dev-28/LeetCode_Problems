class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, max_len = 0;
        for (int right = 0; right < n; ++right) {
            while (nums[right] > (long long)nums[left] * k) {
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return n - max_len;
    }
};