#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <vector>


namespace atlas3 {

class Complex {
public:    
    //Constructors and destructor
    Complex() ;
    Complex(double real,double imag) ;
    Complex(const Complex& other) ;
    Complex(Complex&& other) ;
    ~Complex() ;

    //Operator assignment
    Complex& operator=(const Complex& other) ;
    Complex& operator=(const Complex&& other) ;


    //Geter-setsers
    double getReal() const ;
    void setReal(double r) ;
    double getImag() const ;
    void setImag(double i) ;


    //Arithmetic Operator
    Complex operator+(const Complex& other) ;
    Complex operator-(const Complex& other) ;
    Complex operator*(const Complex& other) ;
    Complex operator/(const Complex& other) ;


    //Compound Assignment Operators
    Complex& operator+=(const Complex& other) ;
    Complex& operator-=(const Complex& other) ;
    Complex& operator*=(const Complex& other) ;
    Complex& operator/=(const Complex& other) ;
    explicit operator double() const noexcept ;


    //Equality Operators
    bool operator==(const Complex& other) ;
    bool operator!=(const Complex& other) ;


private:
    double m_real;
    double m_imag;

private:
   //Member Functions
    Complex conjugate() const ;
    double magnitude() const;
    double phase() const;

};
   
int find_the_sign(std::string& str);
std::ostream& operator<<(std::ostream& os , const Complex& num) ;
std::istream& operator>>(std::istream& is , Complex& num) ;

}

#endif // VECTOR_H
