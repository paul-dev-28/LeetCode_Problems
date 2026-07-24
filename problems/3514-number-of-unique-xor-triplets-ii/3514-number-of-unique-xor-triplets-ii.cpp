class Solution
{
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        vector<int> vals;
        vector<int> vis(2048);
        for(int x:nums)
        {
            if(!vis[x])
            {
                vis[x]=1;
                vals.push_back(x);
            }
        }
        vector<int> two(2048),three(2048);
        for(int a:vals)
        {
            for(int b:vals)
                two[a^b]=1;
        }
        for(int x=0;x<2048;x++)
        {
            if(!two[x])
                continue;

            for(int a:vals)
                three[x^a]=1;
        }
        int ans=0;
        for(int x:three)
            ans+=x;

        return ans;
    }
};