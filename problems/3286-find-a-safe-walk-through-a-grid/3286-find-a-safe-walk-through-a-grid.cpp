typedef tuple<int, int, int> tiii;

class Solution {
    const int mov[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size(), col = grid[0].size();
        int life[row][col];
        memset(life, -1, sizeof(life));
        life[0][0] = health - grid[0][0];
        deque<tiii> dq;
        dq.push_back({0, 0, life[0][0]});
        while(!dq.empty()) {
            auto [r, c, hp] = dq.front();
            dq.pop_front();
            if (hp < life[r][c])
                continue;
            for (int dir = 0; dir < 4; dir++) {
                int newR = r + mov[dir][0], newC = c + mov[dir][1];
                if (newR >= 0 && newR < row && newC >= 0 && newC < col) {
                    int newHP = hp - grid[newR][newC];
                    if (newHP <= life[newR][newC])
                        continue;
                    life[newR][newC] = newHP;
                    if (newHP == hp) {
                        dq.push_front({newR, newC, newHP});
                    } else {
                        dq.push_back({newR, newC, newHP});
                    }
                }
            }
        }
        return life[row - 1][col - 1] > 0;
    }
};