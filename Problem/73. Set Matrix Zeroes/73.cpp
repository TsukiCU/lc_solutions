#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // whether there is 0 in the first line or col
        bool row0_flag = false;
        bool col0_flag = false;

        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == 0) {
                row0_flag = true;
                break;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) {
                col0_flag = true;
                break;
            }
        }

        // Mark rows and columns that need to be set to 0
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // Set the marked rows and columns to 0
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row and column separately if needed
        if (row0_flag) {
            for (int j = 0; j < col; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col0_flag) {
            for (int i = 0; i < row; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
