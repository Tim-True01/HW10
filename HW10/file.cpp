#include "file.h"
#include <iostream>
#include <cmath>
using namespace std;
Figure::Figure()
{
    cout << "[Отладка] Вызван конструктор Figure" << endl;
}
Figure::~Figure()
{
    cout << "[Отладка] Вызван деструктор Figure" << endl;
}

Circle::Circle(double r)
{
    radius = new double(r);
    cout << "[Отладка] Вызван конструктор Circle" << endl;
}

Circle::~Circle()
{
    cout << "[Отладка] Вызван деструктор Circle" << endl;
    delete radius;
}

double Circle::CalcArea()
{
    cout << "[Отладка] Вызван Circle::CalcArea()" << endl;
    const double pi = acos(-1.0);
    return pi * (*radius) * (*radius);
}

void Circle::PrintInfo()
{
    cout << "[Отладка] Вызван Circle::PrintInfo()" << endl;
    cout << "Фигура: круг" << endl;
    cout << "Радиус: " << *radius << endl;
    cout << "Площадь: " << CalcArea() << endl;
}

Rectangle::Rectangle(double w, double h)
{
    width = new double(w);
    height = new double(h);
    cout << "[Отладка] Вызван конструктор Rectangle" << endl;
}

Rectangle::~Rectangle()
{
    cout << "[Отладка] Вызван деструктор Rectangle" << endl;
    delete width;
    delete height;
}

double Rectangle::CalcArea()
{
    cout << "[Отладка] Вызван Rectangle::CalcArea()" << endl;
    return ((*width)) * (*height);
}

void Rectangle::PrintInfo()
{
    cout << "[Отладка] Вызван Rectangle::PrintInfo()" << endl;
    cout << "Фигура: прямоугольник" << endl;
    cout << "Ширина: " << (*width) << endl;
    cout << "Высота: " << *height << endl;
    cout << "Площадь: " << CalcArea() << endl;
}

Triangle::Triangle(double a, double b, double c)
{
    sideA = new double(a);
    sideB = new double(b);
    sideC = new double(c);
    cout << "[Отладка] Вызван конструктор Triangle" << endl;
}
Triangle::~Triangle()
{
    cout << "[Отладка] Вызван деструктор Triangle" << endl;
    delete sideA;
    delete sideB;
    delete sideC;
}
double Triangle::CalcArea()
{
    cout << "[Отладка] Вызван Triangle" << endl;

    double a = *sideA;
    double b = *sideB;
    double c = *sideC;
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "Ошибка: такой треугольник не существует." << endl;
        return 0;
    }

    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
void Triangle::PrintInfo()
{
    cout << "[Отладка] Вызван Triangle::PrintInfo()" << endl;
    cout << "Фигура: треугольник" << endl;
    cout << "Сторона A: " << *sideA << endl;
    cout << "Сторона B: " << *sideB << endl;
    cout << "Сторона C: " << *sideC << endl;
    cout << "Площадь: " << CalcArea() << endl;
}