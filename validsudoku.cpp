class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<std::string> seen;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num == '.') continue;

            std::string rowKey = "row" + std::to_string(i) + num;
            std::string colKey = "col" + std::to_string(j) + num;
            std::string boxKey = "box" + std::to_string(i/3) + std::to_string(j/3) + num;

            if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                return false;
            }

            seen.insert(rowKey);
            seen.insert(colKey);
            seen.insert(boxKey);
        }
    }

    
        return true;
    }
};
