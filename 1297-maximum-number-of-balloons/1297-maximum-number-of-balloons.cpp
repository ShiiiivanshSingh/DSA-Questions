class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int> mp;
        for(int i=0;i<text.length();i++) mp[text[i]]++;
        //for (auto it : mp) cout << it.first << " " << it.second << endl;
        int k = min( {mp['b'] , mp['a'] , mp['l'] /2 , mp['o'] /2 , mp['n'] } );

        return k;

    }
};