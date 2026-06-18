class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=INT_MIN;
        vector<bool> arr;
        for(int i=0;i<candies.size();i++)
        {
            if (candies[i]>maxi)
                maxi=candies[i];
        }
        for(int i=0;i<candies.size();i++)
        {
            if (candies[i]+extraCandies>=maxi)
                arr.push_back(true);
            else
                arr.push_back(false);
        }
        return arr;
    }
};