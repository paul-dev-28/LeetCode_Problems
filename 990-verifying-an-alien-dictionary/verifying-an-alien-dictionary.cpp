class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>rank(26);
        for(int i=0;i<26;i++)
            rank[order[i]-'a']=i;
        for(int i=1;i<words.size();i++)
        {
            string a=words[i-1],b=words[i];
            int j=0;
            while(j<a.size() && j<b.size() && a[j]==b[j])
                j++;
            if(j==b.size() && j<a.size())
                return false;
            if(j<a.size() && j<b.size() && rank[a[j]-'a']>rank[b[j]-'a'])
                return false;
        }
        return true;
    }
};