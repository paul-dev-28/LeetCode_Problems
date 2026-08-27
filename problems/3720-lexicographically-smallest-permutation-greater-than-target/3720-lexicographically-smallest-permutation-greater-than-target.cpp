class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int> cnt(26,0);

        for(char c:s)
            cnt[c-'a']++;

        // Try to make target itself using characters from s
        int i=0;
        for(;i<n;i++)
        {
            int x=target[i]-'a';

            if(cnt[x]>0)
                cnt[x]--;
            else
                break;
        }

        // If target was completely formed,
        // we need to find the next greater permutation.
        if(i==n)
        {
            i=n-1;

            while(i>=0)
            {
                cnt[target[i]-'a']++;

                int x=target[i]-'a';

                for(int c=x+1;c<26;c++)
                {
                    if(cnt[c]>0)
                    {
                        string ans=target.substr(0,i);
                        ans+=char('a'+c);
                        cnt[c]--;

                        for(int d=0;d<26;d++)
                        {
                            while(cnt[d]>0)
                            {
                                ans+=char('a'+d);
                                cnt[d]--;
                            }
                        }

                        return ans;
                    }
                }

                i--;
            }

            return "";
        }

        // We could not match target[i].
        // First try making this position greater.
        for(int c=target[i]-'a'+1;c<26;c++)
        {
            if(cnt[c]>0)
            {
                string ans=target.substr(0,i);
                ans+=char('a'+c);
                cnt[c]--;

                for(int d=0;d<26;d++)
                {
                    while(cnt[d]>0)
                    {
                        ans+=char('a'+d);
                        cnt[d]--;
                    }
                }

                return ans;
            }
        }

        // Cannot make position i greater.
        // Backtrack and increase an earlier position.
        for(i--;i>=0;i--)
        {
            cnt[target[i]-'a']++;

            for(int c=target[i]-'a'+1;c<26;c++)
            {
                if(cnt[c]>0)
                {
                    string ans=target.substr(0,i);
                    ans+=char('a'+c);
                    cnt[c]--;

                    for(int d=0;d<26;d++)
                    {
                        while(cnt[d]>0)
                        {
                            ans+=char('a'+d);
                            cnt[d]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};