class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalapples=0;
        for(int i=0;i<apple.size();i++)
            totalapples+=apple[i];
        sort(capacity.begin(),capacity.end(),greater<int>());
        int boxesUsed = 0;
        for (int cap : capacity) {
            totalapples -= cap;
            boxesUsed++;
            if (totalapples <= 0) {
                return boxesUsed;
            }
        }
        
        return boxesUsed;
    }
};