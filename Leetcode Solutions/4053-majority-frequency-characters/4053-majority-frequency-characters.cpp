class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int chart[26] ={0};
        string mewo;
        for(char i: s) chart[i-'a']++;

        int size = 0;
        int freq = 0;

        for(int i = 1;i<= s.size();i++){ //freqaky
            int size1= 0 ;

            for(int j=0 ; j<26;j++){
                if( chart[j] == i) size1++;
            }

            if(size1> size || (size1 == size && i>freq)){
                size = size1;
                freq = i;
            }
        }
        for(int uwu = 0;uwu<26;uwu++) {
            if (chart[uwu] == freq){
                mewo.push_back('a' + uwu);

                
            }
        }
        return mewo;
    }
};