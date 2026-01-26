class Solution {
public:
    string sortVowels(string s) 
    {
        int c=0;
        vector<char> vowels;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
            {
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
            {
                swap(s[i],vowels[c]);
                c++;
            }
        }
        return s;
    }
};