#include <iostream>
using namespace std;

class FuzzyNumbers {    
public:
    int middle;
    int left;
    int right;
    // Пустой конструктор
    FuzzyNumbers() {
        middle = 0;
        left = 0;
        right = 0;
    }

    // Конструктор, принимающий все параметры
    FuzzyNumbers(int _e1, int _x, int _e2) {
        middle = _x;
        left = middle - _e1;
        right = middle + _e2;
    }

    // Деструктор
    ~FuzzyNumbers() {
        cout << endl << "Деструктор сработал.\n";
    }

    // Вывод нечеткого числа
    void Print() {
        cout << endl << "Левый элемент: " << left << endl;
        cout << "Средний элемент: " << middle << endl;
        cout << "Правый элемент: " << right << endl;
    }

    // Функция для сложения двух нечетких чисел
    FuzzyNumbers Sum(FuzzyNumbers num) {
        cout << "Результат сложения двух нечетких чисел: ";
        int _left = middle + num.middle - left - num.left;
        int _middle = middle + num.middle;
        int _right = middle + num.middle + right + num.right;
        return FuzzyNumbers(_left, _middle, _right);
    }

    // Функция для вычитания двух нечетких чисел
    FuzzyNumbers Sub(FuzzyNumbers num) {
        cout << "Результат вычитания двух нечетких чисел: ";
        int _left = middle - num.middle - left - num.left;
        int _middle = middle - num.middle;
        int _right = middle - num.middle + right + num.right;
        return FuzzyNumbers(_left, _middle, _right);
    }

    // Функция для умножения двух нечетких чисел
    FuzzyNumbers Mul(FuzzyNumbers num) {
        cout << "Результат умножения двух нечетких чисел: ";
        int _left = middle * num.middle - num.middle * left - middle * num.left + left * num.right;
        int _middle = middle - num.middle;
        int _right = middle * num.middle + num.middle * left + middle * num.left + left * num.right;
        return FuzzyNumbers(_left, _middle, _right);
    }

    // Функция для взятия обратного числа
    FuzzyNumbers Reverse() {
        cout << "Результат взятия обратного нечеткого числа: ";
        int _left = -1;
        int _middle = -1;
        int _right = -1;
        if (middle > 0) {
            int _left = 1 / (middle + right);
            int _middle = 1 / middle;
            int _right = 1 / (middle - left);
        }
        return FuzzyNumbers(_left, _middle, _right);
    }

    // Функция для деления двух нечетких чисел
    FuzzyNumbers Div(FuzzyNumbers num) {
        cout << "Результат деления двух нечетких чисел: ";
        int _left = (middle - left) / (num.middle + num.right);
        int _middle = middle / num.middle;
        int _right = (middle + right) / (num.middle - num.left);
        return FuzzyNumbers(_left, _middle, _right);
    }
};

int main()
{

    FuzzyNumbers num1(1, 2, 3);
    FuzzyNumbers num2(3, 2, 1);
    
    num1.Print();

    num1 = num1.Sum(num2);
    num1.Print();
    
    num1 = num1.Sub(num2);
    num1.Print();
    
    num1 = num1.Div(num2);
    num1.Print();
    
    num1 = num1.Mul(num2);
    num1.Print();
    
    num1 = num1.Reverse();
    num1.Print();
}