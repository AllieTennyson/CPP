//(1) Prompt the user to input an integer, a double, a character, and a string, storing each into separate variables.
//Then, output those four values on a single line separated by a space. (2 pts) 

#include <iostream>
#include <string>      // Supports use of "string" data type
using namespace std;

int main() {
   int userInt = 0;
   double userDouble = 0.0;
   char userChar;
   string userString = "";
   // FIXME: Define char and string variables

   cout << "Enter integer:" << endl;
   cin  >> userInt;

   // FIXME (1): Finish reading other items into variables, then output the four values on a single line separated by a space
   cout << "Enter double:" << endl;
   cin >> userDouble;

   cout << "Enter character:" << endl;
   cin >> userChar;

   cout << "Enter string:" << endl;
   cin >> userString;

   cout << userInt << " " << userDouble << " " << userChar << " " << userString << endl;

   // FIXME (2): Output the four values in reverse
   cout << userString << " " << userChar << " " << userDouble << " " << userInt << endl;

   // FIXME (3): Cast the double to an integer, and output that integer
   cout << userDouble << " cast to an integer is " << int (userDouble) << endl;

   return 0;
}
