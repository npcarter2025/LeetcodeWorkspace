class Solution:
    def decodeString(self, s: str) -> str:     
        if not s:
            return ""

        def decode(s: str, index: int) -> (str, int):
            num = 0
            localString = ""
            while index < len(s):
                char = s[index]

                if char.isdigit():
                    num = num * 10 + int(char)
                                        
                elif char.isalpha():
                    localString += char

                elif (char == '['):
                    inner, index = decode(s, index +1)
                    localString += inner * num
                    num = 0
                elif (char == ']'):
                    return localString, index


                index += 1

            return localString, index

        regex, _ = decode(s, 0)
        return regex