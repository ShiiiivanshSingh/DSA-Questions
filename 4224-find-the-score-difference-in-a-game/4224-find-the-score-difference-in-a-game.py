class Solution(object):
    def scoreDifference(self, nums):
        a =0
        b =1
        for x,y in enumerate(nums):
            if y % 2 ==1:
                b *= -1
            if x % 6 ==5:
                b*= -1
                
            a += b *y
        return a
        """
        :type nums: List[int]
        :rtype: int
        """
        