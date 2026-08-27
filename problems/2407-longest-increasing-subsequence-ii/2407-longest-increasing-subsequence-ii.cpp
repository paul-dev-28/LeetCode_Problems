class Solution {
public:
    vector<int> seg;
    int query(int node,int l,int r,int ql,int qr)
    {
        if(qr<l || r<ql)
            return 0;

        if(ql<=l && r<=qr)
            return seg[node];

        int mid=(l+r)/2;

        return max(
            query(node*2,l,mid,ql,qr),
            query(node*2+1,mid+1,r,ql,qr)
        );
    }

    void update(int node,int l,int r,int pos,int val)
    {
        if(l==r)
        {
            seg[node]=max(seg[node],val);
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid)
            update(node*2,l,mid,pos,val);
        else
            update(node*2+1,mid+1,r,pos,val);

        seg[node]=max(seg[node*2],seg[node*2+1]);
    }

    int lengthOfLIS(vector<int>& nums,int k)
    {
        int mx=*max_element(nums.begin(),nums.end());

        seg.resize(4*(mx+1),0);

        int ans=0;

        for(int x:nums)
        {
            int l=max(1,x-k);
            int r=x-1;

            int best=query(1,1,mx,l,r);

            int curr=best+1;

            update(1,1,mx,x,curr);

            ans=max(ans,curr);
        }

        return ans;
    }
};