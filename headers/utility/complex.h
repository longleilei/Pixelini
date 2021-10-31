#pragma once
#include <iostream> 
class Complex {

    double real;
    double imaginary;

public:

    Complex() = default;

    Complex(double _real, double _imaginary);
    double getReal() const;
    double getImaginary() const;
    double normalize();
    void nullify(); 

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator-(int num);
    Complex operator*(const Complex&);
    Complex operator*(int);
    Complex operator*(double num); 
    Complex operator/(int num);
    Complex operator/(const Complex&);
    Complex operator^(int num);
    
    static Complex conjugate(const Complex&); 


    friend std::ostream& operator<<(std::ostream& os, const Complex& out);


};

