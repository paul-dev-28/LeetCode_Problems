class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> f;
        for (int num : nums) 
        {
            f[num]++;
        }
        vector<int> unique_vals;
        for (auto const& [val, count] : f) 
        {
            unique_vals.push_back(val);
        }
        sort(unique_vals.begin(), unique_vals.end());
        int n = unique_vals.size();
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                int x = unique_vals[i];
                int y = unique_vals[j];
                if (f[x] != f[y]) 
                {
                    return {x, y};
                }
            }
        }
        return {-1, -1};
    }
};