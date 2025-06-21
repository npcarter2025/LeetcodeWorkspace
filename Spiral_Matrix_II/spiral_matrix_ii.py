class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        
        #First Generate and Populate matrix with zeroes

        result = []
        for _ in range(n):
            row = []
            for _ in range(n):
                row.append(0)
            result.append(row)
        
        cells = n * n

        val = 1

       
        i = 0
        j = 0

        left = 0
        right = n - 1
        top = 0
        bottom = n - 1


        while val <= cells:
            result[i][j] = val
            val += 1
            if i == top and j < right: # move right
                j += 1
            elif i < bottom and j == right: # move down
                i += 1
            elif i == bottom and j > left: # move left
                j -= 1
            elif i > top + 1 and j == left: # move up
                i -= 1
            
            #Adjust Bounds and automatically move right
            elif i == top + 1 and j == left:
                top += 1
                bottom -= 1
                left += 1
                right -= 1

                j += 1


        return result