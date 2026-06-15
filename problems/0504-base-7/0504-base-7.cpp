class Solution {
public:
    string convertToBase7(int num) {
        if (num==0)
            return "0";
        string s="";
        bool negative=(num<0);
        num=abs(num);
        while(num!=0)
        {
            s+=(char(num%7+'0'));
            num/=7;
        }
        if (negative)
            s+='-';
        reverse(s.begin(),s.end());
        return s;
    }
};