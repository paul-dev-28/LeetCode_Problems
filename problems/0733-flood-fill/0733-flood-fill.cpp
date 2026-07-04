class Solution {
public:
    void dfs(int i,int j,int color,int org,vector<vector<int>>& image)
    {
        int n=image.size();
        int m=image[0].size();
        if(i<0 || i>=n || j<0 || j>=m)
            return;
        if(image[i][j]!=org)
            return;
        image[i][j]=color;
        dfs(i+1,j,color,org,image);
        dfs(i-1,j,color,org,image);
        dfs(i,j+1,color,org,image);
        dfs(i,j-1,color,org,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org=image[sr][sc];
        if(org==color)
            return image;
        dfs(sr,sc,color,org,image);
        return image;
    } 
};