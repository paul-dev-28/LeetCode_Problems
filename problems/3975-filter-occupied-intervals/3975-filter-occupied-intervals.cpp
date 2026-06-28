class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>> m;
        for(int i=0;i<occupiedIntervals.size();i++)
            {
                if (m.empty() || occupiedIntervals[i][0]>m.back()[1]+1)
                    m.push_back(occupiedIntervals[i]);
                else
                    m.back()[1]=max(m.back()[1],occupiedIntervals[i][1]);
                
            }
        vector<vector<int>> ans;
        for(int i=0;i<m.size();i++)
            {
                int l=m[i][0];
                int r=m[i][1];
                if (r<freeStart || l>freeEnd)
                {
                    ans.push_back({l,r});
                    continue;
                }
                if(l<freeStart)
                    ans.push_back({l,freeStart-1});
                if (r>freeEnd)
                    ans.push_back({freeEnd+1,r});
            }
        return ans;
        }
};