#include <iostream>
#include <cmath>

long factoria(int a)
{
  long ans = 1;
  for (int i = 0;i <= a;++i) ans*= i;
  return ans;
}

double get_pi()
{
  double my_pi = 0;
  my_pi = (std::pow(99,2)/ (2*std::sqrt(2)) )*(1)/ (1103);
  return my_pi;
}

int main(int argc, char** argv){
  std::cout << get_pi() << '\n';
}
