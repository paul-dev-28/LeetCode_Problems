class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int c=-1,mini=INT_MAX;
        for(int i=0;i<drones.size();i++)
            {
                int dist=(abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]));
                if (dist<=drones[i][2])
                {
                    if (dist<mini)
                    {
                        mini=dist;
                        c=i;
                    }
                }
            }
        return c;
    }
};