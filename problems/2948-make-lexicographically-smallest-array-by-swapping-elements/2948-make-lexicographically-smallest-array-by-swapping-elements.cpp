class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums,int limit) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        vector<int> ans=nums;
        int i=0;
        while(i<n)
        {
            int j=i;
            while(j+1<n && v[j+1].first-v[j].first<=limit)
                j++;
            vector<int>val;
            vector<int>idx;
            for(int k=i;k<=j;k++)
            {
                val.push_back(v[k].first);
                idx.push_back(v[k].second);
            }
            sort(idx.begin(),idx.end());
            for(int k=0;k<val.size();k++)
                ans[idx[k]]=val[k];
            i=j+1;
        }
        return ans;
    }
};