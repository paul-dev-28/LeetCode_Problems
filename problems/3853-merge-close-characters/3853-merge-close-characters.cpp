class Solution {
public:
    string mergeCharacters(string s, int k) {
       string vel = s;
        
        bool possible = true;
        while (possible) {
            possible = false;
            
            for (int i = 0; i < (int)vel.length(); ++i) {
                for (int j = i + 1; j <= i + k && j < (int)vel.length(); ++j) {
                    if (vel[i] == vel[j]) {
                        vel.erase(j, 1);
                        possible = true;
                        goto next_iteration; 
                    }
                }
            }
            next_iteration:;
        }
        
        return vel;
    }
};