/// Задача 11. Тяжело в учении, легко в бою (необязательная)
/* Вы встретились со своим старым другом, который тоже изучает программирование,
 * правда, в другом учебном заведении. За чашкой кофе он пожаловался вам, что
 * сумасбродный препод дал им задание написать программу, которая из двух
 * введённых чисел определяет наибольшее, не используя при этом условных
 * операторов и циклов. Радуясь, что на вашем курсе такого не требуют, вы
 * всё-таки решаете помочь своему другу. Напишите для него эту программу.*/

#include <iostream>

/// Функция нахождения максимального числа из 2-х введенных чисел
/// \param a -- 1 число
/// \param b -- 2 число
/// \return -- максимальное значение.
// Ссылки, чтобы не делать копию переданных переменных.
inline float findMaximumOfTwoNumbers(float &a, float &b) {
  return std::max(a, b);
}

int main() {
  std::cout << "Введите 2 числа: ";
  float a, b;
  std::cin >> a >> b;

  std::cout << "Минимум из " << a << " и " << b << " равен "
            << findMaximumOfTwoNumbers(a, b);

  return 0;
}
