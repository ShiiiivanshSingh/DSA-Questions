class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        set<string> visited;
        // vector<vector<int>> moves;
        string start;
        queue<pair<string, int>> q;

        for (auto row : board)
            for (auto x : row)
                start += char('0' + x);

        int zero = start.find('0');
        q.push({start, 0});
        visited.insert(start);
        vector<vector<int>> moves = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};

        while (!q.empty()) {
            auto [start, steps] = q.front();
            q.pop();
            if (start == "123450")     return steps;
            int zero = start.find('0');

            for (int next : moves[zero]) {
                swap(start[zero], start[next]);
                if (!visited.count(start)) {
                    visited.insert(start);
                    q.push({start, steps + 1});
                }
                swap(start[zero], start[next]);
            }
        } return -1;
    }
};