class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector<int> l(n),r(n);
        int j=0;
        for(int i=0;i<n;i++)
            {
                while(station[j]!=skill[i])
                    {
                        j++;
                    }
                l[i]=j++;
            }
        j=m-1;
        for(int i=n-1;i>=0;i--)
            {
                while(station[j]!=skill[i])
                    j--;
                r[i]=j--;
            }
        int a=0;
        for(int i=0;i<n-1;i++)
        {
            a=max(a,r[i+1]-l[i]);
        }
        return a;
    }
};