class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int c=0;
        vector<int> v;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if (matrix[i][j]==1)
                    c++;
            }
            v.push_back(c);
            c=0;
        }
        return v;
    }
};