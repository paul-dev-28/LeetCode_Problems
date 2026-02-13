class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        int currentRun = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                currentRun++;
            } else {
                currentRun = 1;
            }
            maxLen = max(maxLen, currentRun);
        }

        vector<pair<char, char>> pairs = {{'a', 'b'}, {'b', 'c'}, {'a', 'c'}};
        for (auto p : pairs) {
            char c1 = p.first, c2 = p.second;
            unordered_map<int, int> firstOccur;
            firstOccur[0] = -1;
            int diff = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] != c1 && s[i] != c2) {
                    firstOccur.clear();
                    firstOccur[0] = i; 
                    diff = 0;
                } else {
                    diff += (s[i] == c1) ? 1 : -1;
                    if (firstOccur.count(diff)) {
                        maxLen = max(maxLen, i - firstOccur[diff]);
                    } else {
                        firstOccur[diff] = i;
                    }
                }
            }
        }

        map<pair<int, int>, int> threeWayMap;
        threeWayMap[{0, 0}] = -1;
        int ca = 0, cb = 0, cc = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;

            pair<int, int> key = {cb - ca, cc - ca};
            if (threeWayMap.count(key)) {
                maxLen = max(maxLen, i - threeWayMap[key]);
            } else {
                threeWayMap[key] = i;
            }
        }

        return maxLen;
    }
};