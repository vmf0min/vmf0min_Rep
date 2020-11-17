/// Задача 4. Коллекторы 2.0.
/// Улучшите робота-коллектора. Теперь сумма долга должна уменьшаться, если
/// пользователь ввел сумму, меньшую чем сумму долга. Также обеспечьте контроль
/// ввода. Если пользователь внес большую сумму, чем требуется для погашения,
/// выведите сообщение о том, какой у него остаток на счету после такой операции.

#include <iostream>

int main() {
    std::string name;
    int debt;
    int debtRepayment = 0;

    std::cout << "Имя должника и сумма задолженности: ";
    std::cin >> name >> debt;

    // флажок погашения. По умолчанию false.
    bool isPaid = false;

    while (!isPaid) {
        std::cout << name << ", ваша задолженность составляет " << debt << " рублей.\n"
                  << "Сколько рублей вы внесете прямо сейчас, чтобы ее погасить?\n";
        std::cin >> debtRepayment;

        // Если сумма долга = 0 или меньше -- значит выплачен долг.
        isPaid = (debt -= debtRepayment) <= 0;

        debtRepayment = 0;
    }

    std::cout << name << ", вы выплатили долг! Остаток по счету: " << abs(debt) << " рублей.\n";

    return 0;
}