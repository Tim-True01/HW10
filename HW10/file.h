#pragma once
class Figure
{
public:
    Figure();
    virtual ~Figure();

    virtual double CalcArea() = 0;
    virtual void PrintInfo() = 0;
};

class Circle : public Figure
{
private:
    double* radius;
public:
    Circle(double r);
    ~Circle() override;

    double CalcArea() override;
    void PrintInfo() override;
};

class Rectangle : public Figure
{
private:
    double* width;
    double* height;
public:
    Rectangle(double w, double h);
    ~Rectangle() override;

    double CalcArea() override;
    void PrintInfo() override;
};

class Triangle : public Figure
{
private:
    double* sideA;
    double* sideB;
    double* sideC;
public:
    Triangle(double a, double b, double c);
    ~Triangle() override;

    double CalcArea() override;
    void PrintInfo() override;
};
