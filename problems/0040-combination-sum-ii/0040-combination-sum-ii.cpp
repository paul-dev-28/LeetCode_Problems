class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates,int target,int i,vector<int>& v)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(target<0||i==candidates.size())
            return;
        for(int j=i;j<candidates.size();j++)
        {
            if(j>i&&candidates[j]==candidates[j-1])
                continue;
            if(candidates[j]>target)
                break;
            v.push_back(candidates[j]);
            solve(candidates,target-candidates[j],j+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates,int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        solve(candidates,target,0,v);
        return ans;
    }
};