class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
    int first = 0 , second = 0 ;
       int n = player1.size();
        // if (n > 0) first += player1[0], second += player2[0];
        // if (n > 1) first += player1[1], second += player2[1];
    for(int i = 0 ;i<player1.size() ; i++){
        if((i  - 1 >=0 && player1[i-1]  == 10)|| (i  - 2 >=0 && player1[i-2] == 10)){
            first += 2*player1[i];
        }
        else first += player1[i];
    }
    for(int i = 0 ;i<player2.size() ; i++){
        if((i  - 1 >=0 && player2[i-1]  == 10)|| (i  - 2 >=0 && player2[i-2] == 10)){
            second += 2*player2[i];
        }
        else second += player2[i];
    }
    cout << first <<  " -> " << second << endl;
    if(first > second) return 1;
    else if(first < second) return 2;
    else return 0;
    }
};