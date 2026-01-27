class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int flag=0,c=0;
        text=text+' ';
        for(int i=0;i<text.size();i++)
        {
            if (text[i]!=' ')
            {
                flag=0;
                for(int j=0;j<brokenLetters.size();j++)
                {
                    if (text[i]==brokenLetters[j])
                    {
                        flag=1;
                        while(text[i]!=' ')
                        {
                            i++;
                        }
                    }   
                }
            }
            if (flag==0 && text[i]==' ')
                c++;
        }
        return c;
    }
};