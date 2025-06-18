# This is not a leetcode problem. 
# I'm just doing this to practice indicing
# and warm-up for SpSpMatMul



def matmul(matA: list[list[float]], matB: list[list[float]]) -> list[list[float]]:
    
    rowsA = len(matA)           #i
    colsA = len(matA[0])        #j
    rowsB = len(matB)           #j
    colsB = len(matB[0])        #k
    if rowsA == 0 | colsA == 0 | rowsB == 0 | colsB == 0:
        return []
    
    if colsA != rowsB:
        return []
    
    #A * B = C
    # ij * jk
    #C_dims = i * k

    # initialize the array filled with zeroes
    C = []
    for elem in range(rowsA):
        row = [0] * colsB
        C.append(row)

    for i in range(rowsA):
        for j in range(colsB):
            for k in range(colsA):
                C[i][j] += matA[i][k] * matB[k][j]

    return C


