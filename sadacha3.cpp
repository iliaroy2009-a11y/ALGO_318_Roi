#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
// Завдання 1. If14
// Вивести спочатку найменше, потім найбільше число.
void task_if14()
{
    double a, b, c;
cout << "Enter three numbers: ";
if (!(cin >> a >> b >> c))
{
    cout << "Wrong input!" << endl;
    return;
}

double mn = min(a, min(b, c));
double mx = max(a, max(b, c));

cout << "Minimum: " << mn << endl;
cout << "Maximum: " << mx << endl;
}
// Завдання 2. If28
// Визначити кількість днів у році.
void task_if28()
{
    int year;
cout << "Enter year: ";
if (!(cin >> year) || year <= 0)
{
    cout << "Wrong year!" << endl;
    return;
}

// Рік високосний, якщо ділиться на 400
// або ділиться на 4, але не на 100.
if (year % 400 == 0 ||
    (year % 4 == 0 && year % 100 != 0))
{
    cout << "Days: 366" << endl;
}
else
{
    cout << "Days: 365" << endl;
}
}
// Завдання 3. Геометрична фігура, варіант 13
// Перевіряємо належність точки зеленим областям.
void task_geom13()
{
    double r, x, y;
cout << "Enter radius r: ";
if (!(cin >> r) || r <= 0)
{
    cout << "Wrong radius!" << endl;
    return;
}

cout << "Enter coordinates x and y: ";
if (!(cin >> x >> y))
{
    cout << "Wrong coordinates!" << endl;
    return;
}

// Коло у верхній правій частині рисунка.
double d1 = (x - r) * (x - r)
          + (y - r) * (y - r);

// Коло у нижній лівій частині рисунка.
double d2 = (x + r) * (x + r)
          + (y + r) * (y + r);

// Зелена область верхнього кола.
bool green1 = (d1 <= r * r &&
               x >= r && y <= r &&
               y >= 2 * r - x);

// Зелена область нижнього кола.
bool green2 = (d2 <= r * r &&
               x >= -r && y >= -r &&
               x + y >= -2 * r);

if (green1 || green2)
    cout << "The point belongs to the green area."
         << endl;
else
    cout << "The point does NOT belong to the green area."
         << endl;
}
int main()
{
    int menu;
cout << "===== MENU =====" << endl;
cout << "1 - If14" << endl;
cout << "2 - If28" << endl;
cout << "3 - Geometric task (variant 13)" << endl;
cout << "Choose task: ";

if (!(cin >> menu))
{
    cout << "Wrong menu input!" << endl;
    return 1;
}

// Вибір завдання за допомогою switch.
switch (menu)
{
    case 1:
        task_if14();
        break;

    case 2:
        task_if28();
        break;

    case 3:
        task_geom13();
        break;

    default:
        cout << "Wrong task! Choose 1, 2 or 3."
             << endl;
}

return 0;
}