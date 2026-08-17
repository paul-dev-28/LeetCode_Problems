class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates,int target,int i,vector<int>& v)
    {
        if (i==candidates.size())
        {
            if(target==0)
                ans.push_back(v);
            return;
        }
        if (candidates[i]<=target)
        {
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i,v);
            v.pop_back();
        }   
        solve(candidates,target,i+1,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target)
    {
        vector<int> v;
        solve(candidates,target,0,v);
        return ans;
    }
};