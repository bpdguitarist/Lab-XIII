//
//  Lab XIII
//
//  Created by Edgar Esparza on 7/19/15.
//

const int MAX_DATES = 60,
MAX_NAME_LEN = 81;

#include <iostream>
#include <fstream>
using namespace std;

struct DayData
{
    int month,
    day;
    char holiday[MAX_NAME_LEN];
};

void findHoliday ( const DayData holidayList[], int listLength,
                  int month, int day, char holidayCopy[] );

int main ()
{
    DayData holidayList[MAX_DATES];
    int count = 0,
    searchMonth,
    searchDay;
    char holidayName[MAX_NAME_LEN];
    
    ifstream holidayFile("holidays.txt");
    if (!holidayFile) {
        cout << "Can NOT open file " << endl;
        return 0;
    }
    
    while (holidayFile.good() && holidayFile >>
           holidayList[count].month>> holidayList[count].day )
    {
        holidayFile.get();
        holidayFile.getline(holidayList[count].holiday,
                            MAX_NAME_LEN,'\n');
        count++;
    }
    
    holidayFile.close();
    
    cout << "Enter the month and day for a holiday: ";
    cin >> searchMonth >> searchDay;
    
    findHoliday(holidayList,count,searchMonth,searchDay,holidayName);
    if ( holidayName[0] != '\0')
        cout << holidayName << endl;
    else
        cout << "No holiday listed" << endl;
}

void findHoliday (const DayData holidayList[],int listLength,
                  int month,int day,char holidayCopy[])
{
    for(int i = 0; i <listLength; i++)
        if(month == holidayList[i].month && day == holidayList[i].day) {
            strcpy (holidayCopy, holidayList[i].holiday);
        }
        else if(i == month - 1)
            holidayCopy[0] = '\0';
    }
