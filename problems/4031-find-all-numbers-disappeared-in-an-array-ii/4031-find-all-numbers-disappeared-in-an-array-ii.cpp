class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        long long p=(long long)lower-1;
        long long c=0LL;
        for(int i=0;i<=nums.size();i++)
            {
                if (i==nums.size())
                    c=(long long)upper+1;
                else if (nums[i]>upper)
                    c=(long long)upper+1;
                else if (nums[i]<lower)
                    continue;
                else
                    c=nums[i];
                if (c-p>=2)
                    v.push_back({(int)p+1,(int)c-1});
                p=c;
                if (c==upper+1)
                    break;
            }
        return v;
    }
};