// Allie Tennyson
// 2017-1-17
// Lab 1: Day of Week

#include <iostream>
#include <cmath>
using namespace std;

int main() {

   int year;
   int month;
   int day;
   char dash;
   int j;
   int k;

   cin >> year >> dash >> month >> dash >> day;


   switch(month) {
      case 1: month = 13; year = year - 1; break;
      case 2: month = 14; year = year - 1; break;
   }

   k = year % 100;
   j = year / 100;

   day = (day + (13*(month +1) / 5) + k + (k/4) + (j/4) + 5*j) % 7;
   cout << day << endl; // calculation for day

   switch (day) {
      case 0: cout << "Saturday"; break;
      case 1: cout << "Sunday"; break;
      case 2: cout << "Monday"; break;
      case 3: cout << "Tuesday"; break;
      case 4: cout << "Wednesday"; break;
      case 5: cout << "Thursday"; break;
      case 6: cout << "Friday"; break;
   }



   return 0;
}
