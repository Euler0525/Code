# include "vector"

using namespace std;

class Solution
{
public:
    static bool isValidSudoku(vector<vector<char>> &board)
    {
        bool row[9][10] = {false}, column[10][9] = {false}, box[3][3][10] = {false};
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                if (board[r][c] == '.')
                {
                    continue;
                }
                char tmp = board[r][c];
                if (row[r][tmp - '0'])
                {
                    return false;
                }
                if (column[tmp - '0'][c])
                {
                    return false;
                }
                if (box[r / 3][c / 3][tmp - '0'])
                {
                    return false;
                }
                row[r][tmp - '0'] = true;
                column[tmp - '0'][c] = true;
                box[r / 3][c / 3][tmp - '0'] = true;
            }
        }
        return true;
    }
};