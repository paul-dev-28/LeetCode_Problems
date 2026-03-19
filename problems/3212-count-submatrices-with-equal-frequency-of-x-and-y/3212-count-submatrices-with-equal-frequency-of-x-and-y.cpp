class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> countX(rows, vector<int>(cols, 0));
        vector<vector<int>> countY(rows, vector<int>(cols, 0));
        int validSubmatrices = 0;
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                int currX = (grid[i][j] == 'X');
                int currY = (grid[i][j] == 'Y');

                if (i > 0) 
                {
                    currX += countX[i - 1][j];
                    currY += countY[i - 1][j];
                }
                if (j > 0) 
                {
                    currX += countX[i][j - 1];
                    currY += countY[i][j - 1];
                }
                if (i > 0 && j > 0) 
                {
                    currX -= countX[i - 1][j - 1];
                    currY -= countY[i - 1][j - 1];
                }
                countX[i][j] = currX;
                countY[i][j] = currY;
                if (currX > 0 && currX == currY) 
                {
                    validSubmatrices++;
                }
            }
        }
        return validSubmatrices;
    }
};