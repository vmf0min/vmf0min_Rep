/// Задача 4. Игрушечная история
// Вы решили открыть бизнес по производству игровых деревянных кубиков для детей.
// Вы узнали, что лучше всего продаются кубики со стороной 5 сантиметров в
// наборах по несколько штук, причём кубиков в наборе должно быть достаточно,
// чтобы сложить из них один большой куб. Для изготовления кубиков к вам в
// мастерскую поступают деревянные бруски в форме прямоугольных параллелепипедов
// любых размеров.
// Для оптимизации бизнес-процессов напишите программу, которая по заданным
// размерам исходного бруска определяет, сколько кубиков из него можно изготовить,
// можно ли из них составить набор для продажи, и если можно, то максимальное
// число кубиков в этом наборе. Все кубики должны быть из цельного дерева без
// использования клея. Размеры бруска — вещественные числа.
// Обеспечьте контроль ввода.
// Пример
/*
Ввод:
Введите размеры бруска
X: 5;
Y: 35.76;
Z: 35.05.
Вывод:
Из этого бруска можно изготовить 49 кубиков.
Из них можно составить набор из 27 кубиков.
*/

#include <iostream>
#include <cmath>

int main() {
  std::cout << "Ввод:\nВведите размеры бруска\n";
  std::cout << "X: ";
  float x;
  std::cin >> x;

  std::cout << "Y: ";
  float y;
  std::cin >> y;

  std::cout << "Z: ";
  float z;
  std::cin >> z;

  if (x < 5 || y < 5 || z < 5) {
    std::cout << "Одна из сторон меньше 5 см!\n";
    return -1;
  }

  // Отсекаем дробную часть.
  x = std::floor(x);
  y = std::floor(y);
  z = std::floor(z);

  // Учитываю лишние см для вырезания 1 кубика.
  int excessX = static_cast<int>(x) % 5;
  int excessY = static_cast<int>(y) % 5;
  int excessZ = static_cast<int>(z) % 5;

  // Находим объем бруска с учетом излишков материала и делим его на
  // кубик 5 * 5 * 5 см.
  int cubes = static_cast<int>((x - static_cast<float>(excessX)) *
                               (y - static_cast<float>(excessY)) *
                               (z - static_cast<float>(excessZ)) /
                               powf(5, 3));
  std::cout << "Вывод:\nИз этого бруска можно изготовить " << cubes
            << " кубиков.\n";

  // Извлекаю кубический корень из всего количества кубиков. Отсекаю дробную
  // часть (можно при желании статик_каст<инт>). Возвожу в куб. Получаю набор.
  int set = std::pow(std::floor(std::cbrt(cubes)), 3);

  set <= 1 ? std::cout << "Нельзя составить набор из 1 кубика.\n"
           : std::cout << "Из них можно составить набор из " << set
                       << " кубиков.\n";

  return 0;
}