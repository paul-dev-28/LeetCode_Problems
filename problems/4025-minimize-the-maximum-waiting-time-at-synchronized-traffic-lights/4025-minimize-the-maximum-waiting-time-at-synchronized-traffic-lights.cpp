class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int c=*max_element(lights.begin(),lights.end());
        int p=0;
        for(int i=0;i<arrivalTime.size();i++)
            {
                int r=arrivalTime[i]%period;
                if (r>=c)
                    p=max(p,period-r);
            }
        return p;
    }
};