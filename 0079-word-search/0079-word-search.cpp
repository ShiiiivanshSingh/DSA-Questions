class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int i, int j, int index,vector<vector<int>> &visited){ //essentially im doin dfs
        int m = board.size();
        int n = board[0].size();
        if(index == word.size()) return 1; //final
        if(i<0 || j<0 || i>=m || j>=n) return 0; // edge case
        if(visited[i][j] == 1) return 0; //  already  went there
        if(board[i][j]  != word[index]) return 0; //wrong check

        visited[i][j] =1;
        bool x = helper(board, word, i+1, j , index+1, visited) || helper(board, word, i, j+1 , index+1, visited) || helper(board, word, i-1, j , index+1, visited) || helper(board, word, i, j-1 , index+1, visited);
        visited[i][j] =0;
        return x;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m ,  vector<int>(n ,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0] && helper(board, word, i , j, 0 , visited)){
                    return 1;
                }
            }
        }

        return 0; 
    }
};