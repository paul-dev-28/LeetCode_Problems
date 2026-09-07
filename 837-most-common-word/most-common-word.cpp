class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>st;
        for(string s:banned)
            st.insert(s);
        unordered_map<string,int>mp;
        string s="";
        for(char c:paragraph)
        {
            if(isalpha(c))
                s+=tolower(c);
            else
            {
                if(!s.empty() && !st.count(s))
                    mp[s]++;
                s="";
            }
        }
        if(!s.empty() && !st.count(s))
            mp[s]++;
        string ans="";
        int mx=0;
        for(auto [s,c]:mp)
        {
            if(c>mx)
            {
                mx=c;
                ans=s;
            }
        }
        return ans;
    }
};