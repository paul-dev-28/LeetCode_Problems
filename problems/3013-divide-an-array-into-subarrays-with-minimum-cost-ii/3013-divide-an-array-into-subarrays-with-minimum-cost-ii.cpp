class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long current_sum = 0;
        multiset<int> low, high;
        int m = k - 1; 
        for (int i = 1; i <= dist + 1; ++i) {
            low.insert(nums[i]);
            current_sum += nums[i];
        }
        while (low.size() > m) {
            auto it = prev(low.end());
            current_sum -= *it;
            high.insert(*it);
            low.erase(it);
        }
        long long min_cost = current_sum;
        for (int i = dist + 2; i < n; ++i) 
        {
            int out = nums[i - dist - 1];
            auto it = low.find(out);
            if (it != low.end()) 
            {
                current_sum -= out;
                low.erase(it);
            } else 
            {
                high.erase(high.find(out));
            }
            low.insert(nums[i]);
            current_sum += nums[i];
            if (low.size() > m) {
                auto it_max = prev(low.end());
                current_sum -= *it_max;
                high.insert(*it_max);
                low.erase(it_max);
            }
            if (!high.empty() && *low.rbegin() > *high.begin()) {
                int val_low = *low.rbegin();
                int val_high = *high.begin();
                
                current_sum = current_sum - val_low + val_high;
                
                low.erase(prev(low.end()));
                high.erase(high.begin());
                
                low.insert(val_high);
                high.insert(val_low);
            }

            min_cost = min(min_cost, current_sum);
        }

        return min_cost + nums[0];
    }
};