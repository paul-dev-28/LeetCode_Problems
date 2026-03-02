class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailingZeros.push_back(count);
        }

        int totalSwaps = 0;

        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i;
            int foundIdx = -1;

            for (int j = i; j < n; ++j) {
                if (trailingZeros[j] >= target) {
                    foundIdx = j;
                    break;
                }
            }

            if (foundIdx == -1) return -1;

            for (int j = foundIdx; j > i; --j) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                totalSwaps++;
            }
        }

        return totalSwaps;
    }
};