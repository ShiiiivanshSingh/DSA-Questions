class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0) return "0";

    string meow;
    if((numerator<0) ^ (denominator<0)) meow += "-";   
    long n = labs(numerator) , d = labs(denominator);
    meow += to_string(n/d);

    long rem = n % d;

    if(rem == 0) return meow; //puurfewect
    meow += ".";

    unordered_map<long,int> pos;
    while(rem ) {
            if(pos.find(rem)!=pos.end()){
                meow.insert(pos[rem],"(");
                meow += ")";
                break;        
        }
        pos[rem] = meow.size();
        rem*= 10;
        meow+= to_string(rem / d);
        rem = rem % d;

    }
    return meow;
    }
};