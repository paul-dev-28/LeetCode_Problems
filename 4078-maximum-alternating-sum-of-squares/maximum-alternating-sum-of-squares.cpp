class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            nums[i]=abs(nums[i]);
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        long long total=0LL;
        while(i<=j)
        {
            if (i==j)
            {
                total+=1LL*nums[j]*nums[j];
                break;
            } 
            total+=1LL*nums[j]*nums[j];
            total-=1LL*nums[i]*nums[i];
            i++;
            j--; 
        }
        return total;
    }
};