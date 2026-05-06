class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        set<char> s;

        for (int i = 0; i < board.size(); i++) { // check rows O(n^2)
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == '.') continue;
                else if (s.count(board[i][j]) == 0) s.insert(board[i][j]);
                else return false;
            }
            s.clear();
        }

        for (int i = 0; i < board[0].size(); i++) { // check columns O(n^2)
            for (int j = 0; j < board.size(); j++) {

                if (board[j][i] == '.') continue;
                else if (s.count(board[j][i]) == 0) s.insert(board[j][i]);
                else return false;
            }
            s.clear();
        }

        // check 3x3s O(n^2)

        pair<int, int> bound(3, 3); // <i, j>
        while (bound.first < 9) {
            for (int i = bound.first - 3; i < bound.first; i++) {
                for (int j = bound.second - 3; j < bound.second; j++) {

                    if (board[i][j] == '.') continue;
                    else if (s.count(board[i][j]) == 0) s.insert(board[i][j]);
                    else return false;
                }
            }

            s.clear();
            if (bound.second < 9) bound.second += 3;
            else if (bound.first < 9 && bound.second == 9) {
                bound.second = 3;
                bound.first += 3;
            }
            
        }

        return true;
    }
};
