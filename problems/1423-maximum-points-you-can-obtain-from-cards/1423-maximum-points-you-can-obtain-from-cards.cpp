class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long l=0LL,r=0LL,maxsum=0LL;
        int c=1;
        for(int i=0;i<k;i++)
            l+=cardPoints[i];
        maxsum=l;
        for(int i=k-1;i>=0;i--)
        {
            l-=cardPoints[i];
            r+=cardPoints[cardPoints.size()-c];
            maxsum=max(maxsum,(l+r));
            c++;
        }
        return maxsum;
    }
};