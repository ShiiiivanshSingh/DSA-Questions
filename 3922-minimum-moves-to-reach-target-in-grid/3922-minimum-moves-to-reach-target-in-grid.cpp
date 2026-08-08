class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int moves = 0;
        while (sx != tx || sy != ty){
            //if(tx == sx && ty == sy) return moves;
            if (sx > tx || sy > ty) return -1;
            if (tx == 0) {

                if (sx != 0) return -1;
                if (ty & 1) return -1;

                ty = ty / 2;
                moves++;
                continue;
            }
            if (ty == 0) {

                if (sy != 0)  return -1;
                if (tx & 1) return -1;

                tx = tx / 2;
                moves++;
                continue;
            }

            if(tx > ty){
                if (tx > 2 * ty) {
                    if (tx % 2) return -1;
                    tx /= 2;
                } else tx = tx - ty; 
            }

            else if (ty > tx) {
                if (ty > 2 * tx) {
                    if (ty % 2) return -1;
                    ty = ty / 2;
                } else ty = ty - tx;
            }
            else {

                if (sx == 0)
                    tx = 0;
                else if (sy == 0)
                    ty = 0;
                else
                    return -1;
            }

            // if (tx == ty) {

            //     if (sx == 0) tx = 0;
            //     else if (sy == 0)  ty = 0;
            //     else  return -1;
        
            //     moves++;
            //     continue;
            // }
            moves++;
        }
            return moves;
    }
};

// class Solution {
// public:
//     int minMoves(int sx, int sy, int tx, int ty) {
//         int moves = 0;

//         while (tx >= sx && ty >= sy) {
            

// if (tx == 0) {
//     if (sx != 0) return -1;

//     if (ty % 2) return -1;

//     ty /= 2;
//     moves++;
//     continue;
// }

// if (ty == 0) {
//     if (sy != 0) return -1;

//     if (tx % 2) return -1;

//     tx /= 2;
//     moves++;
//     continue;
// }

//             if (tx > ty) {

//                 if (tx >= 2 * ty) {
//                     if (tx % 2)
//                         return -1;

//                     tx /= 2;
//                 } else {
//                     tx -= ty;
//                 }

//             } else if (tx < ty) {

//                 if (ty >= 2 * tx) {
//                     if (ty % 2)
//                         return -1;

//                     ty /= 2;
//                 } else {
//                     ty -= tx;
//                 }

//             } else {
//                 return -1;
//             }

//             moves++;
//         }

//         return -1;
//     }
// };