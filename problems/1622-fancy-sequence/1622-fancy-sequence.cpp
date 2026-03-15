class Fancy {
private:
    vector<long long> nums;
    long long a = 1; 
    long long b = 0; 
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) 
    {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {}

    void append(int val) {
        long long x = (val - b + MOD) % MOD;
        x = (x * modInverse(a)) % MOD;
        nums.push_back(x);
    }

    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (a * nums[idx] + b) % MOD;
    }
};