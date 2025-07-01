class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        
        # XOR APPROACH
        n = len(image)
        for i in range(n):
            for j in range((n + 1) //2):
                image[i][j], image[i][-1-j] = 1 ^ image[i][-1-j], 1 ^ image[i][j]
        return image



        # LUT APPROACH
        n = len(image)
        invert = (1, 0)
        for i in range(n):
            for j in range((n + 1) // 2):
                image[i][j], image[i][-1-j] = invert[image[i][-1-j]], invert[image[i][j]]
        return image
        
        
        
        