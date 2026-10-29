#include <iostream>
#include <vector>
#include <clocale>
#include "file.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, ".UTF-8");
    vector<Figure*> figures;
    int choice;
    do
    {
        cout << "\n==МЕНЮ==" << endl;
        cout << "1. Создать круг" << endl;
        cout << "2. Создать прямоугольник" << endl;
        cout << "3. Создать треугольник" << endl;
        cout << "0. Завершить создание фигур" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        if (choice == 1)
        {
            double r;
            cout << "Введите радиус круга: ";
            cin >> r;
            if (r <= 0)
            {
                cout << "Ошибка: радиус > 0." << endl;
                continue;
            }

            figures.push_back(new Circle(r));
        }
        else if (choice == 2)
        {
            double w, h;

            cout << "Введите ширину прямоугольника: ";
            cin >> w;
            cout << "Введите высоту прямоугольника: ";
            cin >> h;

            if (w <= 0 || h <= 0)
            {
                cout << "Ошибка: размеры > 0 ." << endl;
                continue;
            }

            figures.push_back(new Rectangle(w, h));
        }
        else if (choice == 3)
        {
            double a, b, c;
            cout << "Введите три стороны треугольника: ";
            cin >> a >> b >> c;
            if (a <= 0 || b <= 0 || c <= 0 ||
                a + b <= c || a + c <= b || b + c <= a)
            {
                cout << "Ошибка: стороны не образуют треугольник." << endl;
                continue;
            }
            figures.push_back(new Triangle(a, b, c));
        }
        else if (choice != 0)
        {
            cout << "Неверный пункт меню." << endl;
        }

    } while (choice != 0);
    cout << "\n===== СОЗДАННЫЕ ФИГУРЫ =====" << endl;
    for (int i = 0; i < figures.size(); i++)
    {
        cout << "\nФигура" << i + 1 << endl;
        Figure* figure = figures[i];
        figure->PrintInfo();
        cout << "[Отладка] Вызов CalcArea через Figure*" << endl;
        cout << "Результат: " << figure->CalcArea() << endl;
    }
    cout << "\n==ОСВОБОЖДЕНИЕ ПАМЯТИ==" << endl;

    for (int i = 0; i < figures.size(); i++)
    {
        delete figures[i];
    }
    figures.clear();
    cout << "Все объекты удалены." << endl;
    return 0;
}