
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

// Функція для введення цілого числа
int readInt(string message) {
    int value;

    while (true) {
        cout << message;
        if (cin >> value) {
            return value;
        }

        cout << "Помилка! Введіть ціле число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Функція для введення дійсного числа
double readDouble(string message) {
    double value;

    while (true) {
        cout << message;

        if (cin >> value && isfinite(value)) {
            return value;
        }

        cout << "Помилка! Введіть коректне число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// =====================================
// ЗАВДАННЯ 1. ВАРІАНТ 36
// Підрахунок точок у коричневій області
// =====================================

void task1() {
    int n;
    double r;

    cout << "\n--- Завдання 1. Варіант 36 ---\n";

    // Введення радіуса
    do {
        r = readDouble("Введіть радіус кола r: ");
        if (r <= 0)
            cout << "Радіус повинен бути більшим за 0!\n";
    } while (r <= 0);

    // Введення кількості точок
    do {
        n = readInt("Введіть кількість точок: ");
        if (n <= 0)
            cout << "Кількість повинна бути більшою за 0!\n";
    } while (n <= 0);

    int count = 0;

    // Перевірка кожної точки
    for (int i = 1; i <= n; i++) {
        double x = readDouble("x = ");
        double y = readDouble("y = ");

        // Перевірка верхнього трикутника
        bool triangle =
            (x >= 0 && y >= 0 &&
             y >= x && x + y <= 2 * r);

        // Перевірка нижнього сегмента кола
        bool circle =
            (y <= 0 &&
             (x - r) * (x - r) +
             (y - r) * (y - r) <= r * r);

        // Якщо точка потрапила в одну з частин
        if (triangle || circle) {
            count++;
        }
    }

    cout << "\nКількість точок у коричневій області: "
         << count << endl;
}

// =====================================
// ЗАВДАННЯ 2. ВАРІАНТ 16
// Обчислення суми ряду
// =====================================

void task2() {
    cout << "\n--- Завдання 2. Варіант 16 ---\n";

    double x = readDouble("Введіть x: ");

    int n;
    do {
        n = readInt("Введіть натуральне n: ");
        if (n <= 0)
            cout << "n повинно бути більшим за 0!\n";
    } while (n <= 0);

    double sum = 1;
    double element = 1;

    // Обчислення елементів ряду
    for (int k = 1; k <= n; k++) {

        // Отримання наступного елемента
        element *= (2.0 * k - 1) /
                   (2.0 * k) * x * x;

        // Додавання до суми
        sum += element;

        // Виведення кожного третього елемента
        if (k % 3 == 0) {
            cout << "Елемент " << k
                 << ": " << element << endl;
        }
    }

    cout << "\nСума ряду = " << sum << endl;
}

// =====================================
// ЗАВДАННЯ 3. ВАРІАНТ 1
// Дослідження ряду на збіжність
// =====================================

void task3() {
    cout << "\n--- Завдання 3. Варіант 1 ---\n";

    double eps;

    do {
        eps = readDouble("Введіть точність eps: ");
        if (eps <= 0 || eps >= 1)
            cout << "Точність повинна бути між 0 та 1!\n";
    } while (eps <= 0 || eps >= 1);

    double g;

    do {
        g = readDouble("Введіть граничне значення g: ");
        if (g <= 0)
            cout << "g повинно бути більшим за 0!\n";
    } while (g <= 0);

    long double sum = 0;
    long double element;
    int n = 1;

    // Формат виведення з 15 знаками після коми
    cout << fixed << setprecision(15);

    cout << "\nНаростаюча сума:\n";

    // Обчислення ряду
    while (true) {

        // Обчислення чергового елемента через логарифм
        long double logElement =
            1.5L * log((long double)n) +
            n * (log(2.0L) - log((long double)n));

        element = exp(logElement);

        // Перевірка умов завершення
        if (fabs(element) < eps) {
            cout << "\nЕлемент став меншим за eps.\n";
            break;
        }

        if (fabs(element) > g) {
            cout << "\nЕлемент перевищив g.\n";
            break;
        }

        // Додавання елемента до суми
        sum += element;

        cout << "n = " << n
             << "  element = " << element
             << "  sum = " << sum << endl;

        n++;

        // Захист від надто довгого циклу
        if (n > 1000000) {
            cout << "Досягнуто межу обчислень.\n";
            break;
        }
    }

    cout << "\nСума ряду = " << sum << endl;
    cout << "Кількість доданих елементів = "
         << n - 1 << endl;

    cout << "Ряд є збіжним.\n";
}

// =====================================
// ГОЛОВНА ФУНКЦІЯ. МЕНЮ ПРОГРАМИ
// =====================================

int main() {
    int menu;

    do {
        cout << "\n========== МЕНЮ ==========\n";
        cout << "1 - Завдання 1 (варіант 36)\n";
        cout << "2 - Завдання 2 (варіант 16)\n";
        cout << "3 - Завдання 3 (варіант 1)\n";
        cout << "0 - Вихід\n";
        cout << "==========================\n";

        menu = readInt("Оберіть завдання: ");

        switch (menu) {
            case 1:
                task1();
                break;

            case 2:
                task2();
                break;

            case 3:
                task3();
                break;

            case 0:
                cout << "Завершення програми...\n";
                break;

            default:
                cout << "Неправильний номер завдання!\n";
        }

    } while (menu != 0);

    return 0;
}
