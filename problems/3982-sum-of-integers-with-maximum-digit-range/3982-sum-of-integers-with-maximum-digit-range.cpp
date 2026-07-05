class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int max=-1,sum=0;
        for(int i=0;i<nums.size();i++)
            {
                int n=nums[i];
                int mind=9;
                int maxd=0;
                if (n==0)
                {
                    mind=0;
                    maxd=0;
                }
                while(n!=0)
                    {
                        if (n%10<mind)
                            mind=n%10;
                        if (n%10>maxd)
                            maxd=n%10;
                        n/=10;
                    }
                int d=maxd-mind;
                if (d>max)
                {
                    sum=nums[i];
                    max=d;
                }
                else if (d==max)
                    sum+=nums[i];
            }
        return sum;
    }
};