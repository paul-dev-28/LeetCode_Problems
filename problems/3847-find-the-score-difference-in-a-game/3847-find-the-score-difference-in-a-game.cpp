class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        long long score1 = 0, score2 = 0;
        bool p1IsActive = true; 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                p1IsActive = !p1IsActive;
            }

            if ((i + 1) % 6 == 0) {
                p1IsActive = !p1IsActive;
            }
            if (p1IsActive) {
                score1 += nums[i];
            } else {
                score2 += nums[i];
            }
        }

        return (int)(score1 - score2);
    }
};