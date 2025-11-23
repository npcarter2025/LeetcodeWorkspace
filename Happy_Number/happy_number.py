class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        
        copy = n

        hold = n
        hashtable = {}
        squared = 0

        while copy not in hashtable:

            squared += ((hold % 10) ** 2)
            hold = hold // 10

            if not hold:
                hashtable[copy] = squared
                copy = squared
                hold = squared
                squared = 0

        return (copy == 1)

