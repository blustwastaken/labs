// Подключим заголовочный файл для функций ввода-вывода
#include <iostream>
// подключим стандартное пространство имён
using namespace std;

// объявим функцию для вывода матриц
template <class T>
void PrintMatrix(T matrix[[]], int rows, int columns){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++){
            cout << "|" << matrix[i][j] << "|\t";
        }
        cout << endl;
    }
    cout << endl;
}

// объявим функцию для отражения элементов в матрицах относительно главной диагонали
template <class T>
void ReverseMatrix(T matrix[[]], int rows, int columns){
    for(int i = 1; i<rows-1; i++){
        for(int j = 0; j<columns - i - 1; j++){
            // посколько T данные - это именно матрицы, а не элементы, мы не можем использовать 'T temp'
            // замену переменной проведём с помощью арифметики
            matrix[i][j] += matrix[i][columns - j - 1];
            matrix[i][columns - j - 1] = matrix[i][j] - matrix[i][columns - j - 1];
            matrix[i][j] -= matrix[i][columns - j - 1];
        }
    }
}

// объявим функцию для вывода строк, элементы в которых идут по возрастанию.
template <class T>
void PrintIncSubs(T matrix[[]], int rows, int columns){
    for(int i = 0; i<rows; i++){
        // объявим флаг
        bool flag = true;
        for(int j = 1; j<columns; j++){
            if(matrix[i][j]<matrix[i][j-1]){
                // если хотя бы один элемент идет не по порядку - меняем флаг и ломаем цикл
                flag = false;
                break;
            }
        }
        // если все элементы идут по порядку
        if(flag)
            cout << i << " - возрастающая строка." << endl;
    }
    cout << endl;
}

// ф-ия main - точка входа программы
int main(){
    // Объявим матрицы в соответствии с заданием.
    float floatMatrix[2][2]{
        {4.5, 7.8},
        {1.0, 3.5}
    };

    int intMatrix[3][3]{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double doubleMatrix[4][4]{
        {4.9, 5.1, 1.0, 2.1},
        {1.9, 0.0, 5.7, 1.2},
        {3.5, 3.1, 9.9, 12.0},
        {1.0, 1.1, 1.2, 1.3}
    };

    // Выведем матрицы до изменений.
    cout << "Изначальная матрица float-данных" << endl;
    PrintMatrix(floatMatrix, 2, 2);
    cout << endl << "Изначальная матрица int-данных" << endl;
    PrintMatrix(intMatrix, 3, 3);
    cout << endl << "Изначальная матрица double-данных" << endl;
    PrintMatrix(doubleMatrix, 4, 4);

    // Отразим элементы в матрицах относительно главной диагонали, после чего выведем измененные матрицы.
    cout << "Измененная матрица float-данных" << endl;
    ReverseMatrix(floatMatrix, 2, 2);
    PrintMatrix(floatMatrix, 2, 2);
    cout << endl << "Измененная матрица int-данных" << endl;
    ReverseMatrix(intMatrix, 3, 3);
    PrintMatrix(intMatrix, 3, 3);
    cout << endl << "Измененная матрица double-данных" << endl;
    ReverseMatrix(doubleMatrix, 4, 4);
    PrintMatrix(doubleMatrix, 4, 4);

    // Выведем индексы строк, которые находятся по возрастанию.
    cout << "Строки по возрастанию в float-матрице" << endl;
    PrintIncSubs(floatMatrix, 2, 2);
    cout << endl << "Строки по возрастанию в int-матрице" << endl;
    PrintIncSubs(intMatrix, 3, 3);
    cout << endl << "Строки по возрастанию в double-матрице" << endl;
    PrintIncSubs(doubleMatrix, 4, 4);

    // Завершим программу.
    return 0;
}