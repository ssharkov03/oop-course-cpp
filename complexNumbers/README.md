# Lab 1.1
Спроектирован и реализован класс для работы с комплексными числами.
Комплексные числа представлены в форме $z = \text{Re}(z) + i \cdot \text{Im}(z).$
Для представления закрытых данных класса использованы переменные с плавающей точкой.
Реализованы следующие конструкторы: по умолчанию, с одним аргументом ( $\text{Re}(z)$ ), с двумя аргументами.
Перегружены следующие операторы: ```+, -, *, /, ==, !=, istream& operator>>(...), ostream& operator<<(...)```.
Арифметические операции перегружены и для использования с вещественными числами в качестве аргумента.
Реализован метод для печати комплексного числа в показательной форме - ```void printExponentialForm()```.
