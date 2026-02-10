class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxLength=0;
        int n=nums.size();

        for (int i=0;i<n;++i)
        {
            unordered_set<int> distinctEvens;
            unordered_set<int> distinctOdds;

            for (int j=i;j<n;++j) 
            {
                if (nums[j]%2==0) 
                {
                    distinctEvens.insert(nums[j]);
                } else 
                {
                    distinctOdds.insert(nums[j]);
                }

                if (distinctEvens.size()==distinctOdds.size()) 
                {
                    maxLength=max(maxLength,j-i+1);
                }
            }
        }

        return maxLength;
    }
};