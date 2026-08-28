class Solution {
public:
    string build(string h,char mid,int n)
    {
        string ans=h;
        if(n%2)
            ans+=mid;
        for(int i=h.size()-1;i>=0;i--)
            ans+=h[i];
        return ans;
    }
    string nextGreater(vector<int> cnt,string t)
    {
        int n=t.size();
        string h="";
        int i=0;
        for(;i<n;i++)
        {
            int x=t[i]-'a';
            if(cnt[x]>0)
            {
                cnt[x]--;
                h+=t[i];
            }
            else
                break;
        }
        if(i==n)
        {
            for(i=n-1;i>=0;i--)
            {
                cnt[t[i]-'a']++;
                for(int c=t[i]-'a'+1;c<26;c++)
                {
                    if(cnt[c]>0)
                    {
                        string ans=t.substr(0,i);
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
        for(int c=t[i]-'a'+1;c<26;c++)
        {
            if(cnt[c]>0)
            {
                string ans=h;
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
        for(i--;i>=0;i--)
        {
            cnt[h[i]-'a']++;
            for(int c=h[i]-'a'+1;c<26;c++)
            {
                if(cnt[c]>0)
                {
                    string ans=h.substr(0,i);
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
    string lexPalindromicPermutation(string s,string target)
    {
        int n=s.size();
        vector<int> cnt(26,0);
        for(char c:s)
            cnt[c-'a']++;
        char mid=0;
        int odd=0;
        for(int c=0;c<26;c++)
        {
            if(cnt[c]%2)
            {
                odd++;
                mid=char('a'+c);
            }
        }
        if(odd>1)
            return "";
        vector<int> halfCnt(26,0);
        for(int c=0;c<26;c++)
            halfCnt[c]=cnt[c]/2;
        int m=n/2;
        string t=target.substr(0,m);
        string h="";
        vector<int> temp=halfCnt;
        for(int i=0;i<m;i++)
        {
            int x=t[i]-'a';
            if(temp[x]==0)
                break;
            temp[x]--;
            h+=t[i];
        }
        if(h.size()==m)
        {
            string cur=build(h,mid,n);
            if(cur>target)
                return cur;
            string next=nextGreater(halfCnt,h);
            if(next=="")
                return "";
            return build(next,mid,n);
        }
        string next=nextGreater(halfCnt,t);
        if(next=="")
            return "";
        return build(next,mid,n);
    }
};