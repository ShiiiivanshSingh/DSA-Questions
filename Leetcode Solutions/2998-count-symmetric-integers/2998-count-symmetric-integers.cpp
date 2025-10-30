class Solution {
public:
    bool isMeow(int num){
        string billa = to_string(num);
        if(billa.size() % 2 != 0 ) return false;

        int n = (billa.size())/2;
        int seedhe = 0, maut = 0; 


        for(int i = 0;i< n;i++) seedhe += billa[i] - '0';
        for(int j = n;j< billa.size();j++) maut += billa[j] - '0';

        return seedhe == maut;
    }
    int countSymmetricIntegers(int low, int high) {
        int count  =0;
        for(int i = low; i<=high; i++){
            if(isMeow(i))
            count++;
        }
        return count;
    }
};


// class Solution {
//     boolean isMeow(int num){

//     }
