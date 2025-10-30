class Solution(object):
    def reverseString(self, s):
        seedhe = 0
        maut = len(s) - 1
        while seedhe < maut:
            s[seedhe], s[maut] = s[maut], s[seedhe]  # Swap
            seedhe += 1
            maut -= 1