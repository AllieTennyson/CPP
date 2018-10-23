//Prompt the user to input a wall's height and width. Calculate and output the wall's area. (2 pts)
//Extend to also calculate and output the amount of paint in gallons needed to paint the wall.
//  Assume a gallon of paint covers 350 square feet. Store this value using a const double variable. (2 pts)
//Extend to also calculate and output the number of 1 gallon cans needed to paint the wall. Hint: Use a math function to round up to the nearest gallon. (2 pts)

#include <iostream>
#include <cmath>                   // Note: Needed for math functions in part (3)
using namespace std;

int main() {
   double wallHeight = 0.0;
   double wallWidth  = 0.0;
   double wallArea   = 0.0;
   double gallonsNeeded = 0.0;
   float cansNeeded = 0;

   cout << "Enter wall height (feet):" << endl;
   cin  >> wallHeight;

   cout << "Enter wall width (feet):" << endl;
   cin >> wallWidth;                   // FIXME (1): Prompt user to input wall's width

   // Calculate and output wall area
   wallArea = wallWidth * wallHeight;                 // FIXME (1): Calculate the wall's area
   cout << "Wall area: " << wallArea << " square feet" << endl;  // FIXME (1): Finish the output statement


   // FIXME (2): Calculate and output the amount of paint in gallons needed to paint the wall
   gallonsNeeded = wallArea / 350;
   cout << "Paint needed: " << gallonsNeeded << " gallons" << endl;

   // FIXME (3): Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer
   cansNeeded = gallonsNeeded;
   cout << "Cans needed: " << round (cansNeeded) << " can(s)" << endl;

   return 0;
}
