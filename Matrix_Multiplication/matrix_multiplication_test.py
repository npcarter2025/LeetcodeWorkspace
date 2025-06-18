#!/Users/nathancarter/anaconda3/bin/python3
from matrix_multiplication import matmul
import random 

import numpy as np 


def main():
    i = random.randint(3, 6)
    j = random.randint(1, 5)
    k = random.randint(1, 5)
    print(f" i = {i}; \n j = {j}; \n k = {k}")
    A = []
    for elem in range(i):
        row = []
        for elems in range(j):
            row.append(random.randint(0, 100))
        A.append(row)

    B = []
    for elem in range(j):
        row = []
        for elems in range(k):
            row.append(random.randint(0, 100))

        B.append(row)

    result = matmul(A, B)
    print(f"result = ")
    for i, row in enumerate(result):
        print(i, row)
    np_result = np.matmul(np.array(A), np.array(B)).tolist()
    print(f"np_result = ")
    for i, row in enumerate(np_result):
        print(i, row)



    assert result == np_result or print("Test passed."), f"Test failed!\nA={A}\nB={B}\nResult={result}\nExpected={np_result}"


if __name__ == "__main__":
    main()