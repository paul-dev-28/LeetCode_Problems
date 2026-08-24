class Solution
{
public:
    int numJewelsInStones(string jewels,string stones)
    {
        bool isJewels[128]={false};
        for(char c:jewels)
            isJewels[c]=true;
        int ans=0;
        for(char c:stones)
        {
            if(isJewels[c])
                ans++;
        }
        return ans;
    }
};