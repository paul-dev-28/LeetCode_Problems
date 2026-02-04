class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int c=0,l=0,r=nums.size()-1;
        while(l<r)
        {
            int k1=nums[l]+nums[r];
            if (k1==k)
            {
                c++;
                l++;
                r--;
            }
            else if(k1<k)
                l++;
            else 
                r--;
        }
        
        return c;
    }
};