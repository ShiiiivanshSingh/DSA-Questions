class Solution {
public:
    void acha(int  cols, int n  , vector<vector<string>>& ans , vector<int> & board){
        if(cols == n){
            vector<string> temp(n, string(n, '.'));
            for(int c = 0; c < n; c++){
                temp[board[c]-1][c] = 'Q';
            }
            ans.push_back(temp);
            return;
        }
        for(int row = 0 ; row<n; row++){
            if( safe(row ,cols , board)){
                board[cols] = 1 + row;
                acha(cols +1 , n, ans, board );
            }
        }
    }
    bool safe(int row  ,int cols, vector<int> & board ){
        for(int last =0 ; last< cols; last++){
            
            int placed = board[last] -1 ;
            
            if(placed  == row) return 0;
            if(abs(placed - row) == abs(last - cols)) return 0;
        }
        return 1;
    }
    vector<vector<string>> solveNQueens(int n) {
        // code here
        vector<vector<string>> ans; 
        vector<int> board(n , 0);
        acha(0 , n ,ans , board);
        return ans;
    }
};

// class Solution {
//   public:
//     vector<vector<int>> nQueen(int n) {
//         // code here
//         vector<vector<int>> ans; 
//         vector<int> board(n , 0);
//         acha(0 , n ,ans , board);
//         return ans;
//     }
//     void acha(int  cols, int n  , vector<vector<int>>& ans , vector<int> & board){
//         if(cols == n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row = 0 ; row<n; row++){
//             if( safe(row ,cols , board)){
//                 board[cols] = 1 + row;
//                 acha(cols +1 , n, ans, board );
//             }
//         }
//     }
//     bool safe(int row  ,int cols, vector<int> & board ){
//         for(int last =0 ; last< cols; last++){
            
//             int placed = board[last] -1 ;
            
//             if(placed  == row) return 0;
//             if(abs(placed - row) == abs(last - cols)) return 0;
//         }
//         return 1;
//     }
// };
