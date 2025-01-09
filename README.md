# Complex-numbers
Complex Number Operations Project
Overview
This project implements a class Complex for representing and manipulating complex numbers in C++. The Complex class supports various operations such as arithmetic operations, input/output stream handling, comparison, and advanced mathematical functions (e.g., magnitude, phase, and conjugate).

The project also includes operator overloading for common arithmetic and assignment operations, as well as custom input/output stream operators for reading and printing complex numbers.

Features
Complex Number Representation: The class represents complex numbers in the form a + bi where a is the real part and b is the imaginary part.
Arithmetic Operations: You can perform addition, subtraction, multiplication, and division between complex numbers.
Compound Assignment Operators: The class supports the compound assignment operators (+=, -=, *=, /=) for modifying complex numbers.
Equality Operators: Supports equality (==) and inequality (!=) comparison between complex numbers.
Stream Operators: Custom << and >> operators for reading and printing complex numbers from/to standard input/output streams.
Member Functions: Includes functions for calculating the magnitude, phase, and conjugate of a complex number.
Conversion Operator: The complex number can be implicitly converted to a double representing its magnitude.
Files in the Project
complex.h: Header file containing the declaration of the Complex class and associated functions.
complex.cpp: Implementation of the Complex class and its methods.
main.cpp: Contains a sample main() function that demonstrates how to use the Complex class and its operators.

Class: Complex
The Complex class has the following key members:

Constructors:
Default Constructor: Initializes the complex number to 0 + 0i.
Complex();

Parameterized Constructor: Initializes the complex number with given real and imaginary parts.
Complex(double real, double imag);

Copy Constructor: Initializes the complex number as a copy of another.
Complex(const Complex& other);

Move Constructor: Transfers ownership of resources from another Complex object.
Complex(Complex&& other);

Destructor: Clears the real and imaginary parts.
~Complex();

Member Functions:
getReal(): Returns the real part of the complex number.
double getReal() const;

setReal(): Sets the real part of the complex number.
void setReal(double r);

getImag(): Returns the imaginary part of the complex number.
double getImag() const;

setImag(): Sets the imaginary part of the complex number.
void setImag(double r);

Arithmetic Operators:

Addition: Adds two complex numbers.
Complex operator+(const Complex& other);

Subtraction: Subtracts two complex numbers.
Complex operator-(const Complex& other);

Multiplication: Multiplies two complex numbers.
Complex operator*(const Complex& other);

Division: Divides one complex number by another.
Complex operator/(const Complex& other);

Compound Assignment Operators:

Addition Assignment: Adds and assigns the result to the current object.
Complex& operator+=(const Complex& other);

Subtraction Assignment: Subtracts and assigns the result to the current object.
Complex& operator-=(const Complex& other);

Multiplication Assignment: Multiplies and assigns the result to the current object.
Complex& operator*=(const Complex& other);

Division Assignment: Divides and assigns the result to the current object.
Complex& operator/=(const Complex& other);

Comparison Operators:

Equality: Checks if two complex numbers are equal.
bool operator==(const Complex& other);

Inequality: Checks if two complex numbers are not equal.
bool operator!=(const Complex& other);

Other Functions:

Conjugate: Returns the complex conjugate (reverses the sign of the imaginary part).
Complex conjugate() const;

Magnitude: Returns the magnitude (absolute value) of the complex number.
double magnitude() const;

Phase: Returns the phase (angle) of the complex number in radians.
double phase() const;

Conversion:

Conversion to Double: Implicit conversion to a double representing the magnitude of the complex number.
operator double() const noexcept;

Stream Operators:

Input Stream Operator (>>): Reads a complex number from standard input in the format a + bi or a - bi.
std::istream& operator>>(std::istream& is, Complex& num);

Output Stream Operator (<<): Prints a complex number in the format a + bi or a - bi.
std::ostream& operator<<(std::ostream& os, const Complex& num);

This project provides a solid implementation of the Complex class with essential operations and mathematical functions. It allows for flexible and efficient manipulation of complex numbers, useful in many applications such as electrical engineering, signal processing, and more.
