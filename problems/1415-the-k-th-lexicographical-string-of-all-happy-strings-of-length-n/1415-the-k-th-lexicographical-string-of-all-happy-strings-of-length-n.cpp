class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * pow(2, n - 1);
        if (k > total) 
            return "";
        string res = "";
        vector<char> letters = {'a', 'b', 'c'};
        int partitionSize = pow(2, n - 1);
        for (char c : letters) 
        {
            if (k <= partitionSize) 
            {
                res += c;
                break;
            } 
            else 
            {
                k -= partitionSize;
            }
        }
        for (int i = 1; i < n; i++) 
        {
            partitionSize /= 2;
            for (char c : letters) 
            {
                if (c == res.back()) 
                    continue; 
                if (k <= partitionSize) 
                {
                    res += c;
                    break;
                } 
                else 
                {
                    k -= partitionSize;
                }
            }
        }
        return res;
    }
};