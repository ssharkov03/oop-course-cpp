Спроектирован и реализован класс, предназначенный для работы с матрицами различных размеров.
Реализованы следующие конструкторы: по умолчанию, по паре целых чисел, задающих размер матрицы, конструктор копирования.
Перегружены следующие операторы: ```+, -, *, [], =, +=, -=, *=, ==, !=, istream& operator>>(...), ostream& operator<<(...)```.
Операторы умножения перегружены и для использования с вещественными числами в качестве аргумента.
Реализован деструктор.

В качестве дополнительного функционала был реализован конструктор по паре целых чисел, задающих размер матрицы, и 
одномерному массиву, задающему содержание матрицы.