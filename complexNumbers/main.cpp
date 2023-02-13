#include "complexNumbers.h"

int main()
{
  Complex c1(0, -1);
  Complex c2(2, 0);
  std::cout << "c1 / c2 = " << c1 / c2 << std::endl;
  std::cout << "is c1 != c2: " << (c1 != c2) << std::endl;
  std::cout << "(c1 + c2) * c2 = " << (c1 + c2) * c2 << std::endl;
  c2 = (c1 + c2) * c2;
  std::cout << "new c2 = " << c2 << std::endl;
  std::cout << "cout test: " << c1 << std::endl;
  std::cout << "exponential form: ";
  c1.printExponentialForm();
  return 0;
}
