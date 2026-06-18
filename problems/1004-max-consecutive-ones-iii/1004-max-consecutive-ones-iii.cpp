class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,c=0,maxi=0;
        for(int j=0;j<nums.size();j++)
        {
            if (nums[j]==0)
                c++;
            while(c>k)
            {
                if (nums[i]==0)
                    c--;
                i++;
            }
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};