class Solution:
    def maximumLength(self, a: List[int]) -> int:
        f = lambda v:v>1 and (z[v]>1 and 2+f(v*v) or z[v] or -1)
        return max(*map(f,z:=Counter(a)),z[1]-~-z[1]%2)