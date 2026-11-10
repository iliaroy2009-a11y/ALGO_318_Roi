#include <iostream>
using namespace std;

// ===== ОГОЛОШЕННЯ ФУНКЦІЙ =====

// Завдання 1. Визначення типу трикутника
int TriangleType(int a, int b, int c);

// Перевірка сторін трикутника
bool InputTriangle(int &a, int &b, int &c);

// Завдання 1. Визначення дня тижня
int DayOfWeek(int K);

// Завдання 2. Введення тризначного числа
bool InputNumber(int &n);

// Обчислення суми та добутку цифр
void Calculate(int n, int &sum, int &product);

// Виведення результату
void Output(int sum, int product);

// Окремі процедури завдань
void TaskTriangle();
void TaskDay();
void TaskDigits();

int main()
{
    int choice;

    // Головне меню програми
    cout << "===== LABORATORY WORK 4 =====" << endl;
    cout << "1. Triangle type" << endl;
    cout << "2. Day of the week" << endl;
    cout << "3. Sum and product of digits" << endl;
    cout << "Choose task: ";
    cin >> choice;

    // Вибір завдання
    switch (choice)
    {
        case 1:
            TaskTriangle();
            break;

        case 2:
            TaskDay();
            break;

        case 3:
            TaskDigits();
            break;

        default:
            cout << "Wrong menu choice!" << endl;
    }

    return 0;
}

// ===== ВИЗНАЧЕННЯ ФУНКЦІЙ =====

// Перевірка правильності введених сторін
bool InputTriangle(int &a, int &b, int &c)
{
    cout << "Enter three triangle sides: ";
    cin >> a >> b >> c;

    if (cin.fail())
        return false;

    if (a <= 0 || b <= 0 || c <= 0)
        return false;

    if (a > 100 || b > 100 || c > 100)
        return false;

    if (a + b <= c || a + c <= b || b + c <= a)
        return false;

    return true;
}

// Визначення типу трикутника
int TriangleType(int a, int b, int c)
{
    // Знаходимо найбільшу сторону
    int temp;

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    // Порівнюємо квадрати сторін
    if (a * a + b * b == c * c)
        return 0;

    if (a * a + b * b > c * c)
        return 1;

    return -1;
}

// Визначення номера дня тижня
int DayOfWeek(int K)
{
    return K % 7;
}

// Введення тризначного числа
bool InputNumber(int &n)
{
    cout << "Enter a three-digit number: ";
    cin >> n;

    if (cin.fail())
        return false;

    if (n < 100 || n > 999)
        return false;

    return true;
}

// Обчислення суми та добутку цифр
void Calculate(int n, int &sum, int &product)
{
    int a = n / 100;
    int b = (n / 10) % 10;
    int c = n % 10;

    sum = a + b + c;
    product = a * b * c;
}

// Виведення результатів
void Output(int sum, int product)
{
    cout << "Sum of digits: " << sum << endl;
    cout << "Product of digits: " << product << endl;
}

// ===== ПРОЦЕДУРА ЗАВДАННЯ 1 =====

// Визначення типів трьох трикутників

void TaskTriangle()
{
    int a, b, c;
    int result;

    // Перший трикутник
    cout << "\nTriangle 1:" << endl;
    if (!InputTriangle(a, b, c))
    {
        cout << "Incorrect input!" << endl;
        return;
    }
    result = TriangleType(a, b, c);

    if (result == 1) cout << "Acute triangle" << endl;
    else if (result == 0) cout << "Right triangle" << endl;
    else cout << "Obtuse triangle" << endl;

    // Другий трикутник
    cout << "\nTriangle 2:" << endl;
    if (!InputTriangle(a, b, c))
    {
        cout << "Incorrect input!" << endl;
        return;
    }
    result = TriangleType(a, b, c);

    if (result == 1) cout << "Acute triangle" << endl;
    else if (result == 0) cout << "Right triangle" << endl;
    else cout << "Obtuse triangle" << endl;

    // Третій трикутник
    cout << "\nTriangle 3:" << endl;
    if (!InputTriangle(a, b, c))
    {
        cout << "Incorrect input!" << endl;
        return;
    }
    result = TriangleType(a, b, c);

    if (result == 1) cout << "Acute triangle" << endl;
    else if (result == 0) cout << "Right triangle" << endl;
    else cout << "Obtuse triangle" << endl;
}

// ===== ПРОЦЕДУРА ЗАВДАННЯ 2 =====

// Визначення дня тижня
void TaskDay()
{
    int K;

    cout << "Enter K (1-365): ";
    cin >> K;

    if (cin.fail() || K < 1 || K > 365)
    {
        cout << "Incorrect input!" << endl;
        return;
    }

    int day = DayOfWeek(K);

    if (day == 0)
        cout << "Sunday" << endl;
    else if (day == 1)
        cout << "Monday" << endl;
    else if (day == 2)
        cout << "Tuesday" << endl;
    else if (day == 3)
        cout << "Wednesday" << endl;
    else if (day == 4)
        cout << "Thursday" << endl;
    else if (day == 5)
        cout << "Friday" << endl;
    else
        cout << "Saturday" << endl;
}

// ===== ПРОЦЕДУРА ЗАВДАННЯ 3 =====

// Знаходження суми та добутку цифр
void TaskDigits()
{
    int n, sum, product;

    if (!InputNumber(n))
    {
        cout << "Incorrect input! Enter a number from 100 to 999."
             << endl;
        return;
    }

    Calculate(n, sum, product);
    Output(sum, product);
}