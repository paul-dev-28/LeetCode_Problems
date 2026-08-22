class Solution {
public:
    vector<string> validStrings(int n)
    {
        vector<string> list;
        string sb="";
        helper(n,list,'0',sb);
        sb="";
        helper(n,list,'1',sb);
        return list;
    }
    void helper(int n,vector<string>& list,char c,string& sb)
    {
        if(n==0)
        {
            list.push_back(sb);
            return;
        }
        if(c=='0')
        {
            sb.push_back(c);
            helper(n-1,list,'1',sb);
            sb.pop_back();
        }
        else
        {
            sb.push_back(c);
            helper(n-1,list,'0',sb);
            if(n>1)
                helper(n-1,list,'1',sb);
            sb.pop_back();
        }
    }
};