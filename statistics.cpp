#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

double mean(vector<double> userNumber);
double range(vector<double> userNumber);
double median(vector<double> userNumber);
double stdDev(vector<double> userNumber);

int main() {
  double number = 0.0;

  cout << "One-variable statistics" << endl << "Type your numbers (separated by whitespace)";
  cout << " followed by EOF (^D on Linux/macOS, ^Z on Windows):" << endl;

  vector<double> userNumber(0);

  while(cin)
  {
    cin >> number;
    if (cin) {
    userNumber.push_back(number);
  }
  else {
    break;
  }
}

  cout << fixed << setprecision(3);
  cout << "Mean:" << setw(10) << mean(userNumber) << endl;
  cout << "Median:" << setw(8) << median(userNumber) << endl;
  cout << "Range:" << setw(9) << range(userNumber) << endl;
  cout << "StdDev:" << setw(8) << stdDev(userNumber) << endl;

  return 0;
}

double mean(vector<double> numbers)
{
  int size = numbers.size();
  float total = 0;
  for (auto i : numbers) {
    total += i;
  }

   return total/size;
}

double median(vector<double> userNumber) {
  sort(userNumber.begin(), userNumber.end());
  if (userNumber.size() % 2 != 0) {
    return userNumber.at((userNumber.size() / 2) + 0.5);
  }
  else {
    return (userNumber.at((userNumber.size() / 2)) + userNumber.at((userNumber.size() / 2) - 1)) / 2;
  }
}

double range(vector<double> userNumber) {
   return *max_element(userNumber.begin(), userNumber.end()) - *min_element(userNumber.begin(), userNumber.end());
}

double stdDev(vector<double> userNumber)
{
  double num = 0;
  double num2 = 0;
  double meanNumber = 0;
  for (auto i : userNumber) {
  meanNumber = mean(userNumber);
    num += (i - meanNumber) * (i - meanNumber);
  }
  num2 = num / userNumber.size();
  return sqrt(num2);
}
