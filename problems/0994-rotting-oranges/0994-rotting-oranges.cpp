class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),min=0,fo=0;
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)fo++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()&&fo){
            int sz=q.size();
            min++;
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int i=x+dr[k];
                    int j=y+dc[k];
                    if(i>=0&&j>=0&&i<r&&j<c&&grid[i][j]==1){
                        fo--;
                        grid[i][j]=2;
                        q.push({i,j});
                    }
                }
            }
        }
        if(fo)return -1;
        return min;
    }
};