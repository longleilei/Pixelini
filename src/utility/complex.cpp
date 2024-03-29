#include "utility/complex.h"
#include<cmath>



Complex::Complex(double r, double i) :real{ r }, imaginary{ i }{

}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}

double Complex::normalize() {
    return sqrt(real * real + imaginary * imaginary);
}

void Complex::nullify() {
    if(abs(real) < 0.00000001){
        real = 0; 
    }

    if(abs(imaginary) < 0.00000001){
        imaginary = 0; 
    }
}

Complex Complex::operator+(const Complex& num) {
    Complex temp{ real, imaginary}; 
    temp.real += num.real;
    temp.imaginary += num.imaginary;
    return temp;
}

Complex Complex::operator-(int num) {
    Complex temp{ real, imaginary}; 
    temp.real -= num;
    temp.imaginary -= num;
    return temp;
}

Complex Complex::operator-(const Complex& num) {
    Complex temp{ real, imaginary}; 
    temp.real -= num.real;
    temp.imaginary -= num.imaginary;
    return temp;
}

Complex Complex::operator*(const Complex& num) {

    // auto realTemp{ real };
    // real = real * num.real - imaginary * num.imaginary;
    // imaginary = realTemp * num.imaginary + imaginary * num.real;

    Complex temp{ real, imaginary}; 
    auto realTemp{ real };
    temp.real =  temp.real * num.real - temp.imaginary * num.imaginary;
    temp.imaginary = realTemp * num.imaginary + temp.imaginary * num.real;
    return temp;
}

Complex Complex::operator*(int num) {
    Complex temp{ real, imaginary}; 
    temp.real *= num;
    temp.imaginary *= num;
    return temp;
}

Complex Complex::operator*(double num) {
    Complex temp{ real, imaginary}; 
    temp.real *= num;
    temp.imaginary *= num;
    return temp;
}

Complex Complex::operator/(int num) {
    Complex temp{ real, imaginary}; 
    temp.real /= num;
    temp.imaginary /= num;
    return temp;
}

Complex Complex::operator/(const Complex& num) {
    Complex temp{ real, imaginary}; 
    auto realTemp{ real };
    temp.real = (real * num.real + imaginary * num.imaginary) / (num.real * num.real + num.imaginary * num.imaginary);
    temp.imaginary = (num.real * imaginary - realTemp * num.imaginary) / (num.real * num.real + num.imaginary * num.imaginary);
    return temp;
}

Complex Complex::operator^(int num) {
    Complex temp{ real, imaginary};
    auto abs{ pow(normalize(), num) };
    auto arg{ atan(imaginary / real) };
    temp.real = abs * cos(num * arg);
    temp.imaginary = abs * sin(num * arg);
    return temp;

}

Complex Complex::conjugate(const Complex& num){
    return { num.real, num.imaginary * (-1)}; 
}

std::ostream& operator<<(std::ostream& os, const Complex& out)
{
    if (out.getReal() < 0.00000001 && out.getReal() > -0.00000001) {
        if (abs(out.getImaginary()) == 1) {
            if (out.getImaginary() < 0) {
                os << "-i";
                return os;
            }
            os << 'i';
            return os;
        }
        os <<  out.imaginary << 'i';
        return os;
    }
    if (out.getImaginary() < 0.000000001 && out.getImaginary() > -0.000000001) {
        os << out.getReal();
        return os;
    }
    if (out.getImaginary() > 0) {

        os << out.real << "+" << out.imaginary << 'i';
    }
    else {
        os << out.real << "-" << out.imaginary*-1 << 'i';
    }
    return os;
}
