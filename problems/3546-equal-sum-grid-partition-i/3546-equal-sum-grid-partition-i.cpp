class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return false;
        int n = grid[0].size();

        long long totalSum = 0;
        for (const auto& row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }

        if (totalSum % 2 != 0) return false;
        long long target = totalSum / 2;

        long long horizontalRunningSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                horizontalRunningSum += grid[i][j];
            }
            if (horizontalRunningSum == target) return true;
        }

        long long verticalRunningSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                verticalRunningSum += grid[i][j];
            }
            if (verticalRunningSum == target) return true;
        }

        return false;
    }
};