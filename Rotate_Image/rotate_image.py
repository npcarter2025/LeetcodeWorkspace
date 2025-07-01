class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # transpose it, and then reverse each row.

        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        for x in range(n):
            for y in range(n // 2):
                matrix[x][y], matrix[x][-1 - y] = matrix[x][-1 - y], matrix[x][y]



        return None