class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_pos = -k - 1; 
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                
                if (i - last_pos <= k) {
                    return false;
                }
                last_pos = i;
            }
        }
        
        return true;
    }
};