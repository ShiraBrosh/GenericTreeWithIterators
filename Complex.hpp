#pragma once
#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double get_real() const {// Get the real part of the complex number
        return real;
    }

    double get_imag() const {// Get the imaginary part of the complex number
        return imag;
    }

    void set_real(double r) {// Set the real part of the complex number
        real = r;
    }

    void set_imag(double i) { // Set the imaginary part of the complex number
        imag = i;
    }

    double magnitude() const {// Get the magnitude of the complex number
        return std::sqrt(real * real + imag * imag);
    }

    bool operator<(const Complex& other) const {// Compare the magnitude of two complex numbers
        return magnitude() < other.magnitude();
    }

    bool operator==(const Complex& other) const {// Check if two complex numbers are equal
        return real == other.real && imag == other.imag;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {// Output the complex number
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};