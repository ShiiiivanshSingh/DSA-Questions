class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i=0;i<s.size();i++){
            int distance = s[i] - 'a';
            int cost = min(distance,26-distance);

            if(cost<=k) {
                k -= cost;
                s[i] = 'a'; // replace with a
            } else {
                int jump = min(k,distance);
                s[i] = char(s[i]  -  jump);
                k=0; // khel khtm
            }
            if(k == 0)  break;

            
        } return s;
    }
};