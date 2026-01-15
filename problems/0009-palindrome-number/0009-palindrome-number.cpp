class Solution {
public:
    bool isPalindrome(long int x) {
        long int no=x,rev=0;
        if (x<0)
            return false;
        while(x>0)
        {
            rev=rev*10+(x%10);
            x/=10;
        }
        if (rev==no)
            return true;
        else
            return false;
    }
    void main()
    {
        long int n;
        std::cin >> n;
        std::cout << isPalindrome(n);
    }
};