class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long high = 0;
        long long maxW = *min_element(workerTimes.begin(), workerTimes.end());
        high = maxW * (long long)mountainHeight * (mountainHeight + 1) / 2;
        long long result = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canReduceHeight(mid, mountainHeight, workerTimes)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return result;
    }

private:
    bool canReduceHeight(long long time, int targetHeight, const vector<int>& workerTimes) {
        long long totalReduced = 0;
        for (int w : workerTimes) {
            long long val = (2 * time) / w;
            long long x = (-1 + sqrt(1 + 4 * val)) / 2;
            totalReduced += x;
            
            if (totalReduced >= targetHeight) return true;
        }
        return totalReduced >= targetHeight;
    }
};