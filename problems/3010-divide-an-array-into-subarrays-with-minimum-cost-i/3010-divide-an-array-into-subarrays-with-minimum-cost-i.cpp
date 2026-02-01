class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first_cost = nums[0];
        
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < min1) {
                
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
               
                min2 = nums[i];
            }
        }
        
        return first_cost + min1 + min2;
    }
};