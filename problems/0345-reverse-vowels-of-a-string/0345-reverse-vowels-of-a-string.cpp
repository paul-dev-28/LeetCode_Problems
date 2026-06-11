class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int x=0,y=n-1;
        int flag1=0,flag2=0;
        while(x<y)
        {
            if ((s[x] == 'a' || s[x] == 'e' || s[x] == 'i' || s[x] == 'o'
        || s[x] == 'u' || s[x] == 'A' || s[x] == 'E' || s[x] == 'I'
        || s[x] == 'O' || s[x] == 'U'))
        {
            flag1=1;
        }    
        if (s[y] == 'a' || s[y] == 'e' || s[y] == 'i' || s[y] == 'o'
        || s[y] == 'u' || s[y] == 'A' || s[y] == 'E' || s[y] == 'I'
        || s[y] == 'O' || s[y] == 'U')
        {
            flag2=1;
        }
        if (flag1==flag2 && flag1==1)
        {
           
            swap(s[x],s[y]);
            x++;
            y--;
        }    
        else if (flag1)
            y--;
        else if (flag2)
            x++;
        else
        {    x++;
            y--;}
        flag1=0;
        flag2=0;
        }
        return s;
    }
};