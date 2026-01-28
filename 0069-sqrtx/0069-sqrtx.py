class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0 or x == 1:
            return x
        
        low, high = 0, x
        while low <= high:
            mid = (low + high) // 2
            if mid * mid <= x and (mid + 1) * (mid + 1) > x:
                return mid
            elif mid * mid > x:
                high = mid - 1
            else:
                low = mid + 1
