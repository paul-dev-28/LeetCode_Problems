class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        long long res=1;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> row;
            row.push_back(1);
            for(int j=1;j<i;j++)
            {
                res*=(i-j);
                res/=j;
                row.push_back(res);
            }
            ans.push_back(row);
            res=1;
        }
        return ans;
    }
};