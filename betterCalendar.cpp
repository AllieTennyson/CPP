//Allie Tennyson
//2017-2-14
//Calendar Functions
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function prototypes
string determineMonth(int month);
int calculateWeekDay(int month, int year);
int determineDays(int month, int year);
void calculateDayofWeek(int weekDay, int days);
int date(int weekDay);

int main()
{
  int month, year;
  //int result = (new doctest::Context())->run();
  cout << "Enter a month and year in 00 0000 format: ";
  cin >> month >> year;
  //cin >> month >> year;
  cout << determineMonth(month) << " " << year << endl;
  cout << "Su Mo Tu We Th Fr Sa" << endl;

  int numberOfDays = determineDays(month, year);


  int weekDay = calculateWeekDay(month, year);
  weekDay = date(weekDay);
  calculateDayofWeek(weekDay, numberOfDays);

 //return result;
}

//Function Defenitions

//Determines the number of days in a month
int determineDays(int month, int year)
{
  int days = 0;
  switch (month)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
     days = 31;
     break;
    case 2:
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {days = 29;}
    else {days = 28; }
    break;
    case 4:
    case 6:
    case 9:
    case 11:
      days = 30;
    break;
  }
    return days;
  }

//Determines the month based on readDate function
string determineMonth(int month)
{
   switch (month)
   {
      case 1:
         return "    January";
         break;
      case 2:
        return  "   February";
        break;
      case 3:
        return "     March";
        break;
      case 4:
        return "     April";
        break;
      case 5:
        return "      May";
        break;
      case 6:
        return "     June";
        break;
      case 7:
        return "     July";
        break;
      case 8:
        return "    August";
        break;
      case 9:
        return "   September";
        break;
      case 10:
        return "    October";
        break;
      case 11:
        return "   November";
        break;
      case 12:
        return "   December";
        break;
      default:
       return "0";
   }
 }

//Determines the weekday from equation
int calculateWeekDay(int month, int year)
{
    if (month == 1 || month == 2)
       {
           year -= 1;
           month += 12;
       }
    return (1 + (13*(month +1) / 5) + year + (year/4) - (year/100) + (year/400)) % 7; // calculates the day
}

//Determines the day of the week
void calculateDayofWeek(int date, int days)
{
   if (date == 0)
   {
       date = 7;
   }
//    switch (weekDay) {
//       case 0: date = 7; break; //Sabbath
//       case 1: date = 1; break; //Sunday
//       case 2: date = 2; break; //Monday
//       case 3: date = 3; break; //Tuesday
//       case 4: date = 4; break; //Wednesday
//       case 5: date = 5; break; //Thursday
//       case 6: date = 6; break; //Friday

    if (date != 1)
    {
        cout << "  ";
        for (int i = 2; i < date; ++i)
        {
            cout << "   ";
        }
      cout << ' ';
    }
    for (int currentDay = 1; currentDay <= days; currentDay++)
    {
        cout << setw(2) << currentDay;
        if ((currentDay + date) % 7 == 1)    //Adds a new line at the end of 7 days
        {
            cout << endl;
        }
      else if (currentDay == days)
      {
            cout << endl;
      }
       else
       {
            cout << ' ';                   //Else, puts a space between each date
      }
    }
}

//Switch statement for day of the week
int date(int weekDay)
{
    int date = 0;
    switch (weekDay)
    {
     case 0: date = 7; break; //Sabbath
     case 1: date = 1; break; //Sunday
     case 2: date = 2; break; //Monday
     case 3: date = 3; break; //Tuesday
     case 4: date = 4; break; //Wednesday
     case 5: date = 5; break; //Thursday
     case 6: date = 6; break; //Friday
    }
  return date;
}

//TEST CASES

TEST_CASE("determineMonth")
{
  CHECK(determineMonth(1) == "    January");
  CHECK(determineMonth(2) == "   February");
  CHECK(determineMonth(3) == "     March");
  CHECK(determineMonth(4) == "     April");
  CHECK(determineMonth(5) == "      May");
  CHECK(determineMonth(6) == "     June");
  CHECK(determineMonth(7) == "     July");
  CHECK(determineMonth(8) == "    August");
  CHECK(determineMonth(9) == "   September");
  CHECK(determineMonth(10) == "    October");
  CHECK(determineMonth(11) == "   November");
  CHECK(determineMonth(12) == "   December");
  CHECK(determineMonth(15) == "0");
}

TEST_CASE("determineDays")
{
  CHECK(determineDays(1, 1995) == 31); // 31-Day Month
  CHECK(determineDays(3, 1995) == 31);
  CHECK(determineDays(5, 1995) == 31);
  CHECK(determineDays(7, 1995) == 31);
  CHECK(determineDays(8, 1995) == 31);
  CHECK(determineDays(9, 1995) == 30);
  CHECK(determineDays(10, 1995) == 31);
  CHECK(determineDays(12, 1995) == 31);
  CHECK(determineDays(2, 2017) == 28); // February Non-Leap Year
  CHECK(determineDays(2, 2016) == 29); // February Leap Year
  CHECK(determineDays(4, 2016) == 30); // 30-Day Month
  CHECK(determineDays(6, 2016) == 30);
  CHECK(determineDays(11, 2016) == 30);
}

