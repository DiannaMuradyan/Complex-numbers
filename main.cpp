#include "complex.h"  

int main() {
    atlas3::Complex num1(3.0, 4.0);   
    atlas3::Complex num2(1.0, 2.0);   
    
    std::cout << "num1: " << num1;
    std::cout << "num2: " << num2;

    
    atlas3::Complex sum = num1 + num2;  
    atlas3::Complex difference = num1 - num2;  
    atlas3::Complex product = num1 * num2;  
    atlas3::Complex quotient = num1 / num2;  

   
    std::cout << "Sum: " << sum;
    std::cout << "Difference: " << difference;
    std::cout << "Product: " << product;
    std::cout << "Quotient: " << quotient;

    
    num1 += num2; 
    std::cout << "After num1 += num2: " << num1;

    num1 -= num2; 
    std::cout << "After num1 -= num2: " << num1;

    num1 *= num2;  
    std::cout << "After num1 *= num2: " << num1;

    num1 /= num2;  
    std::cout << "After num1 /= num2: " << num1;

    
    atlas3::Complex num3;
    std::cout << "Enter a complex number in the form a + bi or a - bi: ";
    std::cin >> num3;  //overloaded >> operator
    std::cout << "You entered: " << num3;

    return 0;
}
