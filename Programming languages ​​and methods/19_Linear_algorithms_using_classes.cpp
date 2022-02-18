/*
Class Pair with fields (float)first, (int)second.
Init method, field multiply method.
*/

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
    // Russian localization
    setlocale(LC_ALL, "RUSSIAN");
    // Create object
    Pair obj;
    // Add values for initialize obj fields
    float first_number;
    int second_number;
    std::cout << "Enter first and second numbers.\n";
    std::cin >> first_number >> second_number;
    obj.init(first_number, second_number);
    // Return result of multiplication
    std::cout << "Result of multiplication: " << obj.multiplication();
    // Finish the program
    return 0;
}
