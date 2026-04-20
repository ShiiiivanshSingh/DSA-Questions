class Solution(object):
    def twoEggDrop(self, n):

        x =0 
        s = 0
        while(s < n):
            x = x+1
            s = x +s
           
       # print(x)  
        return x  
    