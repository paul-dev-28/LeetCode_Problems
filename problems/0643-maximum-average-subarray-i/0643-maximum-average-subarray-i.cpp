class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        double avg=0.0;
        for(int a=0;a<k;a++)
            avg+=(double)nums[a]/k;
        double maxi=avg;
        while(i+k<nums.size())
        {
            avg=avg+(double)nums[i+k]/k;
            avg=avg-(double)nums[i]/k;
            maxi=max(maxi,avg);
            i++;
        }
        return maxi;
    }
};