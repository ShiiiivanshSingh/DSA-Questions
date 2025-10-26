class Bank {
public:
    vector<long long> achaa;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size(); 
        // achaa.resize(n); 
        achaa = balance;
    }
    // Bank(vector<long long>& balance) {
    //     n = balance.size(); 
    //     // achaa.resize(n); 
    //     achaa = balance;
    // }
    
    bool transfer(int account1, int account2, long long money) {
         if (account1 < 1 || account1 > n || account2 < 1 || account2 > n) {
            return 0;
        }
        if(achaa[account1 - 1] >= money){
            achaa[account2 -1] += money; 
            achaa[account1 -1] -= money;
            return 1;
        }
    // bool transfer(int account1, int account2, long long money) {
    //      if (account1 < 1 || account1 > n || account2 < 1 || account2 > n) {
    //         return 0;
    //     }
    //     if(achaa[account1 - 1] >= money){
    //         achaa[account2 -1] += money; 
    //         achaa[account1 -1] -= money;
    //         return 1;
    //     }
        return 0;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > n )  {
            return 0;
        }


        achaa[account-1] += money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > n || achaa[account - 1] < money) {
            return 0;
        }
        achaa[account - 1] -= money;
        return 1; 
    }
};

