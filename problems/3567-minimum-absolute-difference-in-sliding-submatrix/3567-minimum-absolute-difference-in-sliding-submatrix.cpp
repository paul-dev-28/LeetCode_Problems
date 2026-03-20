class Solution {
public:
    int getMinDiff(const set<int>& uniqueVals) {
        if (uniqueVals.size() <= 1) 
            return 0;

        int minDiff = INT_MAX;
        auto it = uniqueVals.begin();
        auto prev = it;
        it++;

        while (it != uniqueVals.end()) 
        {
            minDiff = min(minDiff, *it - *prev);
            if (minDiff == 1) 
                return 1; 
            prev = it;
            it++;
        }

        return minDiff;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int row_res = m - k + 1;
        int col_res = n - k + 1;
        vector<vector<int>> ans(row_res, vector<int>(col_res));

        for (int i = 0; i < row_res; ++i) 
        {
            map<int, int> freq;
            set<int> uniqueVals;
            
            auto add = [&](int val) 
            {
                freq[val]++;
                uniqueVals.insert(val);
            };
            
            auto remove = [&](int val) 
            {
                if (--freq[val] == 0) {
                    uniqueVals.erase(val);
                }
            };

            for (int r = i; r < i + k; ++r) 
            {
                for (int c = 0; c < k; ++c) 
                {
                    add(grid[r][c]);
                }
            }
            ans[i][0] = getMinDiff(uniqueVals);

            for (int j = 1; j < col_res; ++j) 
            {
                for (int r = i; r < i + k; ++r) 
                {
                    remove(grid[r][j - 1]);
                    add(grid[r][j + k - 1]);
                }
                ans[i][j] = getMinDiff(uniqueVals);
            }
        }
        return ans;
    }
};