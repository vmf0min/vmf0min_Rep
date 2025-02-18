/// Задача 3. Крепкий орешек.
/// Мы разрабатываем пошаговую игру по мотивам боевика. Игрок — главный герой и
/// должен обезвредить бомбу, которая взорвётся через 10 итераций цикла.
/// Программа спрашивает пользователя хочет ли он перерезать провод сейчас. Если
/// ответ “нет”, то счетчик бомбы уменьшается. Если он достиг нуля, то программа
/// выдаёт сообщение “Бомба взорвалась”, а если не достиг, то программа вновь
/// переспрашивает, не хочет ли игрок обезвредить бомбу, и сообщает, сколько
/// времени осталось до взрыва. Если ответ “да”, то программа выводит на экран
/// сообщение о том, что бомба обезврежена и сколько шагов оставалось до взрыва.
/// Используйте цикл for.

#include <iostream>

int main() {
    std::string answer;

    for (int i = 10; i >= 0; i--) {
        std::cout << "Хотите перерезать провод сейчас? ";
        std::cin >> answer;

        if ("да" == answer) {
            std::cout << i << "\n";
            break;
        }

        if (i == 0) {
            std::cout << "Бомба взорвалась!\n";
            break;
        }

        std::cout << i << "\n";
    }


    return 0;
}
