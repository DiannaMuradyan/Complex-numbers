#include "complex.h"

//Operator <<
std::ostream& atlas3::operator<<(std::ostream& os,const atlas3::Complex& num) {
    if(num.getImag() > 0){
        os << num.getReal() << " + " << num.getImag() << "i\n" ;
    } 
    else{
        os << num.getReal() << " - " << (-1)*num.getImag() << "i\n" ;
    }
    return os;
}

//Operator>>
std::istream& atlas3::operator>>(std::istream& is , atlas3::Complex& num) {
    std::string str;
    std::cin>>str;
    std::string tmp(str);

    int index = find_the_sign(str);
    
    tmp.resize(index);
    num.setReal(std::stod(tmp));

    tmp = str;

    tmp.assign(&str[0] + index);
    tmp.resize(tmp.size() - 1);
    num.setImag(std::stod(tmp));                                               
    return is;
}

//Constructors and destructor

atlas3::Complex::Complex() : m_real{0} , m_imag{0} {};

atlas3::Complex::Complex(double real , double imag) {  
    m_real = real;
    m_imag = imag;
}

atlas3::Complex::Complex(const atlas3::Complex& other) {
    m_real = other.m_real;
    m_imag = other.m_imag;
}


atlas3::Complex::Complex(atlas3::Complex&& other) {
    m_real = other.m_real;
    m_imag = other.m_imag;
    other.m_real = 0;
    other.m_imag = 0;
}

atlas3::Complex::~Complex() {
    m_real = 0;
    m_imag = 0;
}


//Operator assignment
atlas3::Complex& atlas3::Complex::operator=(const atlas3::Complex& other) {
    if(*this == other){
        return *this;
    }
    m_real = other.m_real;
    m_imag = other.m_imag;
    return *this;
}

atlas3::Complex& atlas3::Complex::operator=(const atlas3::Complex&& other) {
    if(*this == other){
        return *this;
    }
    m_real = other.m_real;
    m_imag = other.m_imag;
    return *this;
}


double atlas3::Complex::getReal() const {
    return m_real;
}

void atlas3::Complex::setReal(double r) {
    m_real = r;
}

double atlas3::Complex::getImag() const {
    return m_imag;
}

void atlas3::Complex::setImag(double r) {
    m_imag = r;
}

//Arithmetic Operator
atlas3::Complex atlas3::Complex::operator+(const atlas3::Complex& other) {
    Complex num;
    num.m_real = m_real + other.m_real;
    num.m_imag = m_imag + other.m_imag;
    return num;
}

atlas3::Complex atlas3::Complex::operator-(const atlas3::Complex& other) {
    Complex num;
    num.m_real = m_real - other.m_real;
    num.m_imag = m_imag - other.m_imag;
    return num;
}

atlas3::Complex atlas3::Complex::operator*(const atlas3::Complex& other) {
    Complex num;
    num.m_real = m_real * other.m_real - m_imag * other.m_imag;
    num.m_imag = m_real * other.m_imag + m_imag * other.m_real;
    return num;
}

atlas3::Complex atlas3::Complex::operator/(const atlas3::Complex& other) {
    Complex num;
    Complex anouncer = *this * (other.conjugate());
    int numerator = other.m_real * other.m_real - other.m_imag * other.m_imag;
    num.m_real = anouncer.m_real/numerator;
    num.m_imag = anouncer.m_imag/numerator;
    return num;
}


//Compound Assignment Operators
atlas3::Complex& atlas3::Complex::operator+=(const atlas3::Complex& other) {
    m_real = m_real + other.m_real;
    m_imag = m_imag + other.m_imag;
    return *this;
} 


atlas3::Complex& atlas3::Complex::operator-=(const atlas3::Complex& other) {
    m_real = m_real - other.m_real;
    m_imag = m_imag - other.m_imag;
    return *this;
} 

atlas3::Complex& atlas3::Complex::operator*=(const atlas3::Complex& other) {
    m_real = m_real * other.m_real - m_imag * other.m_imag;
    m_imag = m_real * other.m_imag + m_imag * other.m_real;
    return *this;
} 

atlas3::Complex& atlas3::Complex::operator/=(const atlas3::Complex& other) {
    Complex anouncer = *this * (other.conjugate());
    int numerator = other.m_real * other.m_real - other.m_imag * other.m_imag;
    m_real = anouncer.m_real/numerator;
    m_imag = anouncer.m_imag/numerator;
    return *this;
} 


atlas3::Complex::operator double() const noexcept {
    return this -> magnitude() ;
}



//Equality Operators
bool atlas3::Complex::operator==(const atlas3::Complex& other) {
    if(m_real == other.m_real && m_imag == other.m_imag){
        return true;
    }
    return false;
}

bool atlas3::Complex::operator!=(const atlas3::Complex& other) {
    return !operator==(other);
}


//Member Functions
atlas3::Complex atlas3::Complex::conjugate() const {
    Complex num;
    num.m_real = m_real;
    num.m_imag = (-1)*m_imag;
    return num;
}


double atlas3::Complex::magnitude() const {
    return sqrt(m_real * m_real + m_imag * m_imag) ;
}


double atlas3::Complex::phase() const {
    return atan2(m_imag, m_real) ;
}

int atlas3::find_the_sign(std::string& str) {
    int index = 0;
    if ((index = str.find('+')) > -1) {
        return index;
    }
    else if ((index = str.find('-')) > -1) {
        return index;
    }
    else {
        throw std::abort;
    }
}