#include <iostream>

double Average_R(int array[], int length){
    // Если длина массива 1 - возвращаем начальный элемент
    if (length == 1)
        return array[length - 1];
    // Умножим результат функции с массивом меньшей длинны на саму меньшую длинну,
    // после чего сложим с последним значением в исходном массиве. Результат поделим на общую длинну массива
    return ((length-1) * Average_R(array, length - 1) + array[length - 1])/length;
}

double Average_I(int array[], int length){
    double average = 0;
    for (int i = 0; i < length; i++)
        average += array[i];
    average /= length;
    return average;
}

int main(){
int array[] = {1, 2, 3, 4, 5};

std::cout << "Среднее арифметическое массива, найденое итеративным алгоритмом:"<<std::endl;
std::cout << Average_I(array, 5);

std::cout << std::endl << "Среднее арифметическое массива, найденное рекурсивным алгоритмом:"<<std::endl;
std::cout << Average_R(array, 5);
}
