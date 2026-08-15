class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
            {
                int c=i;
                int total=i;
                for(int j=0;j<n/2;j++)
                    {
                        int a=s[(i+j)%n]-'a';
                        int b=s[(i+n-j-1)%n]-'a';
                        total+=min((a-b+26)%26,(b-a+26)%26);
                    }
                mini=min(mini,total);
            }
        return mini;
    }
};