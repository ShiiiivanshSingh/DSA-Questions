class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx, vector<vector<int>>& vis) {
        int m = board.size();
        int n = board[0].size();
        if(idx == word.size()) return 1;
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(vis[i][j] || board[i][j] != word[idx]) return 0;

        vis[i][j] = 1;
        bool found = dfs(board, i+1, j, word, idx+1, vis) ||
                     dfs(board, i-1, j, word, idx+1, vis) ||
                     dfs(board, i, j+1, word, idx+1, vis) ||
                     dfs(board, i, j-1, word, idx+1, vis);
        vis[i][j] = 0;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0, vis)) 
                    return 1;
            }
        }
        return 0;
    }
};
