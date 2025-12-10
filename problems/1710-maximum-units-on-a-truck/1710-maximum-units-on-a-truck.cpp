#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] > b[1]; 
            }
        );
        
        long long totalUnits = 0;
        int remainingTruckCapacity = truckSize;
        
        for (const auto& boxType : boxTypes) {
            
            if (remainingTruckCapacity == 0) {
                break;
            }
            
            int numberOfBoxes = boxType[0];
            int unitsPerBox = boxType[1];
            
            int boxesToTake = min(numberOfBoxes, remainingTruckCapacity);
            
            totalUnits += (long long)boxesToTake * unitsPerBox;
            
            remainingTruckCapacity -= boxesToTake;
        }
        
        return (int)totalUnits;
    }
};