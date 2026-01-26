class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> v;
        int min=arr[1]-arr[0];
        for(int i=1;i<arr.size()-1;i++)
        {
            if ((arr[i+1]-arr[i])<min)
                min=(arr[i+1]-arr[i]);
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            if ((arr[i+1]-arr[i])==min)
                v.push_back({arr[i],arr[i+1]});
        }
        return v;
    }
};