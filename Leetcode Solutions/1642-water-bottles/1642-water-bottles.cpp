class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int mt =numBottles;
        int final =numBottles;
        while(mt >= numExchange){
            int mew= mt/numExchange;
            final += mew;
            mt =  mt% numExchange + mew;


        } return final;
    }
};