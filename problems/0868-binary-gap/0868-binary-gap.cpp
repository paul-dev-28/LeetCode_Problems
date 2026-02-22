class Solution {
public:
    int binaryGap(int n) {
        vector<int> bin;
        int c=0,max=0;
        if (n==1)
            return 0;
        while(n>0)
        {
            bin.insert(bin.begin(),n%2);
            n/=2;
        }
        for(int i=0;i<bin.size();)
        {
            if (bin[i]==1){
            i++;
            while(i<bin.size() && bin[i]!=1)
            {
                c++;
                i++;

            }}
            c++;
            if (bin[i-1]==0 && i==bin.size())
                c=0;
            if (c>max) 
                max=c;
            c=0;
        }
        return max;
    }
};