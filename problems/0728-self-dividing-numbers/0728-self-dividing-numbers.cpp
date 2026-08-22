class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        int flag=0;
        for(int i=left;i<=right;i++)
        {
            int n=i;
            while(n>0)
            {
                if (n%10==0)
                {
                    flag=1;
                    break;
                }   
                if (i%(n%10)!=0)
                {
                    flag=1;
                    break;
                }
                n/=10;
            }
            if (flag==0)
                v.push_back(i);
            flag=0;
        }
        return v;
    }
};