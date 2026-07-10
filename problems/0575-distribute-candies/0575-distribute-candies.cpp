class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mpp;
        int c=0;
        for(int i=0;i<candyType.size();i++)
        {
            mpp[candyType[i]]++;
        }  
        for(auto it:mpp)
        {
            if (it.second>0)
                c++;
        }    
        if (c<candyType.size()/2)
            return c;
        return candyType.size()/2;
    }
};