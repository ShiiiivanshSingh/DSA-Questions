class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> f1(10, 0), f2(10, 0);

        int i = 0, j = 0, bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                f1[secret[i] - '0']++;
                f2[guess[i] - '0']++;
            }
        }

        string ans;
        for (int i = 0; i < 10; i++) {
            cows += min(f1[i], f2[i]);
        }
        ans += (to_string(bulls));
        ans += ("A");
        ans += (to_string(cows));
        ans += ("B");
        return ans;
    }
};