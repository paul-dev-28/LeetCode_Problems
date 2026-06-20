class Solution {
public:
    long long hoursNeeded(int speed, vector<int>& piles)
    {
        long long hours = 0;

        for(int bananas : piles)
            hours += (bananas + speed - 1) / speed;

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(hoursNeeded(mid, piles) <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};