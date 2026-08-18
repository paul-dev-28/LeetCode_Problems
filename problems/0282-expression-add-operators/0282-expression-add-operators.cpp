class Solution {
public:
    vector<string> ans;
    void solve(string& num,long long target,int i,long long val,long long prev,string s)
    {
        if(i==num.size())
        {
            if(val==target)
                ans.push_back(s);
            return;
        }
        long long x=0;
        for(int j=i;j<num.size();j++)
        {
            if(j>i&&num[i]=='0')
                break;
            x=x*10+(num[j]-'0');
            string cur=num.substr(i,j-i+1);
            if(i==0)
                solve(num,target,j+1,x,x,cur);
            else
            {
                solve(num,target,j+1,val+x,x,s+"+"+cur);
                solve(num,target,j+1,val-x,-x,s+"-"+cur);
                solve(num,target,j+1,val-prev+prev*x,prev*x,s+"*"+cur);
            }
        }
    }
    vector<string> addOperators(string num,int target)
    {
        solve(num,target,0,0,0,"");
        return ans;
    }
};