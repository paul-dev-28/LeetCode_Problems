class Solution {
public:
bool isVowel(char c) {

        return c=='a' || c=='e' || c=='i' ||

               c=='o' || c=='u';

    }
    int maxVowels(string s, int k) {
        int i=0,c=0;
        for(i=0;i<k;i++)
        {
            if (isVowel(s[i]))
                c++;
        }
        int maxi=c;
        i=0;
        while(i+k<s.size())
        {
            if(isVowel(s[i]))
                c--;
            if(isVowel(s[i+k]))
                c++;
            maxi=max(maxi, c);
            i++;
        }
        return maxi;
    }
};