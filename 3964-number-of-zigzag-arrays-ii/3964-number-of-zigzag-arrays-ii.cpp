class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    using mat = vector<vector<ll>>;

    mat op1(mat &a, mat &b) {
        int n = a.size(), m = b[0].size();

        mat c(n, vector<ll>(m));

        for (int i = 0; i < n; i++)
            for (int k = 0; k < a[0].size(); k++)
                if (a[i][k])
                    for (int j = 0; j < m; j++)
                        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;

        return c;
    }

    mat power(mat a, ll b, mat res) {
        while (b) {
            if (b & 1) res = op1(res, a);
            a = op1(a, a);
            b >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int sz = 2 * m;

        mat a(sz, vector<ll>(sz));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++)
                a[i][j + m] = 1;

            for (int j = i + 1; j < m; j++)
                a[i + m][j] = 1;
        }

        mat dp(1, vector<ll>(sz, 1));

        dp = power(a, n - 1, dp);

        ll ans = 0;

        for (int i = 0; i < sz; i++)
            ans = (ans + dp[0][i]) % mod;

        return ans;
    }
};