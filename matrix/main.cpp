#include "matrix.h"

int main()
{
  Matrix my;
  std::cin >> my;
  std::cout << my << "------" << std::endl;
  Matrix res = my * 2;
  std::cout << res;

  const double a[] = {1, 2, 3, 2, 4, 6};
  const double b[] = {2, 2, 2};
  const double c[] = {1, 1, 1, 1};
  Matrix m2(2, 3, a);
  Matrix m3(3, 1, b);
  std::cout << m2 * m3;
  std::cout << "--------" << std::endl;
  std::cout << m2 + m2;
  std::cout << m2 << m2[1][1];
  std::cout << std::endl << "--------" << std::endl;
  m2 *= m3;
  m2 *= 0.5;
  std::cout << m2;
  Matrix assignTest(2, 2, c);

  std::cout << "Test assignment:" << std::endl;
  std::cout << "Was assignTest[1][1] = " << assignTest[1][1] << std::endl;
  assignTest[1][1] = 2;
  std::cout << "Became assignTest[1][1] = " << assignTest[1][1] << std::endl;

  return 0;
}
