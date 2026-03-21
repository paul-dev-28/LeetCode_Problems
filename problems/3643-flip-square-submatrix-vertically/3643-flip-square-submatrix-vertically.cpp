class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=y;i<y+k;i++)
        {
            int b=x+k-1;
            int t=x;
            while(t<b)
            {
                swap(grid[t][i],grid[b][i]);
                t++;
                b--;
            }
        }
        return grid;
    }
};