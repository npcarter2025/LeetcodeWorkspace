#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();

        if (rows * cols != r * c) {
            return mat;
        }

        vector<int> flattened;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++ ) {
                flattened.push_back(mat[i][j]);
            }
        }

        vector<vector<int>> result;
        int index = 0;

        for (int i = 0; i < r; i++) {
            vector<int> row;
            for (int j = 0; j < c; j++) {
                row.push_back(flattened[index]);
                index++;
            }
            result.push_back(row);
        }
        return result;
    }
};