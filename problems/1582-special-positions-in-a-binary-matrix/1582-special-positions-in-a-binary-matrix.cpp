class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int c=0,ctr=0,pos=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if (mat[i][j]==1)
                {
                    pos=j;
                    c++;
                }
                if (c>1)
                    break;
            }
            if (c==1)
            {
                c=0;
                for(int j=0;j<mat.size();j++)
                {
                    if (mat[j][pos]==1)
                    {
                        c++;
                    }
                    if (c>1)
                        break;
                }
            }
            if (c==1)
                ctr++;
            c=0;
        }
        return ctr;
    }
};