#include "date.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	Date d;

	cout<<d.getCurrentLocalDate()<<endl;
	cout<<d.getCurrentMonthAsInt()<<endl;


	return 0;

}