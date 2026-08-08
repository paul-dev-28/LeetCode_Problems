class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums,int k)
    {
        unordered_map<int,int> mpp;
        for(int x:nums)
            mpp[x]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto [x,f]:mpp)
            bucket[f].push_back(x);
        vector<int> ans;
        for(int f=nums.size();f>=1&&ans.size()<k;f--)
        {
            for(int x:bucket[f])
            {
                ans.push_back(x);
                if(ans.size()==k)
                    break;
            }
        }
        return ans;
    }
};