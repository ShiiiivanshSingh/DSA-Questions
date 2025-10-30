class Solution {
public:
    int distinctPoints(string s, int k) {
      string meow = s;
        int n= s.size();

        vector<pair<int , int>> ab(n+1, {0,0});

        for(int i =0 ; i<n ;i++){
            ab[i+1] = ab[i];

            if(s[i] == 'U') ab[i+1].second++; //upar
            if(s[i] == 'D') ab[i+1].second--; //neeche
            if(s[i] == 'L') ab[i+1].first--; //leff
            if(s[i] == 'R') ab[i+1].first++; //righte
        }

        pair<int, int> fia = ab[n];

        set<pair<int, int>> achaa;

        for(int l=0 ; l+ k<= n;l++){
            int r = l+k;
            int dx = ab[r].first - ab[l].first;
            int dy = ab[r].second - ab[l].second;
            achaa.insert({fia.first -dx, fia.second -dy});
        } return achaa.size();
    }
};