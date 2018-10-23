//Write a program that outputs the lyrics to "Ten Little Indians" modified to be "N Little Indians" instead.
//Case, punctuation, and spacing matter. Add an input of where to stop, which defaults to 10.


#include <iostream>
using namespace std;
int main() {
   int i = 1;
   int indians = 10;
   cin >> indians;

   for (i = 1; i < indians; ++i) {
     if (i % 3 == 0) {
        cout << i << " little Indians;" << endl;
      }
      else {
        cout << i << " little, ";

      }
    }
    cout << indians << " little Indian boys." << endl;

   return 0;
}

//https://en.wikipedia.org/wiki/Ten_Little_Indians
