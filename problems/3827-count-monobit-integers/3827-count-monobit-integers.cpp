class Solution {
public:
    int countMonobit(int n) {
        int count=0;
        if(n>=0) count++;
        long long x=1;
        while (x<=n){
            count++;
            x=(x<<1)|1;
        }
        return count;
    }
};