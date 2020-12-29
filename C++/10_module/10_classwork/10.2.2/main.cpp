/// Задача 2. Сумма чисел (цикл for).
/// Перепишите программу из прошлого модуля, используя цикл for. У бухгалтера
/// сломались счеты. Напишите программу, которая считала бы сумму вводимых чисел.
/// В начале у бухгалтера спрашивают, сколько чисел тот хочет сложить, затем
/// нужное количество раз просят ввести число и в конце выводят получившуюся сумму.

#include <iostream>

int main() {
    int sum;   // Сумма вводимых чисел.
    int n;     // Количество чисел для суммы.

    std::cout << "Введите общее количество чисел для сложения: ";
    std::cin >> n;

    if (1 == n) {
        std::cout << "Общее количество чисел для сложения должно быть "
                     "минимум 2!\n";
        return -1;
    }

    for (int count = 0; count < n; count++) {
        int x;
        std::cout << "Введите число: ";
        std::cin >> x;
        sum += x;
    }

    std::cout << "\nСумма = " << sum << "\n";

    return 0;
}