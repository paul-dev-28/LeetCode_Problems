class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(101, 0.0);
        row[0] = (double)poured;
        for (int r = 0; r <= query_row; ++r) {
            vector<double> next_row(101, 0.0);
            for (int c = 0; c <= r; ++c) {
                if (row[c] > 1.0) {
                    double overflow = (row[c] - 1.0) / 2.0;
                    next_row[c] += overflow;
                    next_row[c + 1] += overflow;
                }
            }
            if (r == query_row) return min(1.0, row[query_glass]);
            row = next_row;
        }
        return 0.0;
    }
};