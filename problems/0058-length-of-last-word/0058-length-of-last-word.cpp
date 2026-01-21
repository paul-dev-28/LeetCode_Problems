class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0,i;
        if (s.size()==1 && s[0]!=' ')
            return 1;
        if (s.size()==0)
            return 0;
        for(i=s.size()-1;i>=0;i--)
        {
            if (s[i]==' ')
                continue;
            else
            {
                while(s[i]!=' ')
                {
                    c++;
                    if (i!=0)
                        --i;
                    else
                        break;
                }
                break; 
            }
        }
        return c;
    }
};