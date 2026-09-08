class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size(),m=words.size(),len=words[0].size();
        unordered_map<string,int>need;
        for(string w:words)
            need[w]++;
        vector<int>ans;
        for(int st=0;st<len;st++)
        {
            int l=st,cnt=0;
            unordered_map<string,int>have;
            for(int r=st;r+len<=n;r+=len)
            {
                string w=s.substr(r,len);
                if(!need.count(w))
                {
                    have.clear();
                    cnt=0;
                    l=r+len;
                    continue;
                }
                have[w]++;
                cnt++;
                while(have[w]>need[w])
                {
                    string x=s.substr(l,len);
                    have[x]--;
                    cnt--;
                    l+=len;
                }
                if(cnt==m)
                {
                    ans.push_back(l);
                    string x=s.substr(l,len);
                    have[x]--;
                    cnt--;
                    l+=len;
                }
            }
        }
        return ans;
    }
};