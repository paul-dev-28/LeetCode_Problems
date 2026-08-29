class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n=nums.size();
        const int z=1<<25;
        vector<string> s;
        for(int i=0;i<n;i++)
            {
                string st="";
                int zc=nums[i]/z;
                st.append(zc,'z');
                int x=nums[i]%z;
                for(int j=24;j>=0;j--)
                    {
                        if ((x>>j)&1)
                            st+=char('a'+j);
                    }
                s.push_back(st);
            }
        return s;
    }
};