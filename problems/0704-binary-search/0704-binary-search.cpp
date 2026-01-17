class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,u=nums.size()-1;
        int mid=0;
        while(l<=u)
        {
            mid=(u+l)/2;
            if (target<nums[mid]){
                
                u=mid-1;
            }
            else if (target>nums[mid]){
                l=mid+1;

            }
            else if(target==nums[mid])
                return mid;
        }
        return -1;
        
    }
};