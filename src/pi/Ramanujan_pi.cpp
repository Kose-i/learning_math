#include <iostream>
#include <cmath>

namespace Ramanujan_pi{
  double get_pi() {
    double my_pi = 0;
    my_pi = (std::pow(99,2)/ (2*std::sqrt(2)) )*(1)/ (1103);
    return my_pi;
  };
}

int main(int argc, char** argv){
  std::cout << Ramanujan_pi::get_pi() << '\n';
}
