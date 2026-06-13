class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> ch;
        int sum=0;
        for(int i=0;i<password.size();i++)
            ch.insert(password[i]);
        for(auto x:ch)
        {
            if (x>='a'&& x<='z')
                sum++;
            else if (x>='A'&& x<='Z')
                sum+=2;
            else if (x>='0'&& x<='9')
                sum+=3;
            else
                sum+=5;
        }
        return sum;
    }
};