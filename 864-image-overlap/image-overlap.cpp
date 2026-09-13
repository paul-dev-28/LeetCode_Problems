class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> a,b;
        int n=img1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j])
                    a.push_back({i,j});
                if(img2[i][j])
                    b.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        int ans=0;
        for(auto [x1,y1]:a)
        {
            for(auto [x2,y2]:b)
            {
                pair<int,int> shift={x2-x1,y2-y1};
                ans=max(ans,++mp[shift]);
            }
        }
        return ans;
    }
};