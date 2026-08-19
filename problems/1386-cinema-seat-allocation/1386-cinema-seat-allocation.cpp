class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> mp;
        for(auto &x:reservedSeats)
            mp[x[0]]|=(1<<(x[1]-1));
        int ans=(n-mp.size())*2;
        for(auto &[r,mask]:mp)
        {
            bool left=(mask&((1<<1)|(1<<2)|(1<<3)|(1<<4)))==0;
            bool mid=(mask&((1<<3)|(1<<4)|(1<<5)|(1<<6)))==0;
            bool right=(mask&((1<<5)|(1<<6)|(1<<7)|(1<<8)))==0;
            if(left&&right)
                ans+=2;
            else if(left||mid||right)
                ans++;
        }
        return ans;
    }
};