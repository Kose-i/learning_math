#include <iostream>
#include <cmath>

namespace Kosei{
  constexpr double PI {3.14159265};
  constexpr double EXP {2.71828182};
  double factorial(const double& t) {
    return std::sqrt(2*PI*t)*std::pow((t/Kosei::EXP),t)*(1+1/(12*t));
  };
};

int main(int argc, char** argv) {
  const double t {3.2};
  std::cout << t << "!=" << Kosei::factorial(t) << '\n';
}
