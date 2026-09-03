class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX,o=0;
        for(int x: nums1){
            o+=x&1;
            mini=min(mini, x);
        }
        return mini&1||o==0;
    }
};