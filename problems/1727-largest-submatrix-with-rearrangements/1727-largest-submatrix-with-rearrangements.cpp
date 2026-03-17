class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
     int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            std::vector<int> heights = matrix[i];
            std::sort(heights.begin(), heights.end(), std::greater<int>());

            for (int j = 0; j < n; ++j) {
                if (heights[j] == 0) break;
                
                int width = j + 1;
                maxArea = std::max(maxArea, heights[j] * width);
            }
        }

        return maxArea;
    }
};