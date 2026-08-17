class Solution {
public:
    vector<vector<int>> ans;
    int arr[9]={1,2,3,4,5,6,7,8,9};
    void solve(int n,int k,int i,vector<int>& v) {
        if (v.size()==k && n==0)
        {
            ans.push_back(v);
            return;
        }    
        if(n<0 || i==9)
            return;
        if (arr[i]<=n)
        {
            v.push_back(arr[i]);
            solve(n-arr[i],k,i+1,v);
            v.pop_back();
        }   
        solve(n,k,i+1,v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(n,k,0,v);
        return ans;
    }
};