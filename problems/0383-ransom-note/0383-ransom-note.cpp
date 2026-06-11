class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26]={0};
        for(int i=0;i<ransomNote.size();i++)
        {
            hash[(int)(ransomNote[i])-97]++;
        }
        for(int i=0;i<magazine.size();i++)
        {
            hash[(int)(magazine[i])-97]--;
        }
        for(int i=0;i<26;i++)
        {
            if (hash[i]>0)
                return false;
        }
        return true;
    }
};