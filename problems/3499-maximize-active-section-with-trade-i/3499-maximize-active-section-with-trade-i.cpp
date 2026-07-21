class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones=0;
        for(char c:s)
            ones+=(c=='1');
        string t="1"+s+"1";
        vector<pair<char,int>> v;
        for(char c:t)
        {
            if(v.empty() || v.back().first!=c)
                v.push_back({c,1});
            else
                v.back().second++;
        }
        int add=0;
        for(int i=1;i+1<v.size();i++)
        {
            if(v[i].first=='1' && v[i-1].first=='0' && v[i+1].first=='0')
                add=max(add,v[i-1].second+v[i+1].second);
        }
        return ones+add;
    }
};