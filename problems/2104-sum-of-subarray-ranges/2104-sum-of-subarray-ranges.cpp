class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> pl(n),nl(n),pg(n),ng(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            pl[i]=st.empty()?i+1:i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            nl[i]=st.empty()?n-i:st.top()-i;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            pg[i]=st.empty()?i+1:i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            ng[i]=st.empty()?n-i:st.top()-i;
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
            ans+=1LL*nums[i]*pg[i]*ng[i]-1LL*nums[i]*pl[i]*nl[i];
        return ans;
    }
};