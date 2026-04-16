class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        if k == 0:
            return [0] * n

        temp = code * 2
        
        if k > 0:
            return [sum(temp[i + 1:i + 1 + k]) for i in range(n)]
        else:
            k = abs(k)
            return [sum(temp[i + n - k:i + n]) for i in range(n)]
