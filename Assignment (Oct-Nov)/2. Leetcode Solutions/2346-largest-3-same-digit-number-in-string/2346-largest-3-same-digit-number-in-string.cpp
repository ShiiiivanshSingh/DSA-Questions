class Solution {
public:
    string largestGoodInteger(string num) {
        for(char i= '9';i>='0';i--){
            string meowl = string(3,i);
            if(num.find(meowl)!= string::npos) return meowl;
        }
        return "";
    }
};