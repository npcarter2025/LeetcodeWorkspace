class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        # ||===== MEM EFFICIENT APPROACH aka NO FLATTENING========||
        # ||===== indexing is calculated dynamically=====||
        rows = len(mat)
        cols = len(mat[0])
        if rows*cols != r * c:
            return mat
        
        result = []

        for m in range(r):
            row = []
            for n in range(c):

                # TEST CASE mat = [[1, 2], [3, 4]], and r = 1, c = 4
                # EXPECTED OUTPUT IS [[1, 2, 3, 4]]
                # need to index as if it was flattened
                #Think about it in reverse
                flattened_idx = m * c + n
                
                orig_row = flattened_idx // cols
                orig_col = flattened_idx % cols

                # Get the element and append it to the current row
                row.append(mat[orig_row][orig_col])
                
            result.append(row)
        return result
        
        
        
        
        # ||========ORIGINAL APPROACH aka copying to a FLATTENED LIST ===||
        # # Check dimensions are allowed
        # rows = len(mat)
        # cols = len(mat[0])
        # if rows*cols != r * c:
        #     return mat

        # # first flatten it, and then construct answer from this list
        # flattened = []
        # for i in range(rows):
        #     for j in range(cols):
        #         flattened.append(mat[i][j])
  
        # result = []
        # index = 0
        # for m in range(r):
        #     row = []
        #     for n in range(c):
        #         row.append(flattened[index])
        #         index += 1
        #     result.append(row)

        # return result     