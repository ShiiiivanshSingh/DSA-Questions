class Solution {
public:
int maxBottlesDrunk(int numBottles, int numExchange) {

    int drunk = numBottles; //bottles consumemed
    int mt = numBottles; //empty bots
    int ex = numExchange; // exchanged

    while(mt >= ex){
        mt -= ex; drunk += 1;
        mt += 1;
        ex++;
    }

    return drunk;
    }
};
