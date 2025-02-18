/// Задача 8. Зарплата (необязательная).
/// В отделе маркетинга работают 3 сотрудника. У каждого разные зарплаты. Напишите программу, которая вычисляет
/// разницу между самой высокой и низкой зарплатой сотрудника, а также среднюю зарплату отдела.

#include <iostream>

int main() {
    int a, b, c, min, max, diff;
    float avg;

    std::cout << "Введите зарплаты 3 сотрудников через пробел: ";
    std::cin >> a >> b >> c;

    // Начальные условия
    min = a;
    max = a;

    if (b < min) min = b;
    if (c < min) min = c;

    if (b > max) max = b;
    if (c > max) max = c;

    diff = max - min;

    avg = (float) (a + b + c) / 3;

    std::cout << "Минимальная зарплата: " << min << "\nМаксимальная зарпалата: " << max
              << "\nРазница: " << diff << "\nСредняя зарплата: " << avg << "\n";

    return 0;
}
