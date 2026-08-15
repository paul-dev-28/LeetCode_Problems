class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total=0;
        total+=requests[0];
        for(int i=1;i<requests.size();i++)
            {
                if (requests[i]!=requests[i-1])
                    total+=abs(requests[i]-requests[i-1]);
                
            }
        return total;
    }
};