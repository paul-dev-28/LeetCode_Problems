class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        vector<int> v;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(nums[i],maxi);
            mini=min(nums[i],mini);
            st.insert(nums[i]);
        }
        for(int i=mini;i<=maxi;i++)
        {
            if (st.find(i)==st.end())
                v.push_back(i);
        }
        sort(v.begin(),v.end());
        return v;
    }
};