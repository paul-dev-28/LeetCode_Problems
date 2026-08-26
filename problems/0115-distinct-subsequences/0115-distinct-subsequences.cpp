class Solution {
public:
    int numDistinct(string s,string t) {
        int n=s.size();
        int m=t.size();

        vector<long long> curr(m+1,0);
        vector<long long> fut(m+1,0);

        fut[m]=1;

        for(int i=n-1;i>=0;i--)
        {
            curr[m]=1;

            for(int j=m-1;j>=0;j--)
            {
                if(s[i]==t[j])
                {
                    if(fut[j+1] > INT_MAX-fut[j])
                        curr[j]=INT_MAX;
                    else
                        curr[j]=fut[j+1]+fut[j];
                }
                else
                {
                    curr[j]=fut[j];
                }
            }

            fut=curr;
        }

        return curr[0];
    }
};