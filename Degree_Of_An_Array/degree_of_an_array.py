class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
         #[1,2,2,3,1]
        # {1: [0,4], 2: [1,2]}
        # 1: put everything in Hashmap K/V 
        # Key = Actual value
        # Value = list of indices
        # First time you saw it, last time you saw it

        # Degree = whichever Valuelist has the most elems
        # result = value[-1] - value[0]

        

        if not nums:
            return 0

        hashtable = {}
        maxElems = 0
        for i, elem in enumerate(nums):
            
            if not hashtable.get(elem):
                newEntry = [i]
                hashtable[elem] = newEntry

            else:
                hashtable[elem].append(i)

                checkLength = len(hashtable[elem]) 

                if (checkLength > maxElems):
                    maxElems = len(hashtable[elem]) #.values()

        minLength = float('inf')
        for key in hashtable:

            if len(hashtable[key]) == maxElems:

                tempList = hashtable[key]
                currLen = tempList[-1] - tempList[0]

                minLength = currLen if currLen < minLength else minLength

        return 1 if minLength == float('inf') else minLength + 1





    def findShortestSubArray(self, nums: List[int]) -> int:

        # {1: [count, first_index, last_index]}
        # 1: put everything in Hashmap K/V 
        # Key = Actual value
        # Degree = count
        # values = [count, first_index, last_index]

        if not nums:
            return 0

        hashtable = {}
        maxElems = 0
        for i, elem in enumerate(nums):
            
            if not hashtable.get(elem):
                newEntry = [1, i]
                hashtable[elem] = newEntry

            else:
                hashtable[elem][0] += 1
                if len(hashtable[elem]) == 2:
                    hashtable[elem].append(i)
                hashtable[elem][2] = i
                maxElems = hashtable[elem][0] if hashtable[elem][0] > maxElems else maxElems

        minLength = float('inf')
        if maxElems > 1:
            for key in hashtable:

                if hashtable[key][0] == maxElems:

                    tempList = hashtable[key]
                    currLen = tempList[2] - tempList[1]

                    minLength = currLen if currLen < minLength else minLength

        return 1 if minLength == float('inf') else minLength + 1


