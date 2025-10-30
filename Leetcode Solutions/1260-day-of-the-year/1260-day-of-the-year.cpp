class Solution {
public:
    int dayOfYear(string date) {
        int year =0, month =0, day =0;

        for(int i=0;i<4;i++)    year = year*10  + (date[i] - '0');
        
        for(int i=5;i<7;i++)    month = month*10  + (date[i] - '0');
        
        for(int i=8;i<=9;i++)   day = day*10  + (date[i] - '0');
        
        int month_count[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if((year % 4 == 0 && year % 100 !=0)|| (year % 400 == 0 )) month_count[1] = 29;

        int meow = 0;
        for(int i =0 ; i< month - 1;i++){
            meow += month_count[i];
        }
        meow += day;
        return meow;

    }
};