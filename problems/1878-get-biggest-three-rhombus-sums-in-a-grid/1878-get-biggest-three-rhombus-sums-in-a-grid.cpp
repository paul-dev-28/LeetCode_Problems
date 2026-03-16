class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> sums;

        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                sums.insert(grid[i][j]);
                for (int k=1;i-k>=0 && i+k<m && j-k>=0 && j+k<n;k++) 
                {
                    int s = 0;
                    for (int x = 0; x < k; ++x) 
                    {
                        s += grid[i - k + x][j + x];
                        s += grid[i + x][j + k - x];
                        s += grid[i + k - x][j - x];
                        s += grid[i - x][j - k + x];
                    }
                    sums.insert(s);
                }
            }
        }
        vector<int> res;
        auto it = sums.begin();
        for (int i = 0; i < 3 && it != sums.end(); ++i, ++it) 
            res.push_back(*it);
        return res;
    }
};