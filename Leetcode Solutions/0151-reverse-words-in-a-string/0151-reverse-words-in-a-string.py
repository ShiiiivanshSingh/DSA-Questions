class Solution(object):
    def reverseWords(self, s):
        result = s.split()[::-1]
        return " ".join(result)
        