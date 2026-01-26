class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
         int k=0,r=0;
        for(int i=1;i<=n;i++)
        {
            int c1=i;
            int c2=n-i;
            while(c1>0)
            {
                r=c1%10;
                if (r==0)
                {
                    k=1;
                    break;
                }    
                c1/=10;
            }
            while(c2>0)
            {
                r=c2%10;
                if (r==0)
                {
                    k=1;
                    break;
                }
                c2/=10;
            }
            
            if (k==0)  
                return {i,(n-i)};
            k=0;
        }
        return {};
    }
};