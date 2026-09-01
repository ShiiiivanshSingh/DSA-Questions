class Solution {
public:
    int minMoves(vector<string>& a, int e) {
        int m = a.size(), n = a[0].size(), k = 0, sx, sy;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S')    sx = i, sy = j;
                if (a[i][j] == 'L')   id[i][j] = k++;
            }

        if (!k)    return 0;

        vector v(m, vector(n, vector<int>(1 << k, -1)));
        struct S {
            int x, y, z, e, d;
        };

        queue<S> q;
        q.push({sx, sy, 0, e, 0});
        v[sx][sy][0] = e;

        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        while (q.size()) {
            auto [x, y, z, en, d] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int X = x + dx[i], Y = y + dy[i];
                if (X < 0 || X >= m || Y < 0 || Y >= n || a[X][Y] == 'X')
                    continue;

                int E = en - 1;
                if (E < 0)
                    continue;
                if (a[X][Y] == 'R')
                    E = e;

                int Z = z | (a[X][Y] == 'L' ? 1 << id[X][Y] : 0);
                if (Z == (1 << k) - 1)
                    return d + 1;

                if (E > v[X][Y][Z])
                    v[X][Y][Z] = E, q.push({X, Y, Z, E, d + 1});
            }
        }
        return -1;
    }
};