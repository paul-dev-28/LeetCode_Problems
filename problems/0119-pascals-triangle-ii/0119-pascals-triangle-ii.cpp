class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        v.push_back({1});
        if (rowIndex==0) 
            return v[0];
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> currentRow;
            currentRow.push_back(1);
            for(int j=1;j<i;j++)
            {
                currentRow.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            currentRow.push_back(1);
            v.push_back(currentRow);
        }
        return v[rowIndex];
    }
};