#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] =  temp;
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n / 2; y++) {
                int temp = matrix[x][y];

                matrix[x][y] = matrix[x][n - 1 - y];
                matrix[x][n - 1 - y] = temp;
            }
        }

    }
};
