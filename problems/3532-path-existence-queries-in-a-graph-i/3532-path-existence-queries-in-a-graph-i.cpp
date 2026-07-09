class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n);
        for(int i=1;i<n;i++)
        {
            comp[i]=comp[i-1];
            if(nums[i]-nums[i-1]>maxDiff)
                comp[i]++;
        }
        vector<bool> ans;
        for(auto &v:queries)
            ans.push_back(comp[v[0]]==comp[v[1]]);
        return ans;
    }
};