//A variable like yearBorn can store a value like an integer. Extend the given program to calculate values based on yearBorn as indicated.
//(1) Output the user's input. (2 pts)

#include <iostream>
using namespace std;

int main()
{
  int year = 0;
  do {
    cout << "Enter the year you were born (4 digits, i.e., 1998): " << endl;
    cin  >> year;
    int age = 2017 - year;
    int day = (365.2425) * (age);

    cout << "You entered: " << year << endl;

    cout << "On your birthday this year, you'll be " << age << " years old." << endl;

    cout << "You'll have lived " << day << "±1" << " days." << endl;
  }

  while(year != 0);
  return 0;
}
