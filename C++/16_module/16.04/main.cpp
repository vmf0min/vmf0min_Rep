/**
 * @file      main.cpp
 * @author    vmf0min (vlifom@yandex.ru)
 * @brief     Задача 4. Механическое пианино.
 * Создать упрощённую модель механического пианино. Всего у данного пианино - 7
 * клавиш, соответствуют они семи нотам. Каждая клавиша кодируется уникальной
 * битовой маской, которая записывается в enum. Вначале программы пользователь
 * вводит мелодию. Ввод осуществляется с помощью цифр на клавиатуре, от 1 до 7
 * включительно (от ноты “до” до ноты “си”). В результате из чисел может быть
 * составлена любая комбинация нот. К примеру 512 или 154. После ввода
 * комбинации, вводится следующая. Всего таких комбинаций нот - 12. Как только
 * все комбинации были введены пользователем, мелодия проигрывается. Для этого
 * каждая комбинация нот последовательно выводится на экран. Однако, на этот раз
 * она печатается “красиво”, т.е. все ноты указываются словами, а не цифрами.
 * При этом слова разделяются пробелами.
 * @version   0.1
 * @date      09-03-2021
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <sstream>

using std::cin;
using std::cout;

enum class Piano {
  DO = 1 << 0,
  RE = 1 << 1,
  MI = 1 << 2,
  FA = 1 << 3,
  SO = 1 << 4,
  LA = 1 << 5,
  SI = 1 << 6,
};

/**
 * @brief     print melody to console with musician's mistakes
 * @param     noteCombination  musical combination
 */
void printNotes(const std::string& noteCombination) {
  for (int i{}; i < noteCombination.length(); ++i) {
    int32_t note = noteCombination[i] - '0';
    cout << "\x1b[32m";
    switch (1 << (note - 1)) {
      case static_cast<int32_t>(Piano::DO):
        cout << "Do";
        break;
      case static_cast<int32_t>(Piano::RE):
        cout << "Re";
        break;
      case static_cast<int32_t>(Piano::MI):
        cout << "Mi";
        break;
      case static_cast<int32_t>(Piano::FA):
        cout << "Fa";
        break;
      case static_cast<int32_t>(Piano::SO):
        cout << "So";
        break;
      case static_cast<int32_t>(Piano::LA):
        cout << "La";
        break;
      case static_cast<int32_t>(Piano::SI):
        cout << "Si";
        break;
    }
  }
  cout << " \x1b[0m";
}

/**
 * @brief     check the valid notes
 * @param     noteCombination  musical combination
 * @return    true             notes is valid
 */
bool checkNoteCombination(std::string& noteCombination) {
  for (size_t i{}; i < noteCombination.length(); ++i) {
    if (noteCombination[i] < '1' || noteCombination[i] > '7') {
      cout << "Error: incorrect note!\n";
      return false;
    }
  }
  return true;
}

int main() {
  cout << "\x1b[2J";
  std::stringstream musicNotation;
  std::string noteCombination;
  for (size_t i{}; i < 12; ++i) {
    cout << "Enter the music combination: ";
    cin >> noteCombination;
    if (!checkNoteCombination(noteCombination)) continue;

    musicNotation << noteCombination << " ";
  }

  cout << "\nYour music composition:\n";
  for (size_t i{}; i < 12; ++i) {
    musicNotation >> noteCombination;
    printNotes(noteCombination);
  }

  cout << "\n";
  return 0;
}