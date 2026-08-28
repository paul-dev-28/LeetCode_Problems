class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>cnt(1001,0);
        for(int x:arr1)
            cnt[x]++;
        vector<int>ans;
        for(int x:arr2)
        {
            while(cnt[x])
            {
                ans.push_back(x);
                cnt[x]--;
            }
        }
        for(int i=0;i<=1000;i++)
        {
            while(cnt[i])
            {
                ans.push_back(i);
                cnt[i]--;
            }
        }
        return ans;
    }
};