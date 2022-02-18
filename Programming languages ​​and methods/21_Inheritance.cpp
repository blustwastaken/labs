#include <iostream>
class Triad {
public:
    int a, b, c;
    Triad() {}
    Triad(int first, int second, int third) {
        a = first;
        b = second;
        c = third;
    }
    ~Triad() {
        std::cout << "Деструктор сработал." << std::endl;
    }
    void get() {
        std::cout << "Координаты вектора: " << a << " " << b << " " << c << std::endl;
    }
    void init(int first, int second, int third) {
        a = first;
        b = second;
        c = third;
    }
    void sum(int number) {
        a += number;
        b += number;
        c += number;
    }
    void dif(int number) {
        a -= number;
        b -= number;
        c -= number;
    }
    bool equals(int first, int second, int third) {
        if ((a == first) and (b == second) and (c = third)) {
            return true;
        }
        return false;
    }
};

class vector3d : public Triad {
public:
    void sum_of_vectors(int a1, int b1, int c1) {
        std::cout << "Координаты получившегося вектора: " << a1 + a << " " << b1 + b << " " << c1 + c << std::endl;
    }
    void multy(int a1, int b1, int c1) {
        std::cout << "Скалярное произведение векторов: " << a1 * a + b1 * b + c1 * c << std::endl;
    }
};
int main()
{
    Triad triad;
    vector3d vect;
    std::cout << "Введите тройку чисел для объекта класса Triad" << std::endl;
    int a, b, c;
    std::cin >> a >> b >> c;
    triad.init(a, b, c);
    triad.get();
    std::cout << "Введите число, на которое нужно увеличить объект Triad" << std::endl;
    int number1;
    std::cin >> number1;
    triad.sum(number1);
    triad.get();
    std::cout << "Введите число, на которое нужно уменьшить объект Triad" << std::endl;
    int number2;
    std::cin >> number2;
    triad.dif(number2);
    triad.get();
    std::cout << "Введите вектор, который нужно сравнить с объектов Triad" << std::endl;
    int a1, b1, c1;
    std::cin >> a1 >> b1 >> c1;
    std::cout << triad.equals(a1, b1, c1) << std::endl;
    std::cout << "Введите тройку чисел для объекта класса vector3d" << std::endl;
    int v1, v2, v3;
    std::cin >> v1 >> v2 >> v3;
    vect.init(v1, v2, v3);
    std::cout << "Введите вектор для сложения векторов" << std::endl;
    int a2, b2, c2;
    std::cin >> a2 >> b2 >> c2;
    vect.sum_of_vectors(a2, b2, c2);
    std::cout << "Введите вектор для скалярного произведения векторов" << std::endl;
    int a3, b3, c3;
    std::cin >> a3 >> b3 >> c3;
    vect.multy(a3, b3, c3);
    return 0;
}