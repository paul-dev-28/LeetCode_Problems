class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string a="";
        int t=(word1.size()>word2.size())? word1.size():word2.size();
        for(int i=0;i<t;i++)
        {
            if (i>=word1.size())
            {
                a+=word2[i];
                continue;
            }
            if (i>=word2.size())
            {
                a+=word1[i];
                continue;
            }    
            a+=word1[i];
            a+=word2[i];
        }
        return a;
    }
};