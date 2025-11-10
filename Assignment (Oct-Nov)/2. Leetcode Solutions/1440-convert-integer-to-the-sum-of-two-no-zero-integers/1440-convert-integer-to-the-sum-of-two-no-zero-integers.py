class Solution(object):
    def getNoZeroIntegers(self, n):
        def zerohai(x):
            return '0' in str(x)



            
        for myauu in range(1, n):
            meow = n - myauu
            if not zerohai(myauu) and not zerohai(meow):
                return [myauu, meow]
