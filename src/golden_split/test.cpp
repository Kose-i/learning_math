#include <iostream>

/***
*** AP:PB = AB:AP
***
***/
int main(int argc, char** argv) {
  double AP = 0; // AP^2 = (1 - AP) ==> AP^2+AP-1 = 0
  double AP_right = 1;
  double AP_left = 0;
  for (double eps = 0.00001;AP_right - AP_left > eps;) {
    double AP_mid = (AP_right + AP_left)/2.0;
    if ((AP_mid*AP_mid) + AP_mid - 1 > 0) {
      AP_right = AP_mid;
    } else {
      AP_left = AP_mid;
    }
  }
  AP = AP_left;
  double PB = 1.00 - AP;
  std::cout << AP << '\n' << PB << '\n';
}