TEST_CASE("calculateWeekDay")
{
    //Sunday
  CHECK(calculateWeekDay(1, 2017) == 1);
  CHECK(calculateWeekDay(2, 2015) == 1);
  CHECK(calculateWeekDay(3, 2015) == 1);
  CHECK(calculateWeekDay(4, 2012) == 1);
  CHECK(calculateWeekDay(5, 2011) == 1);
  CHECK(calculateWeekDay(6, 2014) == 1);
  CHECK(calculateWeekDay(7, 2018) == 1);
  CHECK(calculateWeekDay(8, 2010) == 1);
  CHECK(calculateWeekDay(9, 2013) == 1);
  CHECK(calculateWeekDay(10, 2017) == 1);
  CHECK(calculateWeekDay(11, 2015) == 1);
  CHECK(calculateWeekDay(12, 2013) == 1);

  //Monday
  CHECK(calculateWeekDay(1, 2018) == 2);
  CHECK(calculateWeekDay(2, 2010) == 2);
  CHECK(calculateWeekDay(3, 2010) == 2);
  CHECK(calculateWeekDay(4, 2013) == 2);
  CHECK(calculateWeekDay(5, 2017) == 2);
  CHECK(calculateWeekDay(6, 2015) == 2);
  CHECK(calculateWeekDay(7, 2019) == 2);
  CHECK(calculateWeekDay(8, 2016) == 2);
  CHECK(calculateWeekDay(9, 2014) == 2);
  CHECK(calculateWeekDay(10, 2012) == 2);
  CHECK(calculateWeekDay(11, 2010) == 2);
  CHECK(calculateWeekDay(12, 2014) == 2);

  //Tuesday
  CHECK(calculateWeekDay(1, 2013) == 3);
  CHECK(calculateWeekDay(2, 2011) == 3);
  CHECK(calculateWeekDay(3, 2011) == 3);
  CHECK(calculateWeekDay(4, 2014) == 3);
  CHECK(calculateWeekDay(5, 2018) == 3);
  CHECK(calculateWeekDay(6, 2010) == 3);
  CHECK(calculateWeekDay(7, 2014) == 3);
  CHECK(calculateWeekDay(8, 2017) == 3);
  CHECK(calculateWeekDay(9, 2015) == 3);
  CHECK(calculateWeekDay(10, 2013) == 3);
  CHECK(calculateWeekDay(11, 2016) == 3);
  CHECK(calculateWeekDay(12, 2015) == 3);

  //Wednesday
  CHECK(calculateWeekDay(1, 2014) == 4);
  CHECK(calculateWeekDay(2, 2012) == 4);
  CHECK(calculateWeekDay(3, 2017) == 4);
  CHECK(calculateWeekDay(4, 2015) == 4);
  CHECK(calculateWeekDay(5, 2013) == 4);
  CHECK(calculateWeekDay(6, 2016) == 4);
  CHECK(calculateWeekDay(7, 2015) == 4);
  CHECK(calculateWeekDay(8, 2012) == 4);
  CHECK(calculateWeekDay(9, 2010) == 4);
  CHECK(calculateWeekDay(10, 2014) == 4);
  CHECK(calculateWeekDay(11, 2017) == 4);
  CHECK(calculateWeekDay(12, 2010) == 4);

  //Thursday
  CHECK(calculateWeekDay(1, 2015) == 5);
  CHECK(calculateWeekDay(2, 2018) == 5);
  CHECK(calculateWeekDay(3, 2012) == 5);
  CHECK(calculateWeekDay(4, 2010) == 5);
  CHECK(calculateWeekDay(5, 2014) == 5);
  CHECK(calculateWeekDay(6, 2017) == 5);
  CHECK(calculateWeekDay(7, 2010) == 5);
  CHECK(calculateWeekDay(8, 2013) == 5);
  CHECK(calculateWeekDay(9, 2011) == 5);
  CHECK(calculateWeekDay(10, 2015) == 5);
  CHECK(calculateWeekDay(11, 2012) == 5);
  CHECK(calculateWeekDay(12, 2011) == 5);

  //Friday
  CHECK(calculateWeekDay(1, 2010) == 6);
  CHECK(calculateWeekDay(2, 2013) == 6);
  CHECK(calculateWeekDay(3, 2013) == 6);
  CHECK(calculateWeekDay(4, 2011) == 6);
  CHECK(calculateWeekDay(5, 2015) == 6);
  CHECK(calculateWeekDay(6, 2012) == 6);
  CHECK(calculateWeekDay(7, 2011) == 6);
  CHECK(calculateWeekDay(8, 2014) == 6);
  CHECK(calculateWeekDay(9, 2017) == 6);
  CHECK(calculateWeekDay(10, 2010) == 6);
  CHECK(calculateWeekDay(11, 2013) == 6);
  CHECK(calculateWeekDay(12, 2017) == 6);

  //Saturday
  CHECK(calculateWeekDay(1, 2011) == 0);
  CHECK(calculateWeekDay(2, 2014) == 0);
  CHECK(calculateWeekDay(3, 2014) == 0);
  CHECK(calculateWeekDay(4, 2017) == 0);
  CHECK(calculateWeekDay(5, 2010) == 0);
  CHECK(calculateWeekDay(6, 2013) == 0);
  CHECK(calculateWeekDay(7, 2017) == 0);
  CHECK(calculateWeekDay(8, 2015) == 0);
  CHECK(calculateWeekDay(9, 2012) == 0);
  CHECK(calculateWeekDay(10, 2011) == 0);
  CHECK(calculateWeekDay(11, 2014) == 0);
  CHECK(calculateWeekDay(12, 2012) == 0);
}

TEST_CASE("date")
{
  CHECK(date(0) == 7);
  CHECK(date(1) == 1);
  CHECK(date(2) == 2);
  CHECK(date(3) == 3);
  CHECK(date(4) == 4);
  CHECK(date(5) == 5);
  CHECK(date(6) == 6);
}
