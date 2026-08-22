class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> cnt(n,0);
        vector<int> ans;
        for(int x:nums)
            cnt[x]++;
        for(int i=0;i<n;i++)
        {
            if(cnt[i]==2)
                ans.push_back(i);
        }
        return ans;
    }
};