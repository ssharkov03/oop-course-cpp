#include "matrix.h"
#include "complexNumbers.h"
int main()
{
  std::vector<int> a{1,2,3,4,5,6};
  Matrix<int> test1(3, 2, a);
  Matrix<int> test2(2, 3, a);
  for(auto i : test1)
  {
    std::cout << i << std::endl;
  }
  std::cout << *test1.begin() + 1 << std::endl;
  std::cout << test1 << std::endl;
  std::cout << test1 * test2 << std::endl;

  std::cout << std::endl;
  std::cout << std::endl <<"Testing double." << std::endl;

//  Matrix <double> my;
//  std::cin >> my;
//  std::cout << my << "------" << std::endl;
//  Matrix res = my * 2;
//  std::cout << res;

  const std::vector <double> a1{1, 2, 3, 2, 4, 6};
  const std::vector <double> b{2, 2, 2};
  const std::vector <double> c{1, 1, 1, 1};
  Matrix <double> m2(2, 3, a1);
  Matrix <double> m3(3, 1, b);
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

  std::cout << std::endl;
  std::cout << std::endl <<"Testing complex numbers." << std::endl;

  Complex c1(0, -1);
  Complex c2(2, 0);
  Complex c3(1, 1);
  Complex c4(1, 2);

  std::vector <Complex> compl_vec1{c1, c2, c3, c4};
  std::vector <Complex> compl_vec2{c1, c3, c2, c4};
  Matrix <Complex> compl_mat1(2, 2, compl_vec1);
  Matrix <Complex> compl_mat2(2, 2, compl_vec2);

  Matrix <Complex> compl_prod = compl_mat1 * compl_mat2;;
  std::cout << compl_prod << "-------\n";
  std::cout << compl_mat1 + compl_mat2;

  return 0;
}
