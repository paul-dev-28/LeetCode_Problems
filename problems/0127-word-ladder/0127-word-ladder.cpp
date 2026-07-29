class Solution
{
public:
    int ladderLength(string beginWord,string endWord,vector<string>& wordList)
    {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(!st.count(endWord))
            return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            auto [s,d]=q.front();
            q.pop();
            if(s==endWord)
                return d;
            for(int i=0;i<s.size();i++)
            {
                char c=s[i];
                for(char ch='a';ch<='z';ch++)
                {
                    s[i]=ch;
                    if(st.count(s))
                    {
                        q.push({s,d+1});
                        st.erase(s);
                    }
                }
                s[i]=c;
            }
        }
        return 0;
    }
};