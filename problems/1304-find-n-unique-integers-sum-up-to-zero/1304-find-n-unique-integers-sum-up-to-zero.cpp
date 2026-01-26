class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> nums;
        if (n%2==1)
        {
            for(int i=(n*(-1)+1)/2;i<=(n-1)/2;i++)
            {
                nums.push_back(i);
            }
        }
        if (n%2==0)
        {
            for(int i=(n*(-1))/2;i<=(n)/2;i++)
            {
                if (i==0)
                    continue;
                nums.push_back(i);
            }
        }
        return nums;
    }
};