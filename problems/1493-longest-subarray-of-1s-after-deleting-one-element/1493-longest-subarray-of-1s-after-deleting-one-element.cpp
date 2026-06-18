class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,c=0,maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)
                c++;
            while(c>1)
            {
                if (nums[j]==0)
                    c--;
                j++;
            }
            maxi=max(maxi,i-j+1);
        }
        return maxi-1;
    }
};