class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string temp = to_string(n);
        int total =0;
        int ans[10];
        ans[0] =1;
        for(int  i =1 ; i<10;i++) ans[i] = ans[i-1] * i;  
        //for(int  i =1 ; i<10;i++) cout << ans [i] << endl;  //precoumpter or smthing idk i want 2 go back 2 sleep
        //cout << endl << endl;
        for(char c : temp) total += ans[c-'0'];
        // for(char c : temp) {
        //     cout << total << " will be added " << ans[c-'0'] << endl;
        // }
         //cout << total << endl;
        string temp2 = to_string(total);
        
        //cout << temp << " and " << temp2 << endl;
        sort(temp.begin(), temp.end());
        sort(temp2.begin(), temp2.end());
        //cout << temp << " and " << temp2 << endl;
        
        if(temp == temp2) return 1;
        else return 0;
    }
};