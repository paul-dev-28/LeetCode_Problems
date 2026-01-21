class Solution {
public:
    void reverseString(vector<char>& s) {
        int i,j;
        for(i=0,j=s.size()-1;i<s.size(),j>=0;i++,j--)
        {
            if (i==j)
                break;
            swap(s[i],s[j]);
            if ((j-i)==1)
                break;
            
        }
    }
};