#include <iostream>

namespace Kosei{
  constexpr int sqrt_helper(int a, int b, int z) {
    return (z < a)? b : sqrt_helper(a+b, b+2, z);
  }
  constexpr int sqrt(const int& t) {
    return Kosei::sqrt_helper(1,3,t)/2 -1;
  }
}

int main(int argc, char** argv) {
  std::cout << "Input(int):";
  const int target {[]{int a;std::cin>>a;return a;}()};
  const int target_answer = Kosei::sqrt(target);
  std::cout << "sqrt(" << target << ")= "<< target_answer << '\n';
  std::cout << target_answer << "^2=" <<  target_answer*target_answer << '\n';
  std::cout << target_answer+1 << "^2=" <<  (target_answer+1)*(target_answer+1) << '\n';
}
