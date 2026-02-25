class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                int c1=__builtin_popcount(arr[j]);
                int c2=__builtin_popcount(arr[j+1]);
                if (c1>c2)
                    swap(arr[j],arr[j+1]);
                else if (c1==c2)
                {
                    if (arr[j]>arr[j+1])
                        swap(arr[j],arr[j+1]);
                }
            }
        }
        return arr;
    }
};