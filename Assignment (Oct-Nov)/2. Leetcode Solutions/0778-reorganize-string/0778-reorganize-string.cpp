class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;

        int maxfr = 0, letter =0 ;
        for(int i=0;i<26;i++){
            if(freq[i] > maxfr){
                maxfr = freq[i];
                letter = i;
            }
        }
        if(maxfr > (n+1)/2) return ""; //fail case

        string uwu(n , ' ');
        int index= 0;
        while(freq[letter]--){
            uwu[index] = 'a' + letter;
            index +=2; //2 jump index
        }
        for(int i=0;i<26;i++){
            if(i==letter) continue;
            while(freq[i]--){
                if(index>=n) index =1;//reset
                uwu[index] = 'a' + i;
                index +=2; //2 jump index
            }
        } 
    return uwu;
    }
};