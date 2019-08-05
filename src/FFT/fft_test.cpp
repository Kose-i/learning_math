#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

constexpr double PI = 3.14159265358979;

template <typename T>
constexpr void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

std::vector<double> four1(std::vector<std::complex<double>>& data_complex, int isign) {

  unsigned long nn = data_complex.size();
  std::vector<double> Fourier_transform(data_complex.size()*2);
  for (auto i = 0;i < nn;++i) {
    Fourier_transform[2*i] = real(data_complex[i]);
    Fourier_transform[2*i + 1] = imag(data_complex[i]);
  }
  double wtemp, wr, wpr, wpi, wi, theta;
  float tempr, tempi;

  unsigned long n = (nn << 1);
  for (auto i = 1, j = 1;i < n;i+=2) {
    if (j > i) {
      swap(Fourier_transform[j], Fourier_transform[i]);
      swap(Fourier_transform[j + 1], Fourier_transform[i + 1]);
    }
    auto m = (n>>1);
    while (m >= 2 && j > m) {
      j -= m;
      m >>= 1;
    }
    j += m;
  }

  unsigned long mmax = 2;
  while (n > mmax) {
    auto istep = (mmax << 1);
    theta = isign*(PI*2/mmax);
    wtemp = sin(0.5*theta);
    wpr = -2.0*wtemp*wtemp;
    wpi = std::sin(theta);
    wr = 1.0;
    wi = 0.0;
    for (auto m = 1;m < mmax;m+=2) {
      for (auto i = m;i<=n;i+=istep) {
        auto j = i+mmax;
        tempr = wr*Fourier_transform[j]-wi*Fourier_transform[j+1];
        tempi = wr*Fourier_transform[i + 1]+wi*Fourier_transform[j];
        Fourier_transform[j] = Fourier_transform[i] - tempr;
        Fourier_transform[j + 1] = Fourier_transform[i + 1] - tempi;
        Fourier_transform[i] += tempr;
        Fourier_transform[i + 1] += tempi;
      }
      wr=(wtemp=wr)*wpr-wi*wpi+wr;
      wi = wi*wpr+wtemp*wpi+wi;
    }
    mmax = istep;
  }
  return Fourier_transform;
}

int main(int argc, char** argv) {
  std::vector<std::complex<double>> sampling_data{
    std::complex<double>(2.2, 1.1),
    std::complex<double>(3.4, 3.1),
    std::complex<double>(3.3, 2.1),
    std::complex<double>(3.2, 1.1)
  };

  for (const auto& e : sampling_data) {
    std::cout << '(' << real(e) << ',' << imag(e) << ')';
  }
  std::cout << '\n';

  auto t = four1(sampling_data, 1);//Fourier Transform

  for (const auto& e : t) {
    std::cout << ' ' << e;
  }
  std::cout << '\n';

  exit(1); //TODO

  four1(sampling_data, -1);//Inverter Fourier Transform

  for (const auto& e : sampling_data) {
    std::cout << ' ' << e;
  }
  std::cout << '\n';
}
