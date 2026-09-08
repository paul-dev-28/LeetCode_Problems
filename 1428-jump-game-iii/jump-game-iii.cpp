class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n);
        function<bool(int)>dfs=[&](int i) {
            if(i<0 || i>=n || vis[i])
                return false;
            if(arr[i]==0)
                return true;
            vis[i]=1;
            return dfs(i+arr[i]) || dfs(i-arr[i]);
        };
        return dfs(start);
    }
};