#ifndef DATEH
#define DATEH
#include <string>
#include <ctime>

using namespace std;

class Date
{

public:
        Date();
        int getCurrentYearAsInt();
        int getCurrentMonthAsInt();
        int getCurrentDayAsInt();
        string getCurrentLocalDate();
        string getCurrentYearAsString();
        string getCurrentMonthAsString();
        string getCurrentDayAsString();




private:
        int currentYear;
        int currentMonth;
        int currentDay;
        string currentDayStr;
        string currentYearStr;
        string currentMonthStr;


        string currentLocalDateStr;

        
        time_t now;
        tm *timeObj;

};

#endif //DATEH