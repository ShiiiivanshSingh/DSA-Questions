class Robot {
public:
    int w, h, per;
    int steps = 0;
    bool chala =0;
        // 7 X 7 = 49
        // &
        // ???????
    Robot(int width, int height) {
        w = width;
        h = height;
        per = 2 * (w + h) - 4;
    }

    void step(int num) {
        int move = num % per;
        if(move == 0) move = per;
        steps = steps + move ;
       // steps %= k;
        steps %= per;
        chala = 1;
    }

    vector<int> getPos() {
        if(steps == 0) 
            return {0, 0};

        if(steps < w) 
            return {steps, 0};
        
        else if(steps < w + h - 1) 
            return {w - 1, steps - (w - 1)};
        
        else if(steps < 2*w + h - 2) 
            return {w - 1 - (steps - (w + h - 2)), h - 1};
        
        else 
            return {0, h - 1 - (steps - (2*w + h - 3))};
        
    }

    string getDir() {
        if(steps == 0){
            if(chala) return "South";
            else return "East"; // fake trav
        }
        if(steps < w) return "East";
        else if(steps < w + h - 1) return "North";
        else if(steps < 2*w + h - 2) return "West";
        else return "South"; // fin
    }
};