class Solution:
    def validMountainArray(self, s: List[int]) -> bool:
        if (len(s) < 3):
            return False

        curr = 1
        prev = 0
        ascending = True
        for i in range(len(s) - 1):

            if (s[1] < s[0] and ascending):
                return False

            if (s[curr] == s[prev]):            ####this goes out of bounds without the continue statement below
                return False

            if (ascending):
                if (s[curr] < s[prev]):
                    ascending = False
                    curr += 1
                    prev += 1
                    continue
                else:
                    curr += 1
                    prev += 1
                    continue  #<-----------    This is the continue I forgot in the interview


            if (s[curr] > s[prev]):
                return False
            curr += 1
            prev += 1

        return not ascending # <-------------- in the Interview, I put "return True && !ascending "
            
    
    # I did the above implementation in an interview. lol pretty bad
    # What I should've done was get rid of the for loop, and just use while loops instead


        

        

