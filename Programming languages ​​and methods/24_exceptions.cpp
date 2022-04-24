#include <iostream>
#include <math.h>
using namespace std;

void function(float a, float b, float c){
    int d = sqrt(b*b - 4*a*c);

    if(d > 0){
        cout << "Первый корень: " << (-b + d)/(2*a)<< endl;
        cout << "Второй корень: " << (-b - d)/(2*a)<< endl;
    }
    else if(d == 0){
        cout << "Единственный корень: " << (-b)/(2*a)<< endl;
    }
    else {
        cout << "Действительных корней уравнения нет." << endl;
    }
}
int main()
{
    int a,b,c;
    cout << "Введите коэфициенты квадратного уравнения в порядке a ==> b ==> c." << endl;
    cin >> a >> b >> c;
    
    try {
        if(a == 0 && b == 0){
            throw 1;
        }
        function(a,b,c);
    } catch (int i){
        if(i == 1){
            if (c == 0){
                cout << "Все переменные равны нулю" << endl;
            } else {
                cout << "Нет решений" << endl;
            }
        } 
    }
    return 0;
}
