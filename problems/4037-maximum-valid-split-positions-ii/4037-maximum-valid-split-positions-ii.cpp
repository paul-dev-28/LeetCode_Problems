class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return 0;
        // prefixGcd[i] = GCD of nums[0...i]
        // suffixGcd[i] = GCD of nums[i...n-1]
        vector<int>prefixGcd(n),suffixGcd(n);
        prefixGcd[0]=nums[0];
        for(int i=1;i<n;i++)
            prefixGcd[i]=gcd(prefixGcd[i-1],nums[i]);
        suffixGcd[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            suffixGcd[i]=gcd(suffixGcd[i+1],nums[i]);
        // Build sparse table for O(1) range GCD queries.
        int maxLog=1;
        while((1<<maxLog)<=n)
            maxLog++;
        vector<vector<int>>sparseTable(maxLog,vector<int>(n));
        sparseTable[0]=nums;
        for(int level=1;level<maxLog;level++)
        {
            int length=1<<level;
            int halfLength=length>>1;
            for(int i=0;i+length<=n;i++)
                sparseTable[level][i]=gcd(sparseTable[level-1][i],sparseTable[level-1][i+halfLength]);
        }
        vector<int>logValue(n+1);
        for(int i=2;i<=n;i++)
            logValue[i]=logValue[i/2]+1;
        // Returns GCD of nums[left...right].
        auto rangeGcd=[&](int left,int right)
        {
            if(left>right)
                return 0;
            int length=right-left+1;
            int level=logValue[length];
            return gcd(sparseTable[level][left],sparseTable[level][right-(1<<level)+1]);
        };
        // A prefix GCD changes only a small number of times.
        // We only need to consider deletions at those positions.
        vector<int>prefixChangeIndices,suffixChangeIndices;
        int previousGcd=0;
        for(int i=0;i<n;i++)
        {
            if(prefixGcd[i]!=previousGcd)
            {
                prefixChangeIndices.push_back(i);
                previousGcd=prefixGcd[i];
            }
        }
        previousGcd=0;
        for(int i=n-1;i>=0;i--)
        {
            if(suffixGcd[i]!=previousGcd)
            {
                suffixChangeIndices.push_back(i);
                previousGcd=suffixGcd[i];
            }
        }
        // Calculate the score without deleting anything.
        vector<bool>baseValid(n-1,false);
        int baseScore=0;
        for(int split=0;split<n-1;split++)
        {
            if(prefixGcd[split]==suffixGcd[split+1])
            {
                baseValid[split]=true;
                baseScore++;
            }
        }
        // Start every deletion with the score of the original array.
        vector<int>scoreAfterDeletion(n,baseScore);
        // Deleting nums[deletionIndex] removes the original split immediately
        // before it. This split no longer exists in the resulting array.
        for(int deletionIndex=0;deletionIndex<n;deletionIndex++)
        {
            int removedSplit=min(deletionIndex,n-2);
            if(baseValid[removedSplit])
                scoreAfterDeletion[deletionIndex]--;
        }
        // If nums[deletionIndex] is removed, for splits before it:
        // left GCD stays the same, while the right GCD may change.
        for(int deletionIndex:prefixChangeIndices)
        {
            for(int split=deletionIndex+1;split<n-1;split++)
            {
                if(split==deletionIndex)
                    continue;
                int leftGcd=prefixGcd[split];
                int rightGcd=gcd(rangeGcd(split+1,deletionIndex-1),suffixGcd[deletionIndex+1]);
                bool newValid=(leftGcd==rightGcd);
                if(newValid && !baseValid[split])
                    scoreAfterDeletion[deletionIndex]++;
                else if(!newValid && baseValid[split])
                    scoreAfterDeletion[deletionIndex]--;
            }
        }
        // If nums[deletionIndex] is removed, for splits after it:
        // right GCD stays the same, while the left GCD may change.
        for(int deletionIndex:suffixChangeIndices)
        {
            for(int split=0;split<deletionIndex-1;split++)
            {
                int leftGcd=gcd(prefixGcd[deletionIndex-1],rangeGcd(deletionIndex+1,split));
                int rightGcd=suffixGcd[split+1];
                bool newValid=(leftGcd==rightGcd);
                if(newValid && !baseValid[split])
                    scoreAfterDeletion[deletionIndex]++;
                else if(!newValid && baseValid[split])
                    scoreAfterDeletion[deletionIndex]--;
            }
        }
        int answer=baseScore;
        for(int deletionIndex=0;deletionIndex<n;deletionIndex++)
            answer=max(answer,scoreAfterDeletion[deletionIndex]);
        return answer;
    }
};