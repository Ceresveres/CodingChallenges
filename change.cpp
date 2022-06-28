#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int change;
  const int dollar = 100, quarter = 25, dime = 10, nickel = 5;
  
  cout << "Enter an amount in cents : ";
  cin >> change
  
  int currentCount = change;
  cout << "You can provide change for this as follows: " >> endl;
  
  change %= dollar;
  cout << "Dollars: " << ((currentCount - change) / dollar) << endl;
  currentCount = change % dollar;
  
  change %= quarter;
  cout << "Quarters: " << ((currentCount - change) / quarter) << endl;
  currentCount = change % quarter;
  
  change %= dime;
  cout << "Dimes: " << ((currentCount - change) / dime) << endl;
  currentCount = change % dime;
  
  change %= nickel;
  cout << "Nickels: " << ((currentCount - change) / nickel) << endl;
  currentCount = change % nickel
  
  cout << "Pennies: " << currentCount << endl;
  
  return 0;
}
