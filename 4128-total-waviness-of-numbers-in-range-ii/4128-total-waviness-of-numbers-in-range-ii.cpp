class Solution {
public:
    using ll = long long;

    ll f(ll x) {

        if (x < 100) return 0;

        string s = to_string(x);
        int n = s.size();

        struct node {
            int a, b, t, l;
            ll c, s;
        };

        vector<node> cur = {{10, 10, 1, 1, 1, 0}};

        for (int i = 0; i < n; i++) {

            ll cnt[2][2][11][11] = {};
            ll sum[2][2][11][11] = {};

            for (auto &p : cur) {

                int lim = p.t ? s[i] - '0' : 9;

                for (int d = 0; d <= lim; d++) {

                    int lead = p.l && d == 0;
                    int a = p.b;
                    int b = lead ? 10 : d;
                    int t = p.t && d == lim;

                    ll add = 0;

                    if (!lead && p.a != 10 && p.b != 10) {
                        if ((p.a < p.b && p.b > d) ||
                            (p.a > p.b && p.b < d))
                            add = p.c;
                    }

                    cnt[t][lead][a][b] += p.c;
                    sum[t][lead][a][b] += p.s + add;
                }
            }

            cur.clear();

            for (int t = 0; t < 2; t++)
                for (int l = 0; l < 2; l++)
                    for (int a = 0; a <= 10; a++)
                        for (int b = 0; b <= 10; b++)
                            if (cnt[t][l][a][b])
                                cur.push_back(
                                    {a, b, t, l,
                                     cnt[t][l][a][b],
                                     sum[t][l][a][b]});
        }

        ll ans = 0;

        for (auto &x : cur) {
            ans += x.s;
        }

        return ans;
    }

    long long totalWaviness(long long l, long long r) {
        return f(r) - f(l - 1);
    }
};