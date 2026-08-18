class Solution {
public:
    int m,n;
    bool solve(vector<vector<char>>& board,string& word,int i,int r,int c)
    {
        if(i==word.size())
            return true;
        if(r<0||r>=m||c<0||c>=n||board[r][c]!=word[i])
            return false;
        char x=board[r][c];
        board[r][c]='#';
        bool ans=solve(board,word,i+1,r+1,c)||
                 solve(board,word,i+1,r-1,c)||
                 solve(board,word,i+1,r,c+1)||
                 solve(board,word,i+1,r,c-1);
        board[r][c]=x;
        return ans;
    }
    bool exist(vector<vector<char>>& board,string word)
    {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0]&&solve(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};