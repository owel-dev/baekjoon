#include <iostream>

using namespace std;

int main(){
  double a, b;

  cout << fixed;
  cout.precision(9);
  
  cin >> a >> b;
  cout << a / b << endl;
}