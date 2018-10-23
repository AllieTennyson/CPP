#include <iostream>
#include <iomanip>
using namespace std;
int main() {
   int month;
   int year;
   int day;
   //int k;
   //int j;
   int days;
   int weekDay;

   cout << "Enter a month and year in 00 0000 format: ";
   cin >> month >> year;

   switch (month) {
      case 1:
         cout << "    January " << year;
         days = 31;
         break;
      case 2:
        cout << "   February " << year;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {days = 29;}
        else {days = 28; }
        break;
      case 3:
        cout << "     March " << year;
        days = 31;
        break;
      case 4:
        cout << "     April " << year;
        days = 30;
        break;
      case 5:
        cout << "      May " << year;
        days = 31;
        break;
      case 6:
        cout << "     June " << year;
        days = 30;
        break;
      case 7:
        cout << "     July " << year;
        days = 31;
        break;
      case 8:
        cout << "    August " << year;
        days = 31;
        break;
      case 9:
        cout << "   September " << year;
        days = 30;
        break;
      case 10:
        cout << "    October " << year;
        days = 31;
        break;
      case 11:
        cout << "   November " << year;
        days = 30;
        break;
      case 12:
        cout << "   December " << year;
        days = 31;
        break;
   }

    cout << endl << "Su Mo Tu We Th Fr Sa" << endl;

   if (month == 1 || month == 2)
   {
     year -= 1;
     month += 12;
   }

   weekDay = (1 + (13*(month +1) / 5) + year + (year/4) - (year/100) + (year/400)) % 7; // calculates the day

   int date;
   switch (weekDay) {
      case 0: date = 7; break; //Sabbath
      case 1: date = 1; break; //Sunday
      case 2: date = 2; break; //Monday
      case 3: date = 3; break; //Tuesday
      case 4: date = 4; break; //Wednesday
      case 5: date = 5; break; //Thursday
      case 6: date = 6; break; //Friday
   }

   if (date != 1)
   {
     cout << "  ";
     for (int i = 2; i < date; ++i)
     {
       cout << "   ";
     }
     cout << ' ';
   }
   for (day = 1; day <= days; day++)
   {
     cout << setw(2) << day;
     if ((day + weekDay) % 7 == 1)    //Adds a new line at the end of 7 days
     {
       cout << endl;
     }
     else if (day == days)
     {
       cout << endl;
     }
      else
      {
       cout << ' ';                   //Else, puts a space between each date
     }
   }






   return 0;
}
