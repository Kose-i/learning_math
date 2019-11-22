/*
60未満で3で割ったらaあまり、4でわったらbあまり、5で割ったらc余る数を求める．
*/

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

int number_1st_edition(const int& a, const int& b, const int& c) {
  std::vector<int> a_vec(60);
  std::iota(a_vec.begin(), a_vec.end(), 1);
  for (const auto& e : a_vec) {
      if (e % 3 == a && e % 4 == b && e % 5 == c) {
        return e;
      }
  }
  return -1;
}

std::vector<std::vector<int>> number_2nd_edition() {
  std::vector<std::vector<int>> answer(60, std::vector<int>(3));
  for (auto i = 0;i < 60;++i) {
      answer[i][0] = (i+1) % 3;
      answer[i][1] = (i+1) % 4;
      answer[i][2] = (i+1) % 5;
  }
  return answer;
}

int main(int argc, char** argv) {

  const int a {1};
  const int b {2};
  const int c {4};

  std::cout << number_1st_edition(a,b,c) << '\n';

  auto ans = number_2nd_edition();
  std::sort(ans.begin(), ans.end());
  for (const auto& e : ans) {
    for (const auto& t : e) {
      std::cout << t << ' ';
    }
    std::cout << '\n';
  }
}


