#include <iostream>

class Pair {
private:
    float first;
    int second;
public:
    void init(float first_number, int second_number) {
        first = first_number;
        second = second_number;
    }
    float multiplication() {
        return first * second;
    }
};

int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    Pair obj;
    float first_number;
    int second_number;

    std::cout << "Enter first and second numbers.\n";
    std::cin >> first_number >> second_number;
    obj.init(first_number, second_number);

    std::cout << "Result of multiplication: " << obj.multiplication();
    return 0;
}
