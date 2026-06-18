class Solution {
public:
    double angleClock(int hour, int minutes) {
        //ð=|30ð»â5.5ð|
        if(hour == 12 ) hour =0;
         double theta = abs(30.0 * hour - 5.5 * minutes);
    theta = min(theta, 360 - theta);

  //  cout << theta << endl;
    return theta;
    }
};