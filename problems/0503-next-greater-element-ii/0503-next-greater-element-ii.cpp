class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> nge;
        for(int i=2*nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i%nums.size()])
                st.pop();
            if (i<nums.size()){
            if (st.empty())
                nge.push_back(-1);
            else
                nge.push_back(st.top());}
            st.push(nums[i%nums.size()]);
        }
        reverse(nge.begin(), nge.end());
        return nge;
    }
};