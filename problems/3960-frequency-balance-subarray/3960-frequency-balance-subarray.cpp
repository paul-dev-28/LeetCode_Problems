class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for (int i=0;i<n;i++)
        {
            unordered_map<int,int> freq;
            map<int,int> cntFreq;
            for (int j=i;j<n;j++)
            {
                int x=nums[j];
                if (freq.count(x))
                {
                    int oldFreq=freq[x];
                    cntFreq[oldFreq]--;
                    if (cntFreq[oldFreq]==0)
                        cntFreq.erase(oldFreq);
                }
                freq[x]++;
                cntFreq[freq[x]]++;
                int dis=freq.size();
                bool ok=false;
                if (i==j)
                    ok = true;
                else if (dis==1)
                    ok = true;
                else if (cntFreq.size()==2)
                {
                    auto it1=cntFreq.begin();
                    auto it2=next(it1);
                    int low=it1->first;
                    int high=it2->first;
                    if (high==2*low)
                        ok=true;
                }
                if (ok)
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};