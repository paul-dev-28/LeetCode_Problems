class Solution {
public:
    int reverseDegree(string s) {
        int d=0;
        for(int i=0;i<s.size();i++)
            d+=(i+1)*((abs(s[i]-'z'))+1);
        return d;
    }
};