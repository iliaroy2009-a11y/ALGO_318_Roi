#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ===== ОГОЛОШЕННЯ ФУНКЦІЙ =====

// Завдання 1. Визначення типу трикутника
int TriangleType(int a, int b, int c);
bool InputTriangle(int &a, int &b, int &c);

// Завдання 2. Обчислення складних відсотків
void CompoundInterest(double P, double r, int n, double &A);

// Завдання 3. Введення тризначного числа
bool InputNumber(int &n);

// Обчислення суми та добутку цифр
void Calculate(int n, int &sum, int &product);

// Виведення результату
void Output(int sum, int product);

// Процедури завдань
void TaskTriangle();
void TaskInterest();
void TaskDigits();

int main()
{
int choice;

cout << "===== LABORATORY WORK 4 =====" << endl;
cout << "1. Triangle type" << endl;
cout << "2. Compound Interest" << endl;
cout << "3. Sum and product of digits" << endl;
cout << "Choose task: ";
cin >> choice;

switch (choice)
{
    case 1:
        TaskTriangle();
        break;

    case 2:
        TaskInterest();
        break;

    case 3:
        TaskDigits();
        break;

    default:
        cout << "Wrong menu choice!" << endl;
}

return 0;
}

// ===== ЗАВДАННЯ 1 =====

bool InputTriangle(int &a, int &b, int &c)
{
cout << "Enter three triangle sides: ";
cin >> a >> b >> c;

if (cin.fail())
    return false;

if (a <= 0 || b <= 0 || c <= 0)
    return false;

if (a > 100  b > 100  c > 100)
    return false;

if (a + b <= c  a + c <= b  b + c <= a)
    return false;

return true;
}

int TriangleType(int a, int b, int c)
{
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

if (a * a + b * b == c * c)
    return 0;

if (a * a + b * b > c * c)
    return 1;

return -1;
}

// ===== ЗАВДАННЯ 2 =====

// Обчислення складних відсотків
void CompoundInterest(double P, double r, int n, double &A)
{
A = P * pow(1 + r, n);
}

// Процедура трьох інвестицій
void TaskInterest()
{
double P, r, A;
int n;

for (int i = 1; i <= 3; i++)
{
    cout << "\nInvestment " << i << endl;

    cout << "Enter initial amount (P): ";
    cin >> P;

    cout << "Enter annual interest rate (%): ";
    cin >> r;

    cout << "Enter number of years (n): ";
    cin >> n;

    if (cin.fail()task: ";
cin r < 0 || n < 0)
    {
        cout << "Incorrect input!" << endl;
        return;
    }

    r = r / 100;

    CompoundInterest(P, r, n, A);

    cout << fixed << setprecision(2);
    cout << "Future value (A): " << A << endl;
}
}

// ===== ЗАВДАННЯ 3 =====

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

void Calculate(int n, int &sum, int &product)
{
int a = n / 100;
int b = (n / 10) % 10;
int c = n % 10;

sum = a + b + c;
product = a * b * c;
}

void Output(int sum, int product)
{
cout << "Sum of digits: " << sum << endl;
cout << "Product of digits: " << product << endl;
}

// ===== ПРОЦЕДУРА ЗАВДАННЯ 1 =====

void TaskTriangle()
{
int a, b, c;
int result;

for (int i = 1; i <= 3; i++)
{
    cout << "\nTriangle " << i << endl;

    if (!InputTriangle(a, b, c))
    {
        cout << "Incorrect input!" << endl;
        return;
    }

    result = TriangleType(a, b, c);

    if (result == 1)
        cout << "Acute triangle" << endl;
    else if (result == 0)
        cout << "Right triangle" << endl;
    else
        cout << "Obtuse triangle" << endl;
}
}

// ===== ПРОЦЕДУРА ЗАВДАННЯ 3 =====

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
