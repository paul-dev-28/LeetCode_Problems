class Solution {
public:
    int countPrimes(int n) {
        vector<bool>checkPrime(n, true);
        if(n <= 2){
            return 0;
        }
        checkPrime[0] = false;
        checkPrime[1] = false;
        for(int i = 2; i * i < n; i++){
            if(checkPrime[i]){
                for(int j = i * i; j < n; j += i){
                    checkPrime[j] = false;
                }
            }
        }
        int count = 0;
        for(int j = 2; j < n; j++){
            if(checkPrime[j] == true){
                count++;
            }
        }
        return count;
    }
};