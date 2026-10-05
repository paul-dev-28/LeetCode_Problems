class Solution {
public:
    string sortSentence(string s) {
        int i=0;
        string a[10]={""};
        string s1="";
        for(i=0;i<s.size();i++)
        {
            while(s[i]!=' ')
            {
                if ((s[i]-'0')>=1 && (s[i]-'0')<=9)
                {
                    a[s[i]-'0'-1]=s1;
                    s1="";
                    break;
                }
                s1+=s[i];
                i++;
            }
        }
        s1="";
        for(int i=0;i<10;i++)
        {
            if (a[i]!="")
                s1+=a[i]+" ";
        }
        if (!s1.empty())
            s1.pop_back();
        return s1;
    }
};