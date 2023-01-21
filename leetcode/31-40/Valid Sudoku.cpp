#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[9];

        // judge row.
        for (int i = 0; i < 9; i++) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    if (st[t]) return false;
                    st[t] = true;
                }
            }
        }
        // judge column.
        for (int i = 0; i < 9; i++) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int t = board[j][i] - '1';
                    if (st[t]) return false;
                    st[t] = true;
                }
            }
        }
        // judge small square
        for (int x = 0; x < 9; x += 3) {
            for (int y = 0; y < 9; y += 3) {
                memset(st, 0, sizeof st);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[x + i][y + j] != '.') {
                            int t = board[x + i][y + j] - '1';
                            if (st[t]) return false;
                            st[t] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};