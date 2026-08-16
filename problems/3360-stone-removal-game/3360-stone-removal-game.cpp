class Solution {
public:
    bool canAliceWin(int n) {
        if (n<10)
            return false;
        int c=9;
        n-=10;
        while(n>0)
        {
            if (n<c)
                return true;
            n-=c;
            c--;
            if (n<c)
                return false;
            n-=c;
            c--;

        }
        return true;
    }
};