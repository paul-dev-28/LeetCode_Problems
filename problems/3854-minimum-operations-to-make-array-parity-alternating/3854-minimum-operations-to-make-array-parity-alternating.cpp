class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<int> m = nums; 
        if (n <= 1) return {0, 0};

        auto solve = [&](int startParity) -> pair<long long, int> {
            long long ops = 0;
            vector<pair<int, int>> candidates;

            for (int i = 0; i < n; ++i) {
                int targetParity = (startParity + i) % 2;
                if (abs(nums[i] % 2) == targetParity) {
                    candidates.push_back({nums[i], i});
                } else {
                    ops++;
                    candidates.push_back({nums[i] - 1, i});
                    candidates.push_back({nums[i] + 1, i});
                }
            }

            sort(candidates.begin(), candidates.end());

            int minRange = 2e9;
            vector<int> freq(n, 0);
            int count = 0;
            int left = 0;

            for (int right = 0; right < candidates.size(); ++right) {
                if (freq[candidates[right].second]++ == 0) count++;

                while (count == n) {
                    minRange = min(minRange, candidates[right].first - candidates[left].first);
                    if (--freq[candidates[left].second] == 0) count--;
                    left++;
                }
            }
            return {ops, minRange};
        };

        auto res0 = solve(0);
        auto res1 = solve(1);

        if (res0.first < res1.first) return {(int)res0.first, res0.second};
        if (res1.first < res0.first) return {(int)res1.first, res1.second};
        return {(int)res0.first, min(res0.second, res1.second)};
    }
};