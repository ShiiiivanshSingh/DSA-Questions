class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), MOD = 1e9 + 7;
        vector<int> sc(n + 1, -1), way(n + 1);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> ns(n + 1, -1), nw(n + 1);

            for (int j = n - 1; j >= 0; j--) {
                char c = board[i][j];
                if (c == 'X') continue;
                if (c == 'S') {
                    ns[j] = 0;
                    nw[j] = 1;
                    continue;
                }
                int best = max({sc[j], ns[j + 1], sc[j + 1]});
                if (best == -1) continue;
                long long cnt = 0;
                if (sc[j] == best) cnt += way[j];
                if (ns[j + 1] == best) cnt += nw[j + 1];
                if (sc[j + 1] == best) cnt += way[j + 1];
                ns[j] = best + (c == 'E' ? 0 : c - '0');
                nw[j] = cnt % MOD;
            }

            sc = move(ns);
            way = move(nw);
        }

        if (sc[0] == -1) return {0, 0};
        return {sc[0], way[0]};
    }
};