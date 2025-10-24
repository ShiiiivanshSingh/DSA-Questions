class Solution {
public:
    bool fun(int x)
    {
        int digi[10] = {0};
        while(x > 0)
        {
            digi[x%10]++;
            x /= 10;
        }
        for(int i=0;i<=9;i++)
        {
            if(digi[i] > 0)
            {
                if(i != digi[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int ans = n+1;
        while(fun(ans) == false)
        {
            ans++;
        }
        return ans;
    }
};