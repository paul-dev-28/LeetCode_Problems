class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if (s[i]==x)
            {
                while(s[j]==x && j>i)
                {
                    j--;
                }    
                if(i<j)
                {
                    swap(s[i],s[j]);
                    j--;
                }
            }
            i++;
        }
        return s;
    }
};