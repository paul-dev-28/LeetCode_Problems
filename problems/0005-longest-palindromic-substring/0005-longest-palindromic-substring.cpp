class Solution {
public:
    string longestPalindrome(string s) {
        string t="#";
        for(char c:s)
        {
            t+=c;
            t+="#";
        }
        int n=t.size(),center=0,right=0,start=0,len=0;
        vector<int> p(n);
        for(int i=0;i<n;i++)
        {
            int mir=2*center-i;
            if(i<right)
                p[i]=min(right-i,p[mir]);
            while(i+p[i]+1<n && i-p[i]-1>=0 && t[i+p[i]+1]==t[i-p[i]-1])
                p[i]++;
            if(i+p[i]>right)
            {
                center=i;
                right=i+p[i];
            }
            if(p[i]>len)
            {
                len=p[i];
                start=(i-p[i])/2;
            }
        }
        return s.substr(start,len);
    }
};