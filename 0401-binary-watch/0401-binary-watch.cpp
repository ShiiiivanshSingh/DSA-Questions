class Solution {
public:
    int countBits(int x) {
        int count = 0;
        while (x > 0) {
            if (x % 2 == 1) count++;
            x = x / 2;
        }
        return count;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<=11;i++){                 // hours display
            for(int j =0; j<=59;j++){              // minute display
                if(countBits(i)+countBits(j) == turnedOn){
                    string hour = to_string(i);
                    string minute = to_string(j);

                    if (j < 10)    minute = "0" + minute;
                    
                    ans.push_back(hour + ":"+ minute);
                }
            }
        }
        return ans;
    }
};