class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rows = len(matrix)
        cols = len(matrix[0])
        cells = rows * cols
        # In Example, Matrix is indexed starting at Top Left
        # Right, Down, Left, Up
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        # 
        # populate a list of which cells we've visited
        # set everything to False at first
        visited = []
        for elems in range(rows):
            row = []
            for elem in range(cols):
                row.append(False)
            visited.append(row)

        result = []


        # We can not use for loops to index normally
        # We will have to keep track of individual indices 
        # and calculate the next move as we go along

        i = 0
        j = 0
        dir_idx = 0

        for _ in range(cells):

            # Add the current cell to the Result list
            # Add True to Visited list
            # Then Set the next indices 
            if not visited[i][j]:
                result.append(matrix[i][j])
            
            visited[i][j] = True

            # Reference Directions, and set indices for next interation

            ni = i + dirs[dir_idx][1]
            nj = j + dirs[dir_idx][0]

            # Check that the next indices are in bounds.
            # if we're out of bounds or alrdy visited, 
            # turn clockwise & reset next indices

            if (not (0 <= ni < rows and 0 <= nj < cols)) or visited[ni][nj]:
                
                dir_idx = (dir_idx + 1) % 4

                ni = i + dirs[dir_idx][1]
                nj = j + dirs[dir_idx][0]
            
            # Finally, set the actually indices to next indices
            i = ni
            j = nj
        
        return result

    # ||===== MEMORY EFFICIENT SOLUTION USING BOUNDARIES AND DIRECT INDEXING==========||
    def spiralOrder_Memory_Efficient(self, matrix: List[List[int]]) -> List[int]:
        rows = len(matrix)
        cols = len(matrix[0])
        cells = rows * cols
        # We're just printing the elems, so no need to populate result with zeroes
        result = []

        # indices for current elem
        i = 0
        j = 0
        # Boundaries
        left = 0
        right = cols - 1
        top = 0
        bottom = rows -1

        # Strategy: Append cell to result
        # Then calculate next index depending out whether it's hit a boundary
        # After a full traversal, Update Bounds
        while cells > 0:

            result.append(matrix[i][j])
            cells -= 1
            if i == top and j < right: # move right
                j += 1

            elif i < bottom and j == right: # move down
                i += 1

            elif i == bottom and j > left: # move left 
                j -= 1

            elif i > top + 1 and j == left: # move up
                i -= 1
            
            # update the bounds and move to the right
            elif j == left and i == top + 1:
                top += 1
                bottom -= 1
                left += 1
                right -= 1
                j += 1

        return result

