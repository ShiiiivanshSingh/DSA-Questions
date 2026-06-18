class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string dayNames[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        
        // return dayNames[zeller(day, month, year)]; <- zeller
        return dayNames[sakamoto(year, month, day)];// <- sakamoto
    }

private:

    int sakamoto(int year, int month, int day) {
        static int monthOffsets[] = {0,3,2,5,0,3,5,1,4,6,2,4};
        year =year - ( month < 3 );
        return 
            (year + year/4 - year/100 + year/400 + monthOffsets[month-1] + day) % 7;
    }

    int zeller(int day, int month, int year) {
        if (month < 3) {
            month += 12;
            year--;
        }
        int centuryYear = year % 100;
        int century     = year / 100;
        int zellerDay   = (day + ( 13* (month+1))/5 + centuryYear + centuryYear/4 + century/4 - 2*century) % 7;
        return (zellerDay + 5) % 7;
    }
};