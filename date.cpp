#include "date.h"
#include <string>
#include <ctime>

using namespace std;


Date::Date()
{
    now = time(0);
    
    timeObj = localtime(&now); 
    
}


string Date::getCurrentLocalDate()
{
        char *tmpdate = ctime(&now);
        
        int i = 0;
        while(tmpdate[i] != '\0')
        {
                currentLocalDateStr.push_back(tmpdate[i]);
                i++;
        }
        
        return currentLocalDateStr;
}


int Date::getCurrentYearAsInt()
{
        currentYear = 1900 + timeObj->tm_year;
        return currentYear;
}

int Date::getCurrentMonthAsInt()
{
        currentMonth = 1 + timeObj->tm_mon;
        return currentMonth;
}

int Date::getCurrentDayAsInt()
{
        currentDay = timeObj->tm_mday;
        return currentDay;
    
}


string Date::getCurrentYearAsString()
{
    currentYearStr = to_string(1900+timeObj->tm_year);
    return currentYearStr;
    
}


string Date::getCurrentMonthAsString()
{
    currentMonthStr = to_string(1 + timeObj->tm_mon);
    return currentMonthStr;
}

string Date::getCurrentDayAsString()
{
    currentDayStr = to_string(timeObj->tm_mday);
    
    return currentDayStr;
}

