#include <iostream>

int main(int argc, char** argv) {
  unsigned long t {10};
  unsigned long fact_ans {1};
  for (auto i = 1;i <= t;++i) {
    fact_ans *= i;
  }
  std::cout << fact_ans << '\n';
}
